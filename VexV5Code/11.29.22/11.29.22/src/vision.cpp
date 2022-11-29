#include "vex.h"
#include "pre-defined-functions.h"
#include "vision.h"
using namespace vex;

////////////////////
// varable to determine what side to rotate the vision sensor to
// change before each match
// red = 0
// blue = 1
int redSide = 0;
int blueSide = 1;
int side = blueSide;
////////////////////

////////////////////
// vision rotation code
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
////////////////////

////////////////////
int returner = 0;

bool blueTest(void) {
  Vision1.takeSnapshot(SIG_BLUE);
  if(Vision1.largestObject.exists){
    if(Vision1.largestObject.width >= 50){
      return true;
    }
  }
  return false;
}

bool redTest(void) {
  Vision1.takeSnapshot(SIG_RED);
  if(Vision1.largestObject.exists){
    if(Vision1.largestObject.width >= 50){
      return true;
    }
  }
  return false;
}

void spinnerPos(void) {
  bool blueExist = blueTest();
  bool redExist = redTest();

  if(side == redSide){
    if(!redExist && blueExist){
      intake.stop(brakeType::hold);
    }else {
      intake.spin(forward, 35, velocityUnits::pct);
    }
  }else if (side == blueSide) {
    if(redExist && !blueExist){
      intake.stop(brakeType::hold);
    }else {
      intake.spin(forward, 35, velocityUnits::pct);
    }
  }
  /*if(blueExist && redExist == false){
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
  return returner;*/
}

/*void spinnerBlueToRed(void){
  //intake.setVelocity(50, velocityUnits::pct);
  //intake.spinFor(forward, 25, rotationUnits::deg);
  if(side==0){
    intake.spin(forward, 50, velocityUnits::pct);
  }

}

void spinnerRedToBlue(void){
  //intake.setVelocity(50, velocityUnits::pct);
  //intake.spinFor(reverse, 25, rotationUnits::deg);
  intake.spin(reverse, 50, velocityUnits::pct);
}

void spinnerStop(void){

}*/

void spinnerInbetween(void){
  if(side == 0){
    intake.setVelocity(50, velocityUnits::pct);
    intake.spinFor(forward, 25, rotationUnits::deg);
  }else if (side == 1) {
    intake.setVelocity(50, velocityUnits::pct);
    intake.spinFor(reverse, 25, rotationUnits::deg);
  }
}

void visionTest(void){
    spinnerPos();
    /*if((int)returner == 1){
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
  }*/
}
////////////////////