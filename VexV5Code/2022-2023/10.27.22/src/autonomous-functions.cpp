#include "vex.h"
#include "autonomous-functions.h"
using namespace vex;

void auton_function_test(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(forward,8,inches);
  //turn right
  Drivetrain.turnFor(right, 40, degrees);
  wait(100, timeUnits::msec);
  //go forward to reach shooting range and start shoooting mtrs
  Drivetrain.driveFor(forward,8,inches);
  //shoot preloads
  spinMtrs.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  wait(1000, timeUnits::msec);
  discFlick.spinFor(forward, 175, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(reverse, 300, timeUnits::msec, 100, velocityUnits::pct);
  wait(100, timeUnits::msec);
}
