#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;

void auton_skills(void){
  //enableDrivePID = false;
  PID();
  startFlyWheel(75);
  rollerTime(500, 100);
  wait(1000, timeUnits::msec);
  moveForwardTime(75);
  turnLeftTime(150);
  wait(600, timeUnits::msec);
  indexerFireAuton();
  turnLeftTime(500);
  RightDriveSmart.spinFor(forward, 1600, timeUnits::msec);
  startFlyWheel(70);
  startIntake();
  moveBackwardTime(1700);
  turnRightTime(565);
  //intakeInTime(500, 100);
  wait(3000, timeUnits::msec);
  stopIntake();
  stopFlyWheel();



  //startIntake();
  //moveBackwardTime(3000);
  //stopIntake();
  //turnLeftTime(1000);
  //indexerFireAuton();
  //turnRightTime(1000);
  //moveBackwardTime(1000);
  
}


void auton_skills2(){
  startFlyWheel(65);
  rollerTime(300);
  //moveForwardTime(200);
  //wait(100, timeUnits::msec);
  //visionTurn();
  startIntake();
  moveForwardTime(600);
  wait(150, timeUnits::msec);
  Drivetrain.turnFor(right, 90, rotationUnits::deg);
  //turnRightTime(600);
  wait(150, timeUnits::msec);
  stopIntake();
  moveBackwardTime(915);
  rollerTime(300);
  moveForwardTime(200);
  wait(150, timeUnits::msec);
  turnLeftTime(490);
  wait(150, timeUnits::msec);
  moveForwardTime(1250);
  indexerFireSkills();
  moveBackwardTime(770);
  turnLeftTime(666);
  startIntake();
  moveBackwardTime(1950);
  stopIntake();
  turnRightTime(500);
  //visionTurn();
  indexerFireSkills();
  turnLeftTime(450);
  startIntake();
  moveBackwardTime(1800);







  }

void autonSkillsBackup(void){
  startFlyWheel(65);
  rollerTime(300);
  //moveForwardTime(200);
  //wait(100, timeUnits::msec);
  //visionTurn();
  startIntake();
  moveForwardTime(500);
  turnRightTime(500);
  stopIntake();
  moveBackwardTime(815);
  rollerTime(300);
  moveForwardTime(200);
  turnLeftTime(490);
  moveForwardTime(1250);
  indexerFireSkills();
  moveBackwardTime(770);
  turnLeftTime(666);
  startIntake();
  moveBackwardTime(1950);
  stopIntake();
  turnRightTime(500);
  //visionTurn();
  indexerFireSkills();
  turnLeftTime(450);
  startIntake();
  moveBackwardTime(1800);
}