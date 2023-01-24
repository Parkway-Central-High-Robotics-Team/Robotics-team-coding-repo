#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "v5.h"
#include "v5_vcs.h"

void flickDisk(void);

void strafeLeft(int vel);
void strafeLeftTime(int msc, int vel);
void strafeLeftDis(int inch, int vel);

void strafeRight(int vel);
void strafeRightTime(int msc, int vel);
void strafeRightDis(int inch, int vel);

void intakeIn(int vel);
void intakeInTime(int msc, int vel);
void intakeInDeg(int deg, int vel);

void intakeOut(int vel);
void intakeOutTime(int msc, int vel);
void intakeOutDeg(int deg, int vel);

void startFlyWheel(int vel);
void stopFlyWheel(void);

