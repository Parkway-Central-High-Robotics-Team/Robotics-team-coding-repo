//#include "vex.h"
#include "vision.h"
#include "pre-defined-functions.h"
#include "vex.h"
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
    return returner;
  }else if (redExist && blueExist == false) {
    Brain.Screen.print("Returned: 2");
    Brain.Screen.newLine();
    return returner;
  }else if (redExist && blueExist) {
    Brain.Screen.print("Returned: 3");
    Brain.Screen.newLine();
    return returner;
  }
  Brain.Screen.print("Returned: 0");
  Brain.Screen.newLine();
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


int stopWidth = 250;
int minColorWidth = 20;
float maxWheelPercentModifier = 1;

float centerErrorPercent;
int c1=157,c2=157,c3=157,c4=157,c5=157;     //set initial centers to the middle of the screen

int smoothedCenter;

bool APressed = false;
bool BPressed = false;
bool XPressed = false;


void TrackWithLargeFunction() {
  centerErrorPercent = ((float)abs(158 - smoothedCenter)/(float)158)*100;
  LeftDriveSmart.spin(fwd, maxWheelPercentModifier*ceil(trunc(stopWidth/Vision1.largestObject.width)/(stopWidth/Vision1.largestObject.width))*(100 - centerErrorPercent + trunc(smoothedCenter/158)*centerErrorPercent), pct);
  RightDriveSmart.spin(fwd, maxWheelPercentModifier*ceil(trunc(stopWidth/Vision1.largestObject.width)/(stopWidth/Vision1.largestObject.width))*(100 - trunc(smoothedCenter/158)*centerErrorPercent), pct);
}


