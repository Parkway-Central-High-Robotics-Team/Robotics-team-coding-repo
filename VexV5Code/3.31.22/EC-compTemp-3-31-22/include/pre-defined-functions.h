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

//** Start of global functions **\\
//void RightDriveSmart(void);
//void LeftDriveSmart(void);

// Start of global claw back functions
void claw_back_open_full(void);
void claw_back_close_full(void);
void claw_back_open_deg(int deg);
void claw_back_close_deg(int deg);
void claw_back_open_time(int ms);
void claw_back_close_time(int ms);
// End of global claw back functions

// Start of global lift front functions
void lift_front_up(void);
void lift_front_down(void);
void lift_front_up_deg(int deg);
void lift_front_down_deg(int deg);
void lift_front_up_time(int ms);
void lift_front_down_time(int ms);
// End of global lift front functions

// Start of global clamp functions
void lift_clamp_open(void);
void lift_clamp_close(void);
void lift_clamp_open_deg(int deg);
void lift_clamp_close_deg(int deg);
void lift_clamp_open_time(int ms);
void lift_clamp_close_time(int ms);
// End of global clamp functions

// Start of global quick grab functions
void Quick_grab_up_full(void);
void Quick_grab_down_full(void);
void Quick_grab_up_deg(int deg);
void Quick_grab_down_deg(int deg);
void Quick_grab_up_time(int ms);
void Quick_grab_down_time(int ms);
// End of global quick grab functions

// Start of global helper functions
void grab_goal_backside(void);
void grab_goal_frontside(void);
void lift_goal_on_platform(void);
void lower_lift_from_platform(void);
// End of global helper functions

//** End of global functions **\\
#endif