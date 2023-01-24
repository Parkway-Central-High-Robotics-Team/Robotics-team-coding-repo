#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;

void auton_function_test(void) {
  //roller first
  rollerTime(500);
  //wait(100, timeUnits::msec);
  // go forward, turn right, move backward
  moveForwardTime(1000);
  turnRightTime(2190);
  moveBackwardTime(1125);
  rollerTime(500);
  moveForwardTime(500);
  turnRightTime(3000);
  moveBackwardTime(6050);
  turnLeftTime(1300);
  moveBackwardTime(1250);
  rollerTime(500);
  moveForwardTime(1250);
  turnRightTime(2000);
  moveBackwardTime(1300);
  rollerTime(500);
  moveForwardTime(1000);
  turnRightTime(1000);
  expansion();
  


  
  /*turnRight(1000);
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
  */

}

void auton_skills(void){
  rollerTime(250);
  //expansion(); 
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

void roller2(void){
  rollerTime(250);
}