#ifndef ACE_TIME_ZONE_INFO_H
#define ACE_TIME_ZONE_INFO_H

#include <stdint.h>
#include "ZonePolicy.h"

namespace ace_time {
namespace common {

/**
 * An entry in ZoneInfo which describes which ZonePolicy was being followed
 * during a particular time period. Corresponds to one line of the ZONE record
 * in the TZ Database file ending with an UNTIL field. The ZonePolicy is
 * determined by the RULES column in the TZ Database file.
 */
struct ZoneEra {
  /** The maximum value of untilYearShort. */
  static const int8_t kMaxUntilYearShort = ZoneRule::kMaxYearShort + 1;

  /** UTC offset in 15 min increments. Determined by the GMTOFF column. */
  int8_t const offsetCode;

  /**
   * Zone policy, determined by the RULES column. Set to nullptr if the RULES
   * column is '-'
   */
  const ZonePolicy* const zonePolicy;

  /**
   * Zone abbreviations (e.g. PST, EST) determined by the FORMAT column. Only a
   * single letter subsitution is supported so that '%s' is changed to just
   * '%'. For example, 'E%ST' is stored as 'E%T', and the LETTER substitution
   * is performed on the '%' character.
   */
  const char* const format;

  /**
   * Era is valid until currentTime < untilYear. Stored as (year - 2000)
   * to save space. Comes from the UNTIL column.
   */
  int8_t const untilYearShort;

  /** The month field in UNTIL (1-12). Will never be 0. */
  uint8_t const untilMonth;

  /**
   * The day field in UNTIL (1-31). Will never be 0. Also, there's no need for
   * untilDayOfWeek, because the database generator will resolve the exact day
   * of month based on the known year and month.
   */
  uint8_t const untilDay;

  /** The hour field of the UNTIL field (0-23). */
  uint8_t const untilHour;

  /** UNTIL time modifier suffix: 'w', 's' or 'u'. */
  uint8_t const untilTimeModifier;
};

/**
 * Representation of a given time zone, implemented as an array of ZoneEra
 * records.
 */
struct ZoneInfo {
  /** Name of zone. */
  const char* const name; // name of zone

  /** ZoneEra entries in increasing order of UNTIL time. */
  const ZoneEra* const eras;

  /** Number of ZoneEra entries. */
  uint8_t const numEras;
};

}
}

#endif
