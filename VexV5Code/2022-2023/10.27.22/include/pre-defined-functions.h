//#ifndef PRE_DEFINED_FUNCTIONS
//#define PRE_DEFINED_FUNCTIONS
#pragma once
using namespace vex;

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