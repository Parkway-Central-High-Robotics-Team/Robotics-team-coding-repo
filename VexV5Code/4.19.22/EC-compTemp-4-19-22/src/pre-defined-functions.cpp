#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

//** ----------Start of pre defined functions ---------- **//

//** Start of claw functions **//
void claw_back_open_full(void) {
  // Opens the claw back fully
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(forward, 50, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_full(void) {
  // Closes the claw back fully
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(reverse, 50, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_open_deg(int deg) {
  // Opens the claw back the inputed degrees
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(forward, deg, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_close_deg(int deg) {
  // Closes the claw back the inputed degrees
  claw_back.setVelocity(100,percent);
  claw_back.spinFor(reverse, deg, degrees);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}

void claw_back_open_time(int ms) {
  // Opens the claw back the inputed time in milliseconds
  claw_back.setVelocity(100,percent);
  claw_back.spin(forward);
  wait(ms, msec);
  claw_back.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void claw_back_close_time(int ms) {
  // Closes the claw back the inputed time in milliseconds
  claw_back.setVelocity(100,percent);
  claw_back.spin(reverse);
  wait(ms, msec);
  claw_back.stop(hold);
  claw_back.setVelocity(20,percent);
}
//** End of claw functions **//

//** Start of lift functions **//
// Gear ratio is 7:1 //
void lift_front_up(void) {
  // Raises the front lift fully
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(reverse, 100, degrees);
  lift_front.stop(hold);
}

void lift_front_down(void) {
  // Lowers the front lift fully
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(forward, 100, degrees);
  lift_front.stop(hold);
}

void lift_front_up_deg(int deg) {
  // Raises the front the inputed degrees
  lift_front.setVelocity(100,percent);
  lift_front.spinFor(reverse, deg * 7, degrees, true);
  lift_front.stop(hold);
}

void lift_front_down_deg(int deg) {
  // Lowers the front the inputed degrees
  lift_front.setVelocity(100,percent);
  lift_front.spinFor(forward, deg * 7, degrees, true);
  lift_front.stop(hold);
}

void lift_front_up_time(int ms) {
  // Raises the front the inputed time in milliseconds
  lift_front.setVelocity(75,percent);
  lift_front.spin(reverse);
  wait(ms, msec);
  lift_front.stop(hold);
}

void lift_front_down_time(int ms) {
  // Lowers the front the inputed time in milliseconds
  lift_front.setVelocity(75,percent);
  lift_front.spin(forward);
  wait(ms, msec);
  lift_front.stop(hold);
}
//** End of lift functions **// 

//** Start of lift clamp functions **// 
void lift_clamp_open(void) {
  // Opens the front lift clamp fully
  lift_front.setVelocity(75,percent);
  lift_front.spinFor(reverse, 100, degrees);
  lift_front.stop(hold);
}

void lift_clamp_close(void) {
  // Closes the front lift clamp fully
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(forward, 100, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_open_deg(int deg) {
  // Opens the front lift clamp the inputed degrees
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(reverse, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_close_deg(int deg) {
  // Closes the front lift clamp the inputed degrees
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spinFor(forward, deg, degrees);
  lift_clamp.stop(hold);
}

void lift_clamp_open_time(int ms) {
  // Opens the front lift clamp the inputed time in milliseconds
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(reverse);
  wait(ms, msec);
  lift_clamp.stop(hold);
}

void lift_clamp_close_time(int ms) {
  // Closes the front lift clamp the inputed time in milliseconds
  lift_clamp.setVelocity(75,percent);
  lift_clamp.spin(forward);
  wait(ms, msec);
  lift_clamp.stop(hold);
}
//** End of lift clamp functions **// 

//** Start of quick grab functions **// 
void Quick_grab_up_full(void) {
  // Raises the quick grab fully
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(forward, 50, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_full(void) {
  // Lowers the quick grab fully
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(reverse, 50, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_up_deg(int deg) {
  // Raises the quick grab the inputed degrees
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(forward, deg, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_deg(int deg) {
  // Lowers the quick grab the inputed degrees
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spinFor(reverse, deg, degrees);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_up_time(int ms) {
  // Raises the quick grab the inputed time in milliseconds
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spin(reverse);
  wait(ms, msec);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}

void Quick_grab_down_time(int ms) {
  // Lowers the quick grab the inputed time in milliseconds
  Quick_grab.setVelocity(100,percent);
  Quick_grab.spin(forward);
  wait(ms, msec);
  Quick_grab.stop(hold);
  Quick_grab.setVelocity(20,percent);
}
//** End of quick grab functions **// 

//** Start of driver helper functions **// 

// Functions to help the driver with repetitive tasks
void grab_goal_backside(void) {
  // Uses the back claw to grab a goal at the push of the left button
  claw_back_open_time(300);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.drive(reverse);
  wait(500, msec);
  Drivetrain.stop(coast);
  //Drivetrain.driveFor(reverse,9,inches);
  claw_back_close_time(300);
  }


void grab_goal_frontside(void) {
  // Uses the front claw to grab a goal at the push of the right button
  lift_clamp_open_time(400);
  lift_front_down_time(100);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.drive(forward);
  wait(500, msec);
  Drivetrain.stop(coast);
  //Drivetrain.driveFor(forward,9,inches);
  lift_clamp_close_time(750);
}

void lift_goal_on_platform(void) {
  // Uses the front lift to grab the goal, backs up. raises the front lift, drives forward. and deposits the goal on the platform
  Drivetrain.setDriveVelocity(50,percent);
  lift_clamp_open_time(400);
  lift_clamp_close_time(400);
  Drivetrain.driveFor(reverse,4,inches);
  lift_front_up_time(2000);
  //Drivetrain.driveFor(forward,20,inches);
  Drivetrain.drive(forward);
  wait(1000, msec);
  Drivetrain.stop(coast);
  lift_clamp_open_time(350);
}

void lower_lift_from_platform(void) {
  Drivetrain.setDriveVelocity(50,percent);
  lift_front_down_time(200);
  //Drivetrain.driveFor(reverse,9,inches);
  Drivetrain.drive(reverse);
  wait(800, msec);
  Drivetrain.stop(coast);
  lift_clamp_close_time(250);
  lift_front_down_time(1650);
}
//** End of driver helper functions **//

//** ----------End of pre defined functions ---------- **\\