#include <Print.h>
#include "ManualZoneSpecifier.h"

namespace ace_time {

const ManualZoneSpecifier ManualZoneSpecifier::sUtcZoneSpecifier;

void ManualZoneSpecifier::printTo(Print& printer) const {
  printer.print(F("UTC"));
  mStdOffset.printTo(printer);
  printer.print(mIsDst ? F(" (DST)") : F(" (STD)"));
}

}
