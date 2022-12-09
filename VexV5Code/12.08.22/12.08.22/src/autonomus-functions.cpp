#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;
void moveForward(int milliseconds){
  LeftDriveSmart.spinFor(forward, milliseconds, timeUnits::msec, 100, velocityUnits::pct);
  RightDriveSmart.spinFor(forward,milliseconds, timeUnits::msec, 100, velocityUnits::pct);
}

void moveBackward(int milliseconds){
  LeftDriveSmart.spinFor(reverse, milliseconds, timeUnits::msec, 100, velocityUnits::pct);
  LeftDriveSmart.spinFor(reverse, milliseconds, timeUnits::msec, 100, velocityUnits::pct);
}

void turnRight(int milliseconds){
  LeftDriveSmart.spinFor(forward, milliseconds, timeUnits::msec, 100, velocityUnits::pct);
  RightDriveSmart.spinFor(reverse,milliseconds, timeUnits::msec, 100, velocityUnits::pct);
}

void turnLeft(int milliseconds){
  LeftDriveSmart.spinFor(reverse, milliseconds, timeUnits::msec, 100, velocityUnits::pct);
  RightDriveSmart.spinFor(forward,milliseconds, timeUnits::msec, 100, velocityUnits::pct);
}

void expansion(void){
  //enter in pneumatic code from "pneumaticstestv3"
}


void auton_function_test(void) {
  //roller first

  // go forward, turn right, move backward
  moveForward(1000);
  turnRight(1000);
  moveBackward(1000);
  // roller 
  //turn right until parallel with divison
  turnRight(1000);
  //move forward to top left roller
  moveForward(1000);
  //turn left
  turnLeft(1000);
  //roller
  //move backward, turn right
  moveBackward(1000);
  turnRight(1000);
  // roller
  //move out and expand

}

void regular_auton(void) {
  intake.spinFor(forward, 15, rotationUnits::deg, 15, velocityUnits::pct);
  Drivetrain.driveFor(forward, 5, distanceUnits::in, 50, velocityUnits::pct);
  Drivetrain.turnFor(right, 120, rotationUnits::deg, 50, velocityUnits::pct);
  Drivetrain.driveFor(forward, 50, distanceUnits::in, 50, velocityUnits::pct);
  startFlyWheel(100);
  Drivetrain.turnFor(right, 90, rotationUnits::deg, 50, velocityUnits::pct);
  intakeIn(100);
  wait(3000, msec);
  intakeStop();
  stopFlyWheel();
}