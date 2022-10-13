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
void auton_function_test(void);         // Test the autonomus functions to see if they work
void all_corners_1_goal(void);          // An old autonomus that works for all corners/robot starting positions
void blue_right_2_goal(void);           // An old autonomus that grabs 2 goals for the blue right side 
void blue_left_2_goal(void);            // An old autonomus that grabs 2 goals for the blue left side 
void red_right_2_goal(void);            // An old autonomus that grabs 2 goals for the red right side 
void left_side_2_goal_1_ring(void);     // An autonomus that grabs 2 goals and puts a ring in the blue goal for the left side
void new_auto_og (void);                // A new autonomus backup for new_auto
void right_side_2_goal_1_ring (void);   // An autonomus that grabs 2 goals and puts a ring in the blue goal for the right side
void right_side_3_goal_1_ring (void);   // A new autonomus that utilizes the quick grab to get 3 goals and puts a ring in the blue goal for the right side
// End of global autonomous functions

//** End of global functions **\\