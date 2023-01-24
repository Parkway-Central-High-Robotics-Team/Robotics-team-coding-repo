#pragma once

#include "v5.h"
#include "v5_vcs.h"

void intakeIn(int vel);
void intakeInTime(int msc, int vel);
void intakeInDeg(int deg, int vel);

void intakeStop(void);
void intakeOut(int vel);
void intakeOutTime(int msc, int vel);
void intakeOutDeg(int deg, int vel);

void startFlyWheel(int vel);
void stopFlyWheel(void);

void strafeLeft(int vel);
void strafeLeftTime(int msc, int vel);
void strafeLeftDis(int inch, int vel);

void strafeRight(int vel);
void strafeRightTime(int msc, int vel);
void strafeRightDis(int inch, int vel);

void visionTest(void);
void pneumaticsFunction(void);
void TrackWithLargeFunction(void);
void visionaim(void);

class Thing {
  public:
  void spin(vex::motor mtr, vex::directionType dir, int vel, vex::velocityUnits units) {
    mtr.spin(dir, vel, units);
  }

  void spin(vex::motor_group mtr, vex::directionType dir, int vel, vex::velocityUnits units) {
    mtr.spin(dir, vel, units);
  }

  /*void spinFor(vex::motor mtr, vex::rotationUnits deg, vex::rotationUnits::rotateType, vex::directionType dir, int vel, vex::velocityUnits units){
    mtr.spinFor(dir, deg, rotateType, double velocity, velocityUnits units_v)
  }*/

  void stop(vex::motor mtr, vex::brakeType bktype) {
    mtr.stop(bktype);
  }

  void stop(vex::motor_group mtr, vex::brakeType bktype) {
    mtr.stop(bktype);
  }
};