#ifndef ACE_TIME_ZONE_MANAGER_H
#define ACE_TIME_ZONE_MANAGER_H

#include <stdint.h>
#include "ZoneOffset.h"
#include "ZoneInfo.h"

class ZoneManagerTest_init_2001;
class ZoneManagerTest_init_2018;

namespace ace_time {

/**
 * Data structure that captures the matching ZoneInfoEntry for a given year.
 * Can be cached based on the year.
 */
struct ZoneMatch {
  const ZoneInfoEntry* entry;
  const ZoneRule* rule; // can be null
  uint32_t startEpochSeconds; // transition time of given rule
  int8_t offsetCode; // effective offsetCode at the start of zone period
  // TODO: add abbreviation
};

/**
 * Manages a given ZoneInfo.
 */
class ZoneManager {
  public:
    ZoneManager(const ZoneInfo* zoneInfo):
        mZoneInfo(zoneInfo) {}

    /** Return the ZoneMatch at the given epochSeconds. */
    const ZoneMatch* getZoneMatch(uint32_t epochSeconds) {
      // TODO: The UTC year will be slightly different if epochSeconds lands on
      // Jan 1 or Dec 31. Unfortunately, we don't know the actual local year
      // until we find the ZoneInfoEntry, but we can't find the ZoneInfoEntry
      // until we know the year. We may need to cache multiple years.
      LocalDate ld = LocalDate::forEpochSeconds(epochSeconds);
      init(ld);
      return findMatch(epochSeconds);
    }

  private:
    friend class ::ZoneManagerTest_init_2001;
    friend class ::ZoneManagerTest_init_2018;

    static const uint8_t kMaxCacheEntries = 5;

    void init(const LocalDate& ld) {
      // If the UTC date is 12/31, the local date could be the next year. If we
      // assume that no DST transitions happen on 12/31, then we can pretend
      // that the current year is (UTC year + 1) and extract the various rules
      // based upon that year.
      uint8_t year = ld.year();
      if (ld.month() == 12 && ld.day() == 31) {
        year++;
      }

      if (!isFilled(year)) {
        mYear = year;
        mNumMatches = 0;
        addLastYear();
        addCurrentYear();
        calcTransitions();
        mIsFilled = true;
      }
    }

    bool isFilled(uint8_t year) const {
      return (year == mYear) && mIsFilled;
    }

    /**
     * Add the last matching rule from last year, to determine the offset
     * at the beginning of the current year.
     *  TODO: special handing for year 2000 (i.e. year == 0)
     */
    void addLastYear() {
      uint8_t lastYear = mYear - 1;
      const ZoneInfoEntry* const entry = findEntry(lastYear);
      // TODO: check for (entry == nullptr).

      // Some countries don't have a ZonePolicy, e.g. South Africa
      const ZonePolicy* const zonePolicy = entry->zonePolicy;
      if (zonePolicy == nullptr) {
        mPreviousMatch = {entry, nullptr, 0, 0};
        return;
      }

      // Find the latest rule for last year. Assume that there are no more than
      // 1 rule per month.
      const ZoneRule* latest = nullptr;
      for (uint8_t i = 0; i < zonePolicy->numRules; i++) {
        const ZoneRule* const rule = &zonePolicy->rules[i];
        if ((rule->fromYear <= lastYear) && (lastYear <= rule->toYear)) {
          if ((latest == nullptr) || (rule->inMonth > latest->inMonth)) {
            latest = rule;
          }
        }
      }
      mPreviousMatch = {entry, latest, 0, 0};
    }

    /** Add all matching rules from the current year. */
    void addCurrentYear() {
      const ZoneInfoEntry* const entry = findEntry(mYear);

      const ZonePolicy* const zonePolicy = entry->zonePolicy;
      if (zonePolicy == nullptr) return;

      for (uint8_t i = 0; i < zonePolicy->numRules; i++) {
        const ZoneRule* const rule = &zonePolicy->rules[i];
        if ((rule->fromYear <= mYear) && (mYear <= rule->toYear)) {
          addRule(entry, rule);
        }
      }
    }

    /**
     * Add (entry, rule) to the cache, in sorted order. Essentially, this is
     * doing an Insertion Sort of the ZoneMatch elements.
     */
    void addRule(const ZoneInfoEntry* entry, const ZoneRule* rule) const {
      if (mNumMatches >= kMaxCacheEntries) return;

      // insert
      mMatches[mNumMatches] = {entry, rule, 0, 0};
      mNumMatches++;

      // sort
      for (uint8_t i = mNumMatches - 1; i > 0; i--) {
        ZoneMatch& left = mMatches[i - 1];
        ZoneMatch& right = mMatches[i];
        // assume only 1 rule per month
        if (left.rule->inMonth > right.rule->inMonth) {
          ZoneMatch tmp = left;
          left = right;
          right = tmp;
        }
      }
    }

    /** Find the matching entry for year. */
    const ZoneInfoEntry* findEntry(uint8_t year) const {
      for (uint8_t i = 0; i < mZoneInfo->numEntries; i++) {
        const ZoneInfoEntry* entry = &mZoneInfo->entries[i];
        if (year <= entry->untilYear) return entry;
      }
      return nullptr;
    }

    /** Calculate the epochSeconds of each ZoneMatch rule. */
    void calcTransitions() {
      mPreviousMatch.startEpochSeconds = 0;
      mPreviousMatch.offsetCode = mPreviousMatch.entry->offsetCode
          + mPreviousMatch.rule->deltaCode;
      ZoneMatch* previousMatch = &mPreviousMatch;

      for (uint8_t i = 0; i < mNumMatches; i++) {
        ZoneMatch& match = mMatches[i];

        // Determine the start date of the rule.
        LocalDate limitDate = LocalDate::forComponents(
            mYear, match.rule->inMonth, match.rule->onDayOfMonth);
        uint8_t dayOfWeekShift =
            (match.rule->onDayOfWeek - limitDate.dayOfWeek() + 7) % 7;
        uint8_t startDayOfMonth = match.rule->onDayOfMonth + dayOfWeekShift;

        // Determine the effective offset code
        match.offsetCode = match.entry->offsetCode + match.rule->deltaCode;

        // Determine the offset of the 'atHourModifier'. If 'w', then we
        // must use the offset of the *previous* zone rule.
        int8_t ruleOffsetCode;
        if (match.rule->atHourModifier == 'w') {
          ruleOffsetCode = previousMatch->entry->offsetCode
              + previousMatch->rule->deltaCode;
        } else if (match.rule->atHourModifier == 's') {
          ruleOffsetCode = previousMatch->entry->offsetCode;
        } else {
          ruleOffsetCode = 0;
        }

        // startDateTime
        OffsetDateTime startDateTime = OffsetDateTime::forComponents(
            mYear, match.rule->inMonth, startDayOfMonth,
                match.rule->atHour, 0, 0,
                ZoneOffset::forOffsetCode(ruleOffsetCode));
        match.startEpochSeconds = startDateTime.toEpochSeconds();

        previousMatch = &match;
      }
    }

    /** Search the cache and find closest ZoneMatch. */
    const ZoneMatch* findMatch(uint32_t epochSeconds) const {
      const ZoneMatch* closestMatch = &mPreviousMatch;
      for (uint8_t i = 0; i < mNumMatches; i++) {
        const ZoneMatch* m = &mMatches[i];
        if (m->startEpochSeconds <= epochSeconds) {
          closestMatch = m;
        }
      }
      return closestMatch;
    }

    const ZoneInfo* const mZoneInfo;

    mutable uint8_t mYear = 0;
    mutable bool mIsFilled = false;
    mutable uint8_t mNumMatches = 0;
    mutable ZoneMatch mMatches[kMaxCacheEntries];
    mutable ZoneMatch mPreviousMatch; // previous year's match
};

}

#endif
