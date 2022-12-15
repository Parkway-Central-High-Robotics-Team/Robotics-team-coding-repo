#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

void strafeLeftThreadFunctionStrafeAGroup(void){ 
  StrafeAGroup.spin(reverse);
  this_thread::sleep_for(25);
}

void strafeLeftThreadFunctionStrafeBGroup(void){ 
  StrafeBGroup.spin(forward);
  this_thread::sleep_for(25);
}

void strafeRightThreadFunctionStrafeAGroup(void){ 
  StrafeAGroup.spin(forward);
  this_thread::sleep_for(25);
}

void strafeRightThreadFunctionStrafeBGroup(void){ 
  StrafeBGroup.spin(reverse);
  this_thread::sleep_for(25);
}


void strafeLeft(int vel){
  StrafeAGroup.setVelocity(vel, velocityUnits::pct);
  StrafeBGroup.setVelocity(vel, velocityUnits::pct);
  thread strafeLeftThread1 = thread(strafeLeftThreadFunctionStrafeAGroup);
  thread strafeLeftThread2 = thread(strafeLeftThreadFunctionStrafeBGroup);
  strafeLeftThread1.join();
  strafeLeftThread2.join();
}

void strafeRight(int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.setVelocity(vel, velocityUnits::pct);
  StrafeBGroup.setVelocity(vel, velocityUnits::pct);
  thread strafeRightThread1 = thread(strafeRightThreadFunctionStrafeAGroup);
  thread strafeRightThread2 = thread(strafeRightThreadFunctionStrafeBGroup);
  strafeRightThread1.join();
  strafeRightThread2.join();
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

void intakeStop(void) {
  intake.stop();
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

void pneumaticsFunction(void){
  // NEEDS TO BE SET TO FALSE IN GLOBAL CODESPACE 
  Pneumatics.set(false);
    if(Pneumatics.value() == 0){
      Pneumatics.set(true);
      Brain.Screen.print("L1 is Pressing");
    }else if(Pneumatics.value() == 1){
     Pneumatics.set(false);
     Brain.Screen.print("L2 is Pressing");
  }
}

/*
class Intake {
public:
  void spin(directionType direction, int velocity, velocityUnits units) {
    intake.spin(direction, velocity, units);
  }

  void spinFor(directionType direction, int value, unitType type, int velocity, velocityUnits units) {
    intake.spinFor(direction, value, type, velocity, units);
    intake.stop();
  }
};

class FlyWheel {
public:
  void spin(int velocity, velocityUnits units) {
    spinMtrs.spin(forward, velocity, units);
  }

  void stop() {
    spinMtrs.stop();
  }
};

class Pneumatics {
public:
  void set(bool value) {
    Pneumatics.set(value);
  }

  bool value() {
    return Pneumatics.value();
  }
};

Intake intake;
FlyWheel flyWheel;
Pneumatics pneumatics;

void pneumaticsFunction() {
  pneumatics.set(false);
  if (pneumatics.value() == 0) {
    pneumatics.set(true);
    Brain.Screen.print("L1 is Pressing");
  } else if (pneumatics.value() == 1) {
    pneumatics.set(false);
    Brain.Screen.print("L2 is Pressing");
  }
}
*/