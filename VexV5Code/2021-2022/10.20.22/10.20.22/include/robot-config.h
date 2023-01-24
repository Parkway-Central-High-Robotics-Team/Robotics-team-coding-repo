#pragma once
using namespace vex;

#include "v5.h"

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern vision Vision;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern inertial DrivetrainInertial;
extern motor intake;
extern motor spinMtr1;
extern motor spinMtr2;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA; 
extern motor rightMotorB; 
extern motor Quick_grab;
extern motor lift_front;
extern motor claw_back;
extern motor lift_clamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );