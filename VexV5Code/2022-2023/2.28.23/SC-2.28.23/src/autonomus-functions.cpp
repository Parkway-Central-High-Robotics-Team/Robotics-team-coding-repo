#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;

void auton_skills(void){
  startFlyWheel(75);
  rollerTime(500, 100);
  wait(1000, timeUnits::msec);
  moveForwardTime(75);
  turnLeftTime(150);
  wait(600, timeUnits::msec);
  indexerFireAuton();
  turnLeftTime(500);
  RightDriveSmart.spinFor(forward, 1600, timeUnits::msec);
  startIntake();
  moveBackwardTime(2000);
  turnRightTime(600);
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


void auton_on_roller(void){

}

void auton_off_roller(void){
  
}
