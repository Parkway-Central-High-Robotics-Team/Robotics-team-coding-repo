#include "vex.h"
#include "autonomous-functions.h"
using namespace vex;

void auton_function_test(void) {
  Drivetrain.setDriveVelocity(40, velocityUnits::pct);
  Drivetrain.driveFor(forward,1, inches);
  intake.spinFor(reverse, 400, timeUnits::msec, 50, velocityUnits::pct);
  Drivetrain.driveFor(reverse,10, inches);
  Drivetrain.turn(left);
  wait(450, msec);
  Drivetrain.stop();
  wait(48000, msec);
  intake.spin(reverse, 75, velocityUnits::pct);
  Drivetrain.driveFor(reverse,100, inches);
  //Drivetrain.drive(reverse);*/

  //Drivetrain.driveFor(forward,1, inches);
  //intake.spinFor(reverse, 500, timeUnits::msec, 75, velocityUnits::pct);


  /*Drivetrain.driveFor(forward,5,inches);
  //turn right
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
