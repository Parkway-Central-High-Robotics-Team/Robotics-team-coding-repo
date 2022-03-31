#include "vex.h"
#include "vision.h"
using namespace vex;

int stopwidth = 250;
float offcenterpct;

/*void tracker() {
  if (Vision1.largestObject.width < stopwidth) {
    offcenterpct = (float)abs(158-Vision1.largestObject.centerX)/(float)158*100;
    if(Vision1.largestObject.centerX < 158){
      LeftDriveSmart.spin(fwd, offcenterpct, pct);
      RightDriveSmart.spin(fwd, 100, pct);
    } else {
      RightDriveSmart.spin(fwd, offcenterpct, pct);
      LeftDriveSmart.spin(fwd, 100, pct);
    }
  }else {
  RightDriveSmart.stop(coast);
  LeftDriveSmart.stop(coast);
  }
}*/