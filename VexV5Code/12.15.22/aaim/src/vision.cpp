#include "vex.h"
#include "predeffun.h"
#include "vision.h"
using namespace vex;


void visionaim(void){
  	//#region config_init
	Vision1.setBrightness(50);
	Vision1.setSignature(SIG_1);
	//#endregion config_init
	
    //camera image is 316 pixels wide, so the center is 316/2
    int screen_middle_x = 316 / 2;
    bool linedup = false;
    //take it slow
    Drivetrain.setDriveVelocity(10,vex::velocityUnits::pct);
    Drivetrain.setTurnVelocity(10,vex::velocityUnits::pct);
    while(not linedup) {
        //snap a picture
        Vision1.takeSnapshot(SIG_1);
        //did we see anything?
        if(Vision1.objectCount > 0) {
            //where was the largest thing?
            if(Vision1.largestObject.centerX < screen_middle_x - 5) {
                //on the left, turn left
                Drivetrain.turn(turnType::left);
            } else if (Vision1.largestObject.centerX > screen_middle_x + 5) {
                //on the right, turn right
                Drivetrain.turn(turnType::right);
            } else {
                //in the middle, we're done lining up
                linedup = true;
                Drivetrain.stop(coast);
            }
        } else {
            //saw nothing, relax
            Drivetrain.stop(coast);
        }
    }
}