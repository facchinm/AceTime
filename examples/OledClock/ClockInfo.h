#ifndef OLED_CLOCK_CLOCK_INFO_H
#define OLED_CLOCK_CLOCK_INFO_H

#include <AceTime.h>
#include "config.h"

/** Information about the clock, mostly independent of rendering. */
struct ClockInfo {
  /** 12:00:00 AM to 12:00:00 PM */
  static uint8_t const kTwelve = 0;

  /** 00:00:00 - 23:59:59 */
  static uint8_t const kTwentyFour = 1;

  /** 12/24 mode */
  uint8_t hourMode;

  /** Zone index into the ZoneRegistry. */
  uint8_t zoneIndex;

  /** ManualZoneSpecifier for deep-copy of TimeZone. */
  ace_time::ManualZoneSpecifier manualZspec;

  /** BasicZoneSpecifier for deep-copy of TimeZone.  */
#if TIME_ZONE_SPECIFIER_TYPE == TIME_ZONE_SPECIFIER_TYPE_BASIC
  ace_time::BasicZoneSpecifier autoZspec;
#else
  ace_time::ExtendedZoneSpecifier autoZspec;
#endif

  /** Timezone */
  ace_time::TimeZone timeZone;

  /** DateTime from the TimeKeeper. */
  ace_time::ZonedDateTime dateTime;
};

#endif
