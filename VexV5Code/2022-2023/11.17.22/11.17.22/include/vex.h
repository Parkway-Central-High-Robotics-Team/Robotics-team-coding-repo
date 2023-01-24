/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#ifndef VEX
#define VEX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "autonomous-functions.h"
#include "pre-defined-functions.h"
//#include "vision.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#endif