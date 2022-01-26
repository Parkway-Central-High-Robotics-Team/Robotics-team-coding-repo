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
// liftFront            motor         10  Not in use at the moment 
// lift_front             motor         7                           
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
  claw_back.spinFor(forward, deg, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_deg(int deg) {
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(reverse, deg, degrees);
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

//begin of back lift functions 
// gear ratio is 7:1
void lift_front_up(void) {
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(reverse, 100, degrees);
  lift_front.stop(hold);
}

void lift_front_down(void) {
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(forward, 100, degrees);
  lift_front.stop(hold);
}

void lift_front_up_deg(int deg) {
  lift_front.setVelocity(100,percent);
  lift_front.spinFor(reverse, deg * 7, degrees, true);
  lift_front.stop(hold);
}

void lift_front_down_deg(int deg) {
  lift_front.setVelocity(100,percent);
  lift_front.spinFor(forward, deg * 7, degrees, true);
  lift_front.stop(hold);
}

void lift_front_up_time(int ms) {
  lift_front.setVelocity(75,percent);
  lift_front.spin(reverse);
  wait(ms * 7, msec);
  lift_front.stop(hold);
}

void lift_front_down_time(int ms) {
  lift_front.setVelocity(75,percent);
  lift_front.spin(forward);
  wait(ms * 7, msec);
  lift_front.stop(hold);
}
//end of back lift functions 

//begin of lift_clamp functions 
void lift_clamp_open(void) {
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(reverse, 100, degrees);
  lift_front.stop(hold);
}

void lift_clamp_close(void) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(forward, 100, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_open_deg(int deg) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(reverse, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_close_deg(int deg) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(forward, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_open_time(int ms) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(reverse);
  wait(ms, msec);
  lift_clamp.stop(hold);
}

void lift_clamp_close_time(int ms) {
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(forward);
  wait(ms, msec);
  lift_clamp.stop(hold);
}
//end of lift_clamp functions 

//start of auton

void auton_function_test(void) {
  //claw_back_open_full();
  //claw_back_close_full();
  //claw_back_open_time(100);
  //claw_back_close_time(100);
  //claw_back_open_deg(100);
  //claw_back_close_deg(100);

  //lift_front_up();
  //lift_front_down();
  //lift_front_up_deg(100);
  //lift_front_down_deg(100);
  //lift_front_up_time(100);
  //lift_front_down_time(100);

  //lift_clamp_open();
  //lift_clamp_close();
  //lift_clamp_open_deg(100);
  //lift_clamp_close_deg(100);
  //lift_clamp_open_time(100);
  //lift_clamp_close_time(100);

}

void all_corners_1_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(forward,45,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,5,inches);
  claw_back_close_deg(175);
  Drivetrain.driveFor(reverse,30,inches);
}

void blue_right_2_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(forward,45,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,5,inches);
  Drivetrain.setDriveVelocity(75,percent);
  claw_back_close_time(1250);
  //claw_back_close_deg(165);
  lift_front_up_deg(20);
  Drivetrain.turnFor(left, 40, degrees);
  //Drivetrain.turn(left);
  //wait(1000, msec);
  //Drivetrain.stop(coast);
  Drivetrain.driveFor(reverse, 25 ,inches);
  //lift_clamp_close_deg(240);
  lift_clamp_close_time(1000);
  //Drivetrain.turnFor(right, 50, degrees);
  Drivetrain.turn(right);
  wait(1750, msec);
  Drivetrain.stop(coast);
  Drivetrain.driveFor(reverse , 30, inches);
}
//end of auton

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
  blue_right_2_goal();
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
