#pragma once

#include "v5.h"
#include "v5_vcs.h"
////////////////////
extern int side;
extern int redSide;
extern int blueSide;
////////////////////
void intakeIn(int vel);
void intakeInTime(int msc, int vel);
void intakeInDeg(int deg, int vel);
////////////////////
void intakeStop(void);
void intakeOut(int vel);
void intakeOutTime(int msc, int vel);
void intakeOutDeg(int deg, int vel);
////////////////////
void startFlyWheel(int vel);
void stopFlyWheel(void);
////////////////////
void visionTest(void);
void pneumaticsFunction(void);
////////////////////
void visionTurn(void);
void opticalFunction(void);
////////////////////
void moveForwardTime(int msc);
void moveForwardTime(int msc, int vel);
void moveForwardTime(int msc, int vel, vex::brakeType bt);
////////////////////
void moveBackwardTime(int msc);
void moveBackwardTime(int msc, int vel);
void moveBackwardTime(int msc, int vel, vex::brakeType bt);
////////////////////
void turnRightTime(int msc);
void turnRightTime(int msc, int vel);
void turnRightTime(int msc, int vel, vex::brakeType bt);
////////////////////
void turnLeftTime(int msc);
void turnLeftTime(int msc, int vel);
void turnLeftTime(int msc, int vel, vex::brakeType bt);
////////////////////
void rollerTime(int msc);
void rollerTime(int msc, int vel);
void indexerUp(void);
void expansion(void);
void indexerFire(void);
void flywheel(int vel);
////////////////////
void indexerFireAuton(void);
void startIntake(void);
void stopIntake(void);
void indexerDown(void);
void testInertial(void);
////////////////////
