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
// arm                  motor         7               
// liftfront            motor         10  
// liftback             motor         4                                       
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

//start of pre defined functions 

//start of arm functions 
void arms_down_full(void) {
  arm.setVelocity(100,percent);
  arm.spinFor(forward, 50, degrees);
  arm.stop(coast);
  arm.setVelocity(20,percent);
}

void arms_up_full(void) {
  arm.setVelocity(100,percent);
  arm.spinFor(reverse, 50, degrees);
  arm.stop(hold);
  arm.setVelocity(20,percent);
}

void arms_down_deg(int deg) {
  arm.setVelocity(100,percent);
  arm.spinFor(reverse, deg, degrees);
  arm.stop(hold);
  arm.setVelocity(20,percent);
}

void arms_up_deg(int deg) {
  arm.setVelocity(100,percent);
  arm.spinFor(forward, deg, degrees);
  arm.stop(hold);
  arm.setVelocity(20,percent);
}

void arms_down_time(int ms) {
  arm.setVelocity(100,percent);
  arm.spin(reverse);
  wait(ms, msec);
  arm.stop(hold);
  arm.setVelocity(20,percent);
}

void arms_up_time(int ms) {
  arm.setVelocity(100,percent);
  arm.spin(forward);
  wait(ms, msec);
  arm.stop(hold);
  arm.setVelocity(20,percent);
}
//end of arm functions

//begin of front lift functions 
void lift_front_up(void) {
  liftfront.setVelocity(75,percent);
  liftfront.spinFor(forward, 100, degrees);
  liftfront.stop(hold);
}

void lift_front_down(void) {
  liftfront.setVelocity(75,percent);
  liftfront.spinFor(reverse, 100, degrees);
  liftfront.stop(hold);
}

void lift_front_up_deg(int deg) {
  liftfront.setVelocity(75,percent);
  liftfront.spinFor(forward, deg, degrees);
  liftfront.stop(hold);
}

void lift_front_down_deg(int deg) {
  liftfront.setVelocity(75,percent);
  liftfront.spinFor(reverse, deg, degrees);
  liftfront.stop(hold);
}

void lift_front_up_time(int velocity, int ms) {
  liftfront.setVelocity(velocity,percent);
  liftfront.spin(forward);
  wait(ms, msec);
  liftfront.stop(hold);
}

void lift_front_down_time(int velocity, int ms) {
  liftfront.setVelocity(velocity,percent);
  liftfront.spin(reverse);
  wait(ms, msec);
  liftfront.stop(hold);
}
//end of front lift functions 

//begin of back lift functions 
void lift_back_up(void) {
  liftback.setVelocity(75,percent);
  liftback.spinFor(forward, 100, degrees);
  liftback.stop(hold);
}

void lift_back_down(void) {
  liftback.setVelocity(75,percent);
  liftback.spinFor(reverse, 100, degrees);
  liftback.stop(hold);
}

void lift_back_up_deg(int deg) {
  liftback.setVelocity(75,percent);
  liftback.spinFor(forward, deg, degrees);
  liftback.stop(hold);
}

void lift_back_down_deg(int deg) {
  liftback.setVelocity(75,percent);
  liftback.spinFor(reverse, deg, degrees);
  liftback.stop(hold);
}

void lift_back_up_time(int ms) {
  liftback.setVelocity(75,percent);
  liftfront.spin(forward);
  wait(ms, msec);
  liftfront.stop(hold);
}

void lift_back_down_time(int ms) {
  liftback.setVelocity(75,percent);
  liftback.spin(reverse);
  wait(ms, msec);
  liftback.stop(hold);
}
//end of back lift functions 

//begin of lift_clamp functions 
void lift_clamp_up(void) {
  liftback.setVelocity(75,percent);
  liftback.spinFor(forward, 100, degrees);
  liftback.stop(hold);
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

//start of main functions
void autonomousR(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,24,inches);
  lift_front_up_time(100,500);
  Drivetrain.turnFor(left,45,degrees); 
  rightMotorA.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  rightMotorB.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  leftMotorA.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  leftMotorB.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  wait(500, msec);
  arm.spin(vex::directionType::rev, 60, vex::velocityUnits::pct);
  wait(200, msec);
  arm.stop(vex::brakeType::coast);
  wait(680, msec);
  Drivetrain.turnFor(right,45,degrees);
  Drivetrain.driveFor(forward,10,inches);
  arm.spin(vex::directionType::fwd, 60, vex::velocityUnits::pct);
  wait(200, msec);
  arm.stop(hold);
  wait(200, msec);
  Drivetrain.driveFor(reverse,30,inches);
  Drivetrain.turnFor(left,90,degrees);
  arm.stop(coast);
  lift_front_up_time(100,1500);
  
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
  Competition.autonomous(autonomousR);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
