#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

void flickDisk(void){
  discFlick.setStopping(coast);
  discFlick.spinFor(reverse, 75, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(forward, 200, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(reverse, 200, timeUnits::msec, 100, velocityUnits::pct);
}

void strafeLeft(int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.spin(reverse);
  StrafeBGroup.spin(forward);
}

void strafeLeftTime(int msc, int vel){
  StrafeAGroup.setVelocity(100, percent);
  StrafeBGroup.setVelocity(100, percent);
  StrafeAGroup.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeLeftDis(int inch, int vel){
  StrafeAGroup.setVelocity(100, percent);
  StrafeBGroup.setVelocity(100, percent);
  StrafeAGroup.spinFor(reverse, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(forward, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeRight(int vel){
  StrafeAGroup.setVelocity(vel, percent);
  StrafeBGroup.setVelocity(vel, percent);
  StrafeAGroup.spin(forward);
  StrafeBGroup.spin(reverse);
}

void strafeRightTime(int msc, int vel){
  StrafeAGroup.setVelocity(100, percent);
  StrafeBGroup.setVelocity(100, percent);
  StrafeAGroup.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
}

void strafeRightDis(int inch, int vel){
  StrafeAGroup.setVelocity(100, percent);
  StrafeBGroup.setVelocity(100, percent);
  StrafeAGroup.spinFor(forward, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeBGroup.spinFor(reverse, inch, rotationUnits::deg, vel, velocityUnits::pct);
  StrafeAGroup.stop();
  StrafeBGroup.stop();
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