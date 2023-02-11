#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;


void auton_skills(void){
  startFlyWheel(100);
  rollerTime(500, 100);
  moveForwardTime(500);
  turnLeftTime(150);
  indexerFireAuton();
  turnLeftTime(1000);
  startIntake();
  moveBackwardTime(1000);
  stopIntake();
  turnLeftTime(1000);
  indexerFireAuton();
  turnRightTime(1000);
  moveBackwardTime(1000);
  
}


void auton_on_roller(void){

}

void auton_off_roller(void){
  
}
