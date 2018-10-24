#ifndef ACE_TIME_OFFSET_DATE_TIME_H
#define ACE_TIME_OFFSET_DATE_TIME_H

#include <stdint.h>
#include "common/Flash.h"
#include "common/Util.h"
#include "ZoneOffset.h"

class Print;

namespace ace_time {

/**
 * The date (year, month, day) and time (hour, minute, second) fields
 * representing the time with an offset from UTC.
 *
 * The year field is internally represented as a 2 digit number from [2000,
 * 2099]. Therefore, the "epoch" for this library is 2000-01-01 00:00:00Z.
 * These fields map directly to the fields supported by the DS3231 RTC chip.
 *
 * The dayOfWeek (1=Sunday, 7=Saturday) is calculated internally from the date.
 * The value is calculated lazily and cached internally. If any components are
 * changed, then the cache is invalidated and the dayOfWeek is lazily
 * recalculated.
 *
 * The incrementXxx() methods are convenience methods to allow the user to
 * change the date and time using just two buttons. The user is expected to
 * select a specific OffsetDateTime component using one of the buttons, then
 * press the other button to increment it.
 *
 * Parts of this class were inspired by the java.time.OffsetDateTime class of
 * Java 8
 * (https://docs.oracle.com/javase/8/docs/api/java/time/OffsetDateTime.html).
 */
class OffsetDateTime {
  public:
    /**
     * Number of seconds from Unix epoch (1970-01-01 00:00:00Z) to
     * the AceTime epoch (2000-01-01 00:00:00Z).
     */
    static const uint32_t kSecondsSinceUnixEpoch = 946684800;

    /**
     * Number of days between the Julian calendar epoch (4713 BC 01-01) and the
     * AceTime epoch (2000-01-01).
     */
    static const uint32_t kDaysSinceJulianEpoch = 2451545;

    /** Base year of epoch. */
    static const uint16_t kEpochYear = 2000;

    /**
     * Constructor. All internal fields are left in an undefined state.
     */
    explicit OffsetDateTime() {}

    /**
     * Constructor using separated date, time, and time zone fields. The
     * dayOfWeek will be internally generated.
     *
     * @param year last 2 digits of the year from year 2000
     * @param month month with January=1, December=12
     * @param day day of month (1-31)
     * @param hour hour (0-23)
     * @param minute minute (0-59)
     * @param second second (0-59), does not support leap seconds
     * @param zoneOffset Optional, default is UTC time zone. The time zone
     * offset in 15-minute increments from UTC. Using a ZoneOffset object here
     * in the last component allows us to add an additional constructor that
     * accepts a millisecond component in the future.
     */
    explicit OffsetDateTime(uint8_t year, uint8_t month, uint8_t day,
            uint8_t hour, uint8_t minute, uint8_t second,
            ZoneOffset zoneOffset = ZoneOffset()):
        mYear(year),
        mMonth(month),
        mDay(day),
        mHour(hour),
        mMinute(minute),
        mSecond(second),
        mZoneOffset(zoneOffset),
        mDayOfWeek(0) {
    }

    /**
     * Constructor. Create the various components of the OffsetDateTime from
     * the secondsSinceEpoch and its ZoneOffset. The dayOfWeek will be
     * calculated lazily.
     *
     * If ZoneOffset.offsetCode() is negative, then (secondsSinceEpoch >=
     * ZoneOffset::asSeconds() must be true. Otherwise, the local time will be
     * in the year 1999, which cannot be represented by a 2-digit year
     * beginning with the year 2000.
     *
     * @param secondsSinceEpoch Number of seconds from AceTime epoch
     *    (2000-01-01 00:00:00Z). A 0 value is a sentinel that is considerd to
     *    be an error, and causes isError() to return true.
     * @param zoneOffset Optional, default UTC time zone.
     *
     * See https://en.wikipedia.org/wiki/Julian_day.
     */
    explicit OffsetDateTime(uint32_t secondsSinceEpoch,
          ZoneOffset zoneOffset = ZoneOffset()) {
      if (secondsSinceEpoch == 0) {
        setError();
        return;
      }

      mZoneOffset = zoneOffset;

      secondsSinceEpoch += zoneOffset.asSeconds();
      uint32_t daysSinceEpoch = secondsSinceEpoch / 86400;
      fillUsingDaysSinceEpoch(daysSinceEpoch);

      uint32_t seconds = secondsSinceEpoch % 86400;
      mSecond = seconds % 60;
      seconds /= 60;
      mMinute = seconds % 60;
      seconds /= 60;
      mHour = seconds;
    }

    /**
     * Factory method. Create a OffsetDateTime from the ISO8601 date string. If
     * the string cannot be parsed, then isError() on the constructed object
     * returns true.
     *
     * The dateString is expected to be in ISO8601 format
     * "YYYY-MM-DDThh:mm:ss+hh:mm", but currently, the parser is very lenient
     * and does not detect most errors. It cares mostly about the positional
     * placement of the various components. It does not validate the separation
     * characters like '-' or ':'. For example, both of the following will parse
     * to the exactly same OffsetDateTime object:
     * "2018-08-31T13:48:01-07:00"
     * "2018/08/31 13#48#01-07#00"
     */
    static OffsetDateTime forDateString(const char* dateString) {
      return OffsetDateTime().initFromDateString(dateString);
    }

    /**
     * Factory method. Create a OffsetDateTime from date string in flash memory
     * F() strings. Mostly for unit testing.
     */
    static OffsetDateTime forDateString(const __FlashStringHelper* dateString) {
      // Copy the F() string into a buffer. Use strncpy_P() because ESP32 and
      // ESP8266 do not have strlcpy_P().
      char buffer[kDateStringLength + 2];
      strncpy_P(buffer, (const char*) dateString, sizeof(buffer));
      buffer[kDateStringLength + 1] = 0;

      // check if the original F() was too long
      size_t len = strlen(buffer);
      if (len > kDateStringLength) {
        return OffsetDateTime().setError();
      }

      return forDateString(buffer);
    }

    /** Return true if any component indicates an error condition. */
    bool isError() const {
      // Warning: Don't change the order of the following boolean conditionals
      // without changing setError().
      return mSecond >= 60
          || mMinute >= 60
          || mHour >= 24
          || mDay < 1 || mDay > 31
          || mMonth < 1 || mMonth > 12;
    }

    /** Return the 2 digit year from year 2000. */
    uint8_t year() const { return mYear; }

    /** Set the 2 digit year from year 2000. */
    void year(uint8_t year) {
      mYear = year;
      mDayOfWeek = 0;
    }

    /** Return the full year instead of just the last 2 digits. */
    uint16_t yearFull() const { return mYear + kEpochYear; }

    /** Set the year given the full year. */
    void yearFull(uint16_t yearFull) {
      mYear = yearFull - kEpochYear;
      mDayOfWeek = 0;
    }

    /** Return the month with January=1, December=12. */
    uint8_t month() const { return mMonth; }

    /** Set the month. */
    void month(uint8_t month) {
      mMonth = month;
      mDayOfWeek = 0;
    }

    /** Return the day of the month. */
    uint8_t day() const { return mDay; }

    /** Set the day of the month. */
    void day(uint8_t day) {
      mDay = day;
      mDayOfWeek = 0;
    }

    /** Return the hour. */
    uint8_t hour() const { return mHour; }

    /** Set the hour. */
    void hour(uint8_t hour) {
      // Does not affect dayOfWeek.
      mHour = hour;
    }

    /** Return the minute. */
    uint8_t minute() const { return mMinute; }

    /** Set the minute. */
    void minute(uint8_t month) {
      // Does not affect dayOfWeek.
      mMinute = month;
    }

    /** Return the second. */
    uint8_t second() const { return mSecond; }

    /** Set the second. */
    void second(uint8_t second) {
      // Does not affect dayOfWeek.
      mSecond = second;
    }

    /**
     * Return the day of the week, Sunday=1, Saturday=7.
     * The dayOfWeek is calculated lazily and cached internally. Not
     * thread-safe.
     */
    uint8_t dayOfWeek() const {
      if (mDayOfWeek == 0) {
        mDayOfWeek = calculateDayOfWeek();
      }
      return mDayOfWeek;
    }

    /** Return the offset zone of the OffsetDateTime. */
    const ZoneOffset& zoneOffset() const { return mZoneOffset; }

    /** Return the offset zone of the OffsetDateTime. */
    ZoneOffset& zoneOffset() { return mZoneOffset; }

    /** Set the offset zone. */
    void zoneOffset(const ZoneOffset& zoneOffset) {
      // Does not affect dayOfWeek.
      mZoneOffset = zoneOffset;
    }

    /**
     * Create a OffsetDateTime in a different offset zone code (with the same
     * secondsSinceEpoch).
     */
    OffsetDateTime convertToZoneOffset(const ZoneOffset& zoneOffset) const {
      uint32_t secondsSinceEpoch = toSecondsSinceEpoch();
      return OffsetDateTime(secondsSinceEpoch, zoneOffset);
    }

    /**
     * Print OffsetDateTime to 'printer'. Does not implement Printable to avoid
     * memory cost of vtable pointer.
     */
    void printTo(Print& printer) const;

    /** Increment the year by one, wrapping from 99 to 0. */
    void incrementYear() {
      common::incrementMod(mYear, (uint8_t) 100);
      mDayOfWeek = 0;
    }

    /** Increment the year by one, wrapping from 12 to 1. */
    void incrementMonth() {
      common::incrementMod(mMonth, (uint8_t) 12, (uint8_t) 1);
      mDayOfWeek = 0;
    }

    /** Increment the day by one, wrapping from 31 to 1. */
    void incrementDay() {
      common::incrementMod(mDay, (uint8_t) 31, (uint8_t) 1);
      mDayOfWeek = 0;
    }

    /** Increment the hour by one, wrapping from 23 to 0. */
    void incrementHour() {
      common::incrementMod(mHour, (uint8_t) 24);
      mDayOfWeek = 0;
    }

    /** Increment the minute by one, wrapping from 59 to 0. */
    void incrementMinute() {
      common::incrementMod(mMinute, (uint8_t) 60);
      mDayOfWeek = 0;
    }

    /**
     * Return number of whole days since AceTime epoch (2000-01-01 00:00:00Z),
     * taking into account the offset zone.
     */
    uint32_t toDaysSinceEpoch() const {
      uint32_t daysSinceEpoch = toDaysSinceEpochIgnoringZoneOffset();
      int32_t utcOffset = ((mHour * 60) + mMinute) * (uint32_t) 60 + mSecond;
      utcOffset -= mZoneOffset.asSeconds();

      // Increment or decrement the day count depending on the offset zone.
      if (utcOffset >= 86400) {
        return daysSinceEpoch + 1;
      } else if (utcOffset < 0) {
        return daysSinceEpoch - 1;
      } else {
        return daysSinceEpoch;
      }
    }

    /**
     * Return seconds since AceTime epoch (2000-01-01 00:00:00Z), taking into
     * account the offset zone. The return type is an unsigned 32-bit integer,
     * which can represent a range of 136 years. Since the year is stored as a 2
     * digit offset from the year 2000, the return type will be valid for all
     * OffsetDateTime values which can be stored in this class.
     *
     * Normally, Julian day starts at 12:00:00. We modify the formula given in
     * wiki page to start the Gregorian day at 00:00:00.
     *
     * See https://en.wikipedia.org/wiki/Julian_day
     */
    uint32_t toSecondsSinceEpoch() const {
      uint32_t daysSinceEpoch = toDaysSinceEpochIgnoringZoneOffset();
      int32_t utcOffset = ((mHour * 60) + mMinute) * (uint32_t) 60 + mSecond;
      utcOffset -= mZoneOffset.asSeconds();
      return daysSinceEpoch * (uint32_t) 86400 + utcOffset;
    }

    /**
     * Return the number of seconds from Unix epoch 1970-01-01 00:00:00Z. The
     * return type is a uint32_t which can represent a range of 136 years. Since
     * the year is stored as a 2 digit year (from 2000), this method will return
     * a valid result for all dates which can be stored by this class.
     *
     * Tip: You can use the command 'date +%s -d {iso8601date}' on a Unix box to
     * print the unix seconds.
     */
    uint32_t toUnixSeconds() const {
      return toSecondsSinceEpoch() + kSecondsSinceUnixEpoch;
    }

    /**
     * Compare this OffsetDateTime with another OffsetDateTime, and return (<0,
     * 0, >0) according to whether the secondsSinceEpoch() is (a<b, a==b, a>b).
     * The dayOfWeek field is ignored but the offset zone is used.  This method
     * can return 0 (equal) even if the operator==() returns false if the two
     * OffsetDateTime objects are in different offset zones.
     */
    int8_t compareTo(const OffsetDateTime& that) const {
      uint32_t thisSeconds = toSecondsSinceEpoch();
      uint32_t thatSeconds = that.toSecondsSinceEpoch();
      if (thisSeconds < thatSeconds) {
        return -1;
      } else if (thisSeconds == thatSeconds) {
        return 0;
      } else {
        return 1;
      }
    }

    /**
     * Mark the OffsetDateTime so that isError() returns true. Returns a
     * reference to (*this) so that an invalid OffsetDateTime can be returned in
     * a single statement like this: 'return OffsetDateTime().setError()'.
     */
    OffsetDateTime& setError() {
      // We use the 'second' field to represent an error condition because it is
      // the first field checked by operator==(), so will provide the fastest
      // detection of the transition from isError() to a valid OffsetDateTime.
      // All other fields set to 0 to avoid compiler warnings about
      // uninitialized member variables.
      mYear = 0;
      mMonth = 0;
      mDay = 0;
      mHour = 0;
      mMinute = 0;
      mSecond = 255;
      mDayOfWeek = 0;
      return *this;
    }

  private:
    /** Expected length of an ISO8601 date string. */
    static const uint8_t kDateStringLength = 25;

    friend bool operator==(const OffsetDateTime& a, const OffsetDateTime& b);
    friend bool operator!=(const OffsetDateTime& a, const OffsetDateTime& b);

    /** Extract the date time components from the given dateString. */
    OffsetDateTime& initFromDateString(const char* dateString);

    /**
     * Calculate the correct day of week from the internal fields. If any of the
     * component fields (year, month, day, hour, minute, second) are manually
     * changed, this method must be called to update the dayOfWeek. The
     * dayOfWeek does not depend on the offset zone.
     */
    uint8_t calculateDayOfWeek() const {
      uint32_t daysSinceEpoch = toDaysSinceEpochIgnoringZoneOffset();
      // 2000-01-01 is a Saturday (7)
      return (daysSinceEpoch + 6) % 7 + 1;
    }

    /**
     * Return number of days since AceTime epoch (2000-01-01 00:00:00Z),
     * ignoring the offsetCode.
     *
     * Uses Julian days which normally start at 12:00:00. But this method
     * returns the delta number of days since 00:00:00, so we can interpret the
     * Gregorian calendar day to start at 00:00:00.
     *
     * See https://en.wikipedia.org/wiki/Julian_day
     */
    uint32_t toDaysSinceEpochIgnoringZoneOffset() const {
      // From wiki article:
      //
      // JDN = (1461 x (Y + 4800 + (M - 14)/12))/4
      //     + (367 x (M - 2 - 12 x ((M - 14)/12)))/12
      //     - (3 x ((Y + 4900 + (M - 14)/12)/100))/4
      //     + D - 32075
      // JDN2000 = JDN - 2451545
      //
      // It looks like the formula needs to be done using signed integers
      // because it depends on the modulo operation (%) to truncate towards 0
      // for negative numbers.

      int8_t mm = (mMonth - 14)/12;
      int16_t yy = mYear + kEpochYear;
      int32_t jdn = ((int32_t) 1461 * (yy + 4800 + mm))/4
          + (367 * (mMonth - 2 - 12 * mm))/12
          - (3 * ((yy + 4900 + mm)/100))/4
          + mDay - 32075;
      return jdn - kDaysSinceJulianEpoch;
    }


    /**
     * Fill in the (year, month, day, dayOfWeek) fields from daysSinceEpoch.
     * The (hour, minute, second, zoneOffset) fields are left untouched.
     *
     * See https://en.wikipedia.org/wiki/Julian_day.
     */
    void fillUsingDaysSinceEpoch(uint32_t daysSinceEpoch) {
      uint32_t J = daysSinceEpoch + kDaysSinceJulianEpoch;
      uint32_t f = J + 1401 + (((4 * J + 274277 ) / 146097) * 3) / 4 - 38;
      uint32_t e = 4 * f + 3;
      uint32_t g = e % 1461 / 4;
      uint32_t h = 5 * g + 2;
      mDay = (h % 153) / 5 + 1;
      mMonth = (h / 153 + 2) % 12 + 1;
      mYear = (e / 1461) - 4716 + (12 + 2 - mMonth) / 12 - kEpochYear;

      // 2000-01-01 is Saturday (7)
      mDayOfWeek = (daysSinceEpoch + 6) % 7 + 1;
    }

    uint8_t mYear; // [00, 99], year - 2000
    uint8_t mMonth; // [1, 12]
    uint8_t mDay; // [1, 31]
    uint8_t mHour; // [0, 23]
    uint8_t mMinute; // [0, 59]
    uint8_t mSecond; // [0, 59]
    ZoneOffset mZoneOffset; // offset from UTC
    mutable uint8_t mDayOfWeek; // (1=Sunday, 7=Saturday)
};

/**
 * Return true if two OffsetDateTime objects are equal in all components.
 * Optimized for small changes in the less signficant fields, such as 'second'
 * or 'minute'. The dayOfWeek is a derived field so it is not explicitly used
 * to test equality. If all the other fields are identical, then the dayOfWeek
 * must also be equal.
 */
inline bool operator==(const OffsetDateTime& a, const OffsetDateTime& b) {
  return a.mSecond == b.mSecond
      && a.mMinute == b.mMinute
      && a.mHour == b.mHour
      && a.mDay == b.mDay
      && a.mMonth == b.mMonth
      && a.mYear == b.mYear
      && a.mZoneOffset == b.mZoneOffset;
}

/** Return true if two OffsetDateTime objects are not equal. */
inline bool operator!=(const OffsetDateTime& a, const OffsetDateTime& b) {
  return ! (a == b);
}

}

#endif
