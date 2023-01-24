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