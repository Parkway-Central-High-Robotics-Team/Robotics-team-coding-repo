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
// Quick_grab           motor         10
// lift_front           motor         7                           
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
  Quick_grab.setVelocity(20,percent);
}
//end of claw functions

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

// start of Quick grab functions

void Quick_grab_up_full(void) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(forward, 50, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_full(void) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(reverse, 50, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_up_deg(int deg) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(forward, deg, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_deg(int deg) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(reverse, deg, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_up_time(int ms) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spin(reverse);
  wait(ms, msec);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_time(int ms) {
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spin(forward);
  wait(ms, msec);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

// end of quick grab functions 

// start of driver control functions 

void grab_goal_backside(void) {
  claw_back_open_time(150);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,9,inches);
  claw_back_close_time(500);
}

void grab_goal_frontside(void) {
  
  lift_front_up_time(500);
  lift_clamp_open_time(500);
  lift_front_down_time(500);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,7,inches);
  lift_clamp_close_time(750);
}

// end of driver control functions 

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
  Drivetrain.driveFor(reverse,45,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  claw_back_close_deg(175);
  Drivetrain.driveFor(forward,30,inches);
}

void blue_right_2_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(reverse,45,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.setDriveVelocity(75,percent);
  claw_back_close_time(1000);
  //claw_back_close_deg(165);
  lift_front_up_deg(20);
  //Drivetrain.turnFor(right, 40, degrees);
  Drivetrain.turn(right);
  wait(750, msec);
  Drivetrain.stop(coast);
  Drivetrain.driveFor(forward, 25 ,inches);
  //lift_clamp_close_deg(240);
  lift_clamp_close_time(1000);
  //Drivetrain.turnFor(right, 50, degrees);
  Drivetrain.turn(left);
  wait(1750, msec);
  Drivetrain.stop(coast);
  Drivetrain.driveFor(forward , 30, inches);
}

void blue_left_2_goal(void) {
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(reverse, 45, inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.setDriveVelocity(100,percent);
  claw_back_close_time(500);
  Drivetrain.driveFor(forward, 41, inches);
  Drivetrain.turn(right);
  wait(1550, msec);
  Drivetrain.stop(coast);
  lift_front_up_deg(20);
  //Drivetrain.driveFor(forward, 5 ,inches);
  Drivetrain.drive(forward);
  wait(800, msec);
  Drivetrain.stop(coast);
  lift_clamp_close_time(1000);
  //Drivetrain.driveFor(forward, 10 ,inches);
  Drivetrain.drive(forward);
  wait(250, msec);
  Drivetrain.stop(coast);
  lift_clamp_open_time(750);
  Drivetrain.drive(reverse);
  wait(500, msec);
  Drivetrain.stop(coast);
}

void red_right_2_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(reverse,45,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.setDriveVelocity(75,percent);
  claw_back_close_time(1000);
  //claw_back_close_deg(165);
  lift_front_up_deg(20);
  //Drivetrain.turnFor(right, 40, degrees);
  Drivetrain.turn(right);
  wait(750, msec);
  Drivetrain.stop(coast);
  Drivetrain.driveFor(forward, 25 ,inches);
  //lift_clamp_close_deg(240);
  lift_clamp_close_time(1000);
  //Drivetrain.turnFor(right, 50, degrees);
  Drivetrain.turn(left);
  wait(1750, msec);
  Drivetrain.stop(coast);
  Drivetrain.driveFor(forward , 30, inches);
}

void red_left_2_goal(void) {
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(reverse, 45, inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.setDriveVelocity(100,percent);
  claw_back_close_time(500);
  Drivetrain.driveFor(forward, 41, inches);
  Drivetrain.turn(right);
  wait(1550, msec);
  Drivetrain.stop(coast);
  lift_front_up_deg(20);
  //Drivetrain.driveFor(forward, 5 ,inches);
  Drivetrain.drive(forward);
  wait(800, msec);
  Drivetrain.stop(coast);
  lift_clamp_close_time(1000);
  //Drivetrain.driveFor(forward, 10 ,inches);
  Drivetrain.drive(forward);
  wait(250, msec);
  Drivetrain.stop(coast);
  lift_clamp_open_time(750);
  Drivetrain.drive(reverse);
  wait(500, msec);
  Drivetrain.stop(coast);
}

void new_auto_og (void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(reverse,32,inches);
  Quick_grab_down_time(600);
  Drivetrain.driveFor(forward,32,inches);
  Quick_grab_up_time(1000);
  Drivetrain.turn(left);
  wait(360, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(600, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(500);
  Drivetrain.driveFor(forward,20,inches);
}

void new_auto (void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.drive(reverse); //drives reverse 
  wait(485, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(600); //while driving reverse, lowers the quick grab
  //wait(100, msec);
  Drivetrain.stop(brake); //stops driving
  Drivetrain.driveFor(forward,36,inches);//drives 
  Quick_grab_up_time(1000);
  Drivetrain.turn(left);
  wait(425, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(500, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(500);
  Drivetrain.driveFor(forward,17,inches);

  claw_back_open_time(500);
  Drivetrain.turn(right);
  wait(750, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(500, msec);
  Quick_grab_down_time(600);
  wait(500, msec);
  Drivetrain.stop(coast);
  Quick_grab_down_time(600);
  Drivetrain.driveFor(forward,42,inches);

  //Drivetrain.driveFor(reverse,20,inches); 
  //claw_back_close_deg(175);
  //Drivetrain.driveFor(forward,20,inches);
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
  new_auto();
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
    /*bool Controller1LeftShoulderControlMotorsStopped = true;
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    if (Controller1.ButtonLeft.pressing()) {
        grab_goal_backside();
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonRight.pressing()) {
        grab_goal_frontside();
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Drivetrain.stop(coast);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }*/
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