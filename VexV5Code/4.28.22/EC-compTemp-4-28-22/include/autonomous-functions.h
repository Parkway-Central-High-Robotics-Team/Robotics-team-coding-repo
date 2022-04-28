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

// Start of global autonomous functions
void auton_function_test(void);   // Test the autonomus functions to see if they work
void all_corners_1_goal(void);    // An old autonomus that works for all corners/robot starting positions
void blue_right_2_goal(void);     // An old autonomus that grabs 2 goals for the blue right side 
void blue_left_2_goal(void);      // An old autonomus that grabs 2 goals for the blue left side 
void red_right_2_goal(void);      // An old autonomus that grabs 2 goals for the red right side 
void red_left_2_goal(void);       // An old autonomus that grabs 2 goals for the red left side
void new_auto_og (void);          // A new autonomus backup for new_auto
void new_auto_2_goal_works(void); // The main autonomus that we use to grab 2 goals 
void right_side_3_goal_no_ring (void);             // A new autonomus that utilizes the quick grab to get 3 goals
// End of global autonomous functions

//** End of global functions **\\