#include "vex.h"
#include "autonomous-functions.h"
#include "pid.h"

using namespace vex;

void auton_skills(void){
  //enableDrivePID = false;
  //PID();
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

void PID_test(void){
  /*Brain.Screen.print("IN PID");
  vex::task billWiTheScienceFi(drivePID);

  resetDriveSensors = true;
  desiredValue = 300;
  desiredTurnValue = 600;

  vex::task::sleep(1000);

  resetDriveSensors = true;
  desiredValue = 300;
  desiredTurnValue = 300;*/
}

void auton_skills2(){
  startFlyWheel(65);
  rollerTime(300);
  moveForwardTime(500);
  turnRightTime(450);
  moveBackwardTime(830);
  rollerTime(300);
  moveForwardTime(120);
  turnLeftTime(450);
  moveForwardTime(1250);
  //indexerFireSkills();
  moveBackwardTime(700);
  turnLeftTime(625);
  startIntake();
  moveBackwardTime(1750);
  stopIntake();
  turnRightTime(550);
  //indexerFireSkills();
  turnLeftTime(550);
}


void auton_on_roller(void){

}

void auton_off_roller(void){
  
}
