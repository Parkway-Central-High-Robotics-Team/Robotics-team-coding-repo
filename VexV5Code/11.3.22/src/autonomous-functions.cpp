#include "vex.h"
#include "autonomous-functions.h"
using namespace vex;

void auton_function_test(void) {
  Drivetrain.driveFor(forward,5,inches);
  //turn right
  /*
  Drivetrain.turnFor(right, 90, degrees);
  wait(100, timeUnits::msec);
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

void all_corners_1_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(reverse,41,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.driveFor(forward,35,inches);
}