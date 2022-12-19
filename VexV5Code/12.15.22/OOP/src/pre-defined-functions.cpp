#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

/*class Intake {
public:
  void spin(directionType direction, int velocity, velocityUnits units) {
    intake.spin(direction, velocity, units);
  }

  void spinFor(directionType direction, int value, rotationUnits type, int velocity, velocityUnits units) {
    intake.spinFor(direction, value, type, velocity, units);
    intake.stop();
  }
};

FlyWheel {
  void spin(int vel, velocityUnits units) {
    spinMtrs.spin(forward, vel, units);
  }

  void stop() {
    spinMtrs.stop();
  }
};*/

///////

Thing thing;


void intakeStop(void) {
  intake.stop();
  //thing.stop(intake, hold);
}

void intakeIn(int vel){
  intake.spin(forward, vel, velocityUnits::pct);
  //thing.spin(intake,forward,vel, vex::velocityUnits::pct)
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
  spinMtrs.stop(coast);
  //thing.stop(spinMtrs, coast);
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