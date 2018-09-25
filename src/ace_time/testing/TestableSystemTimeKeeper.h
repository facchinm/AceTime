#ifndef ACE_TIME_TESTABLE_SYSTEM_TIME_KEEPER_H
#define ACE_TIME_TESTABLE_SYSTEM_TIME_KEEPER_H

#include <stdint.h>
#include "../SystemTimeKeeper.h"

namespace ace_time {
namespace testing {

/**
 * A version of SystemTimeKeeper that allows the millis() function to be
 * manually set for testing purposes.
 */
class TestableSystemTimeKeeper: public SystemTimeKeeper {
  public:
    explicit TestableSystemTimeKeeper(
            TimeProvider* syncTimeProvider /* nullable */,
            TimeKeeper* backupTimeKeeper /* nullable */):
        SystemTimeKeeper(syncTimeProvider, backupTimeKeeper) {}

    virtual unsigned long millis() const override {
      return mMillis;
    }

    void millis(unsigned long millis) {
      mMillis = millis;
    }

    unsigned long mMillis = 0;
};

}
}

#endif

