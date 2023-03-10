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
int side = redSide;
////////////////////
void visionTurn(void){
  	//#region config_init
  //Drivetrain.setTimeout(100, msec);
	int screen_middle_x = 316 / 2;
  bool linedup = false;
  //take it slow
  Drivetrain.setDriveVelocity(7,vex::velocityUnits::pct);
  Drivetrain.setTurnVelocity(7,vex::velocityUnits::pct);
  while(not linedup) {
      //snap a picture
      Vision1.takeSnapshot(SIG_BLUE);
      //did we see anything?
      if(Vision1.objectCount > 0) {
          //where was the largest thing?
          if(Vision1.largestObject.width >= 30){
            if(Vision1.largestObject.centerX < screen_middle_x - 15) {
                //on the left, turn left
                Drivetrain.turn(turnType::left);
            } else if (Vision1.largestObject.centerX > screen_middle_x + 15) {
                //on the right, turn right
                Drivetrain.turn(turnType::right);
            } else {
                //in the middle, we're done lining up
                linedup = true;
                Drivetrain.stop(coast);
            }
          }
      } else {
          //saw nothing, relax
          Drivetrain.stop(coast);
      }
  }
  Drivetrain.turnFor(right, 7, rotationUnits::deg);
}
////////////////////
int returner = 0;
////////////////////
bool blueTest(void) {
  Vision1.takeSnapshot(SIG_BLUE);
  if(Vision1.largestObject.exists){
    if(Vision1.largestObject.width >= 50){
      return true;
    }
  }
  return false;
}
////////////////////
bool redTest(void) {
  Vision1.takeSnapshot(SIG_RED);
  if(Vision1.largestObject.exists){
    if(Vision1.largestObject.width >= 50){
      return true;
    }
  }
  return false;
}
////////////////////
void spinnerPos(void) {
  bool blueExist = blueTest();
  bool redExist = redTest();

  if(side == redSide){
    if(!redExist && blueExist){
      intake.stop(brakeType::hold);
    }else {
      intake.spin(forward, 15, velocityUnits::pct);
    }
  }else if (side == blueSide) {
    if(redExist && !blueExist){
      intake.stop(brakeType::hold);
    }else {
      intake.spin(forward, 15, velocityUnits::pct);
    }
  }
}
////////////////////
void spinnerInbetween(void){
  if(side == 0){
    intake.setVelocity(50, velocityUnits::pct);
    intake.spinFor(forward, 25, rotationUnits::deg);
  }else if (side == 1) {
    intake.setVelocity(50, velocityUnits::pct);
    intake.spinFor(reverse, 25, rotationUnits::deg);
  }
}
////////////////////
void visionTest(void){
    spinnerPos();
}
////////////////////