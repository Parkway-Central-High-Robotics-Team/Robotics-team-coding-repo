#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

/*class StrafeLeft {
  public:
    void strafeLeftThreadFunctionStrafeAGroup(int vel){ 
      StrafeAGroup.spin(reverse, vel, velocityUnits::pct);
    }void strafeLeftThreadFunctionStrafeAGroupTime(int msc, int vel){ 
      StrafeAGroup.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
    }
    void strafeLeftThreadFunctionStrafeAGroupDistance(int inch, int vel){ 
      StrafeAGroup.spinFor(reverse, inch, rotationUnits::deg, vel, velocityUnits::pct);
    }
};

StrafeLeft strafeLeftObj;

void strafeLeftThreadFunctionStrafeAGroup(int vel){ 
  StrafeAGroup.spin(reverse, vel, velocityUnits::pct);
}

void strafeLeftThreadFunctionStrafeBGroup(void){ 
  StrafeBGroup.spin(forward);
}

void strafeLeft(int vel){  
  strafeLeftObj.strafeLeftThreadFunctionStrafeAGroup(vel);
  thread strafeLeftThread1 = thread(strafeLeftThreadFunctionStrafeAGroup);
  thread strafeLeftThread2 = thread(strafeLeftThreadFunctionStrafeBGroup);
  thread (strafeLeftThreadFunctionStrafeAGroup, 100);
  thread
  strafeLeftThread1.join();
  strafeLeftThread2.join();
}*/

void strafeLeft(int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.spin(reverse, vel, velocityUnits::pct);
  StrafeBGroup.spin(forward, vel, velocityUnits::pct);
}

void strafeLeftTime(int msc, int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.spinFor(reverse, msc, timeUnits::msec);
  StrafeBGroup.spinFor(forward, msc, timeUnits::msec);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeLeftDis(int inch, int vel){
  StrafeAGroup.spinFor(reverse, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(forward, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeRightThreadFunctionStrafeAGroup(void){ 
  StrafeAGroup.spin(reverse);
}

void strafeRightThreadFunctionStrafeBGroup(void){ 
  StrafeBGroup.spin(forward);
}

void strafeRight(int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.spin(forward);
  StrafeBGroup.spin(reverse);
}

void strafeRightTime(int msc, int vel){
  StrafeAGroup.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeRightDis(int inch, int vel){
  StrafeAGroup.spinFor(forward, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(reverse, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void flickDisk(void){
  discFlick.setStopping(coast);
  discFlick.spinFor(reverse, 75, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(forward, 150  , timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(reverse, 175, timeUnits::msec, 100, velocityUnits::pct);
}

void intakeIn(int vel){
  intake.spin(forward, vel, velocityUnits::pct);
}

void intakeInTime(int msc, int vel){
  intake.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
  intake.stop();
}

void intakeInDeg(int deg, int vel){
  intake.spinFor(forward, deg, rotationUnits::deg, vel, velocityUnits::pct);
  intake.stop();
}

void intakeOut(int vel){
  intake.spin(reverse, vel, velocityUnits::pct);
}

void intakeOutTime(int msc, int vel){
  intake.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
  intake.stop();
}

void intakeOutDeg(int deg, int vel){
  intake.spinFor(reverse, deg, rotationUnits::deg, vel, velocityUnits::pct);
  intake.stop();
}

void startFlyWheel(int vel){
  spinMtrs.spin(forward, vel, velocityUnits::pct);
}

void stopFlyWheel(void){
  spinMtrs.stop();
}