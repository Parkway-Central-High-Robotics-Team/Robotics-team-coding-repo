#include "vex.h"
#include "autonomous-functions.h"
using namespace vex;

void auton_function_test(void) {
  //strafeLeftDis(10,25);
  Drivetrain.driveFor(forward,15,inches);
  //strafeLeftTime(1500,25);
  //strafeRightTime(1500,25);
  //turn right
  Drivetrain.turnFor(right, 90, degrees);
  Brain.Screen.newLine();
  /*wait(100, timeUnits::msec);
  //go forward to reach shooting range and start shoooting mtrs
  Drivetrain.driveFor(forward,5,inches);
  startFlyWheel(100);
  wait(100, timeUnits::msec);
  //shoot preloads
  flickDisk();
  wait(100, timeUnits::msec);
  intakeInTime(1000, 100);
  flickDisk();
  wait(100, timeUnits::msec);
  intakeInTime(1000, 100);
  flickDisk();
  wait(100, timeUnits::msec);
  stopFlyWheel();*/
}