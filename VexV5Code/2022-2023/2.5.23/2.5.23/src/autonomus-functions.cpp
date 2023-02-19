#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;

void auton_function_test(void) {
  /*
  rollerTime(500);
  moveForwardTime(600);
  turnRightTime(1050);
  moveBackwardTime(750);
  rollerTime(500);
  moveForwardTime(300);
  turnLeftTime(500);
  moveForwardTime(3800);
  turnRightTime(1450);
  moveBackwardTime(850);
  rollerTime(750);
  moveForwardTime(600);
  turnRightTime(1100);
  moveBackwardTime(700);
  rollerTime(500);
  */
  rollerTime(100, -100);

  
  /*
  //roller first
  roller(500);
  wait(100, timeUnits::msec);
  // go forward, turn right, move backward
  moveForward(500);
  turnRight(1450);
  moveBackward(780);
  roller(500);
  moveForward(300);
  turnRight(2000);



  
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
  */
}

void auton_skills(void){

  /*Drivetrain.drive(reverse, 50, velocityUnits::pct);
  wait(1000, timeUnits::msec);
  Drivetrain.stop();
  turnRightTime(320);
  Drivetrain.drive(reverse, 50, velocityUnits::pct);
  wait(500, timeUnits::msec);
  Drivetrain.stop();
  rollerTime(275, 100);*/



  Drivetrain.drive(reverse, 10, velocityUnits::pct);
  wait(500, timeUnits::msec);
  rollerTime(175, 100);
  Drivetrain.stop();


  /*startFlyWheel(100);
  rollerTime(500, -100);
  moveForwardTime(75);
  turnLeftTime(140);
  indexerUp();
  wait(1200, msec);
  intakeInTime(1000, 100);
  wait(1200, msec);
  intakeInTime(1500, 100);
  stopFlyWheel();*/



  //indexerFireAuton();
  //wait(500, timeUnits::msec);
  //indexerFireAuton();
  
}

void auton_skills2(void){
  startFlyWheel(95);
  moveBackwardTime(850);
  turnRightTime(420);
  moveBackwardTime(350, 75);
  rollerTime(500, -100);  
  turnRightTime(150);
  //moveForwardTime(100);
  indexerUp();
  wait(1200, msec);
  intakeInTime(1200, 100);
  wait(1200, msec);
  intakeInTime(1500, 100);
  stopFlyWheel();

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

void shootLowerGoal(void) {
  //intake.spinFor(forward, 15, rotationUnits::deg, 15, velocityUnits::pct);
  Drivetrain.driveFor(forward, 5, distanceUnits::in, 50, velocityUnits::pct);
  Drivetrain.turnFor(right, 90, rotationUnits::deg, 50, velocityUnits::pct);
  startFlyWheel(100);
  wait(500, msec);
  intakeIn(100);
  wait(3000, msec);
  intakeStop();
  stopFlyWheel();
}

void roller2(void){
  rollerTime(250);
}