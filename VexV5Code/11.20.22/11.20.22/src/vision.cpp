#include "vision.h"
using namespace vex;

bool blueTest(void) {
  Vision1.takeSnapshot(SIG_BLUE);
  if(Vision1.largestObject.exists){
    return true;
  }
  return false;
}

bool redTest(void) {
  Vision1.takeSnapshot(SIG_RED);
  if(Vision1.largestObject.exists){
    return true;
  }
  return false;
}

int spinnerPos(void) {
  bool blueExist = blueTest();
  bool redExist = redTest();
  if(blueExist && !redExist){
    return 1;
  }else if (redExist && !blueExist) {
    return 2;
  }else if (redExist && blueExist) {
    return 3;
  }
  return 0;
}

void spinnerBlueToRed(void){
  intake.spinFor(forward, 50, rotationUnits::deg);
}

void spinnerRedToBlue(void){
  intake.spinFor(reverse, 50, rotationUnits::deg);
}

void spinnerInbetween(void){

}

void visionTest(void){
  if((int)spinnerPos == 1){
    spinnerBlueToRed();
    Brain.Screen.print("spinnerBlueToRed");
  }else if ((int)spinnerPos == 2) {
    spinnerRedToBlue();
    Brain.Screen.print("spinnerRedToBlue");
  }else if ((int)spinnerPos == 3) {
    spinnerInbetween();
    Brain.Screen.print("spinnerInbetween");
  }
}