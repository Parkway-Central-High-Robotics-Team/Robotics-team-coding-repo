#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;


void auton_skills(void){
  startFlyWheel(90);
  rollerTime(500, 100);
  moveForwardTime(110);
  turnLeftTime(145);
  wait(1000, timeUnits::msec);
  indexerFireAuton();
  turnLeftTime(800);
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
