#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

void flickDisk(void){
  discFlick.spinFor(forward, 155, timeUnits::msec, 100, velocityUnits::pct);
  discFlick.spinFor(reverse, 250, timeUnits::msec, 100, velocityUnits::pct);
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