/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 3, 8, 9, 11  
// Controller1          controller                    
// DrivetrainInertial   inertial      11
// leftMotorA           motor         2
// leftMotorB           motor         3
// rightMotorA          motor         8
// rightMotorB          motor         9
// liftFront            motor         10  
// liftBack             motor         7                           
// claw_back            motor         6               
// lift_clamp           motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

//start of pre defined functions 

//start of claw functions 
void claw_back_open_full(void) {
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(forward, 50, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_full(void) {
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(reverse, 50, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_open_deg(int deg) {
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(reverse, deg, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_deg(int deg) {
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(forward, deg, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_time(int ms) {
  claw_back.setVelocity(100,percent);
  claw_back.spin(reverse);
  wait(ms, msec);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_open_time(int ms) {
  claw_back.setVelocity(100,percent);
  claw_back.spin(forward);
  wait(ms, msec);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}
//end of arm functions

//begin of front lift functions 
void lift_front_up(void) {
  liftFront.setVelocity(75,percent);
  liftFront.spinFor(forward, 100, degrees);
  liftFront.stop(hold);
}

void lift_front_down(void) {
  liftFront.setVelocity(75,percent);
  liftFront.spinFor(reverse, 100, degrees);
  liftFront.stop(hold);
}

void lift_front_up_deg(int deg) {
  liftFront.setVelocity(75,percent);
  liftFront.spinFor(forward, deg, degrees);
  liftFront.stop(hold);
}

void lift_front_down_deg(int deg) {
  liftFront.setVelocity(75,percent);
  liftFront.spinFor(reverse, deg, degrees);
  liftFront.stop(hold);
}

void lift_front_up_time(int ms) {
  liftFront.setVelocity(75,percent);
  liftFront.spin(forward);
  wait(ms, msec);
  liftFront.stop(hold);
}

void lift_front_down_time(int ms) {
  liftFront.setVelocity(75,percent);
  liftFront.spin(reverse);
  wait(ms, msec);
  liftFront.stop(hold);
}
//end of front lift functions 

//begin of back lift functions 
void lift_back_up(void) {
  liftBack.setVelocity(75,percent);
  liftBack.spinFor(forward, 100, degrees);
  liftBack.stop(hold);
}

void lift_back_down(void) {
  liftBack.setVelocity(75,percent);
  liftBack.spinFor(reverse, 100, degrees);
  liftBack.stop(hold);
}

void lift_back_up_deg(int deg) {
  liftBack.setVelocity(75,percent);
  liftBack.spinFor(forward, deg, degrees);
  liftBack.stop(hold);
}

void lift_back_down_deg(int deg) {
  liftBack.setVelocity(75,percent);
  liftBack.spinFor(reverse, deg, degrees);
  liftBack.stop(hold);
}

void lift_back_up_time(int ms) {
  liftBack.setVelocity(75,percent);
  liftFront.spin(forward);
  wait(ms, msec);
  liftFront.stop(hold);
}

void lift_back_down_time(int ms) {
  liftBack.setVelocity(75,percent);
  liftBack.spin(reverse);
  wait(ms, msec);
  liftBack.stop(hold);
}
//end of back lift functions 

//begin of lift_clamp functions 
void lift_clamp_up(void) {
  liftBack.setVelocity(75,percent);
  liftBack.spinFor(forward, 100, degrees);
  liftBack.stop(hold);
}

void lift_clamp_down(void) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(reverse, 100, degrees);
  lift_clamp.stop(hold);
}

void llift_clamp_up_deg(int deg) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(forward, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_down_deg(int deg) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(reverse, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_up_time(int ms) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(forward);
  wait(ms, msec);
  lift_clamp.stop(hold);
}

void lift_clamp_down_time(int ms) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(reverse);
  wait(ms, msec);
  lift_clamp.stop(hold);
}
//end of lift_clamp functions 

//start of pre defined functions 
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,24,inches);
  claw_back_close_deg(100);
  Drivetrain.driveFor(reverse,24,inches);
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
