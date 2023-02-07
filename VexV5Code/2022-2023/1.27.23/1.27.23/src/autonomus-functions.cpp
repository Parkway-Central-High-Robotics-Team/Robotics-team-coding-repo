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
  startIntake();

  
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
  startFlyWheel(80);
  rollerTime(500, -100);
  moveForwardTime(150);
  turnLeftTime(135);
  indexerUp();
  wait(1500, msec);
  intakeInTime(1100, 100);
  //startFlyWheel(75);
  //wait(200, msec);
  intakeInTime(1100, 100);
  turnRightTime(1040);
  indexerDown();
  stopFlyWheel();

  //moveBackwardTime(1750, 100);
  //moveForwardTime(1000, 100);
  //startIntake();
  //moveBackwardTime(2500);
  //turnRightTime(450);
  //stopFlyWheel();
  //stopIntake();
  //indexerUp();
  //intakeInTime(3000, 100);
  //indexerDown();
  //stopFlyWheel();


  //stopFlyWheel();




  //indexerFireAuton();
  //wait(500, timeUnits::msec);
  //indexerFireAuton();
  
}

void auton_skills2(void){
  startFlyWheel(80);
  moveBackwardTime(850);
  turnRightTime(430);
  moveBackwardTime(375, 50);
  rollerTime(550, -100);  
  moveForwardTime(120);
  turnRightTime(140);
  //moveForwardTime(100);
  indexerUp();
  wait(1200, msec);
  intakeInTime(1200, 100);
  //wait(1200, msec);
  intakeInTime(1500, 100);
  indexerDown();
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

void auton_skills3(void){
  startFlyWheel(85);
  moveBackwardTime(850);
  turnRightTime(430);
  moveBackwardTime(375, 50);
  rollerTime(500, -100);  
  moveForwardTime(120);
  turnRightTime(140);
  //moveForwardTime(100);
  indexerUp();
  wait(1200, msec);
  intakeInTime(1000, 100);
  //wait(1200, msec);
  intakeInTime(1500, 100);
  stopFlyWheel();

}

void auton_skills_real(void){
  startFlyWheel(65);
  startIntake();
  wait(3000, timeUnits::msec);
  moveBackwardTime(500);
  moveForwardTime(500);
  turnRightTime(625);
  indexerUp();
  wait(3000, timeUnits::msec);
  indexerDown();
  turnLeftTime(625);
  for(int i = 0; i<3; i++){
    moveBackwardTime(500);
    moveForwardTime(500);
  }
  turnRightTime(625);
  indexerUp();
  wait(3000, timeUnits::msec);
  indexerDown();
  turnLeftTime(625);
  for(int i = 0; i<3; i++){
    moveBackwardTime(500);
    moveForwardTime(500);
  }
  turnRightTime(625);
  indexerUp();
  wait(3000, timeUnits::msec);
  indexerDown();
  turnLeftTime(625);



}