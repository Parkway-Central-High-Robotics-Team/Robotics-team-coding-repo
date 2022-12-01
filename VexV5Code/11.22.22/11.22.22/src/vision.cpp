#include "vex.h"
#include "pre-defined-functions.h"
#include "vision.h"
using namespace vex;

/*bool blueTest(void) {
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
}*/

int returner = 0;

void visionTester(void){
    Vision1.takeSnapshot(SIG_RED);
    if(Vision1.largestObject.exists){
      intake.spinFor(forward, 50, rotationUnits::deg);
    }
}

void visionTester1(void){
    int bright = Vision1.getBrightness();
    Brain.Screen.print(bright);
}

bool blueTest(void) {
  Vision1.takeSnapshot(SIG_BLUE);
  return Vision1.largestObject.exists;
}

bool redTest(void) {
  Vision1.takeSnapshot(SIG_RED);
  return Vision1.largestObject.exists;
}

bool spinnerPos(void) {
  bool blueExist = blueTest();
  bool redExist = redTest();
  if(blueExist && redExist == false){
    Brain.Screen.print("Returned: 1");
    Brain.Screen.newLine();
    returner = 1;
    return returner;
  }else if (redExist && blueExist == false) {
    Brain.Screen.print("Returned: 2");
    Brain.Screen.newLine();
    returner = 2;
    return returner;
  }else if (redExist && blueExist) {
    Brain.Screen.print("Returned: 3");
    Brain.Screen.newLine();
    returner = 3;
    return returner;
  }
  Brain.Screen.print("Returned: 0");
  Brain.Screen.newLine();
  returner = 0;
  return returner;
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
    spinnerPos();
    if((int)returner == 1){
        spinnerBlueToRed();
        Brain.Screen.print("spinnerBlueToRed");
        Brain.Screen.newLine();
    }else if ((int)returner == 2) {
        spinnerRedToBlue();
        Brain.Screen.print("spinnerRedToBlue");
    }else if ((int)returner == 3) {
        spinnerInbetween();
        Brain.Screen.print("spinnerInbetween");
        Brain.Screen.newLine();
  }
}