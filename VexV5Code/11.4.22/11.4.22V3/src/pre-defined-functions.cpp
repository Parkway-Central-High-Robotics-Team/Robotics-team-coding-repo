#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

void flickDisk(void){
  discFlick.setStopping(coast);
  discFlick.spinFor(reverse, 75, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(forward, 150  , timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(reverse, 175, timeUnits::msec, 100, velocityUnits::pct);
}

void intakeIn(int vel){
  intake.spin(forward, 100, velocityUnits::pct);
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
  intake.spin(reverse, 100, velocityUnits::pct);
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