#pragma once

#include "v5.h"
#include "v5_vcs.h"

void flickDisk(void);

void intakeIn(int vel);
void intakeInTime(int msc, int vel);
void intakeInDeg(int deg, int vel);

void intakeOut(int vel);
void intakeOutTime(int msc, int vel);
void intakeOutDeg(int deg, int vel);

void startFlyWheel(int vel);
void stopFlyWheel(void);