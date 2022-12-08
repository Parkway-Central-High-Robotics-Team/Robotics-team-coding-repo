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