/*
 * MIT License
 * Copyright (c) 2018 Brian T. Park
 */

#ifndef ACE_TIME_SYSTEM_CLOCK_HEARTBEAT_LOOP_H
#define ACE_TIME_SYSTEM_CLOCK_HEARTBEAT_LOOP_H

#include <stdint.h>
#include "SystemClock.h"

namespace ace_time {
namespace clock {

/**
 * A class that peridically freshens the SystemClock using the heartbeat call
 * to getNow(). Call loop() from the global loop() method as quickly as
 * practical. The class will make a call to SystemClock::getNow() every every
 * heartbeatPeriodMillis interval.
 */
class SystemClockHeartbeatLoop {
  public:
    /**
     * Constructor.
     *
     * @param systemClock the underlying SystemClock
     * @param heartbeatPeriodMillis millis between calls to getNow()
     *    (default 5000)
     */
    explicit SystemClockHeartbeatLoop(SystemClock& systemClock,
          uint16_t heartbeatPeriodMillis = 5000):
      mSystemClock(systemClock),
      mHeartbeatPeriodMillis(heartbeatPeriodMillis) {}

    /**
     * Call this from the global loop() method to make SystemClock
     * keep in sync with the system millis().
     */
    void loop() {
      unsigned long nowMillis = millis();
      uint16_t timeSinceLastSync = nowMillis - mLastSyncMillis;

      // Make sure that mEpochSeconds does not fall too far behind.
      if (timeSinceLastSync >= mHeartbeatPeriodMillis) {
        mSystemClock.getNow();
        mLastSyncMillis = nowMillis;
      }
    }

  private:
    // disable copy constructor and assignment operator
    SystemClockHeartbeatLoop(const SystemClockHeartbeatLoop&) = delete;
    SystemClockHeartbeatLoop& operator=(const SystemClockHeartbeatLoop&) =
        delete;

    SystemClock& mSystemClock;
    uint16_t const mHeartbeatPeriodMillis;

    unsigned long mLastSyncMillis = 0; // should be the same type as millis()
};

}
}

#endif
