#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

//** ----------Start of pre defined functions ---------- **//

//** Start of claw functions **//
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
//** End of claw functions **//

//** Start of lift functions **//
// Gear ratio is 7:1 //
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
  wait(ms, msec);
  lift_front.stop(hold);
}

void lift_front_down_time(int ms) {
  lift_front.setVelocity(75,percent);
  lift_front.spin(forward);
  wait(ms, msec);
  lift_front.stop(hold);
}
//** End of lift functions **// 

//** Start of lift clamp functions **// 
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
//** End of lift clamp functions **// 

//** Start of quick grab functions **// 
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
//** End of quick grab functions **// 

//** Start of driver helper functions **// 
void grab_goal_backside(void) {
  claw_back_open_time(150);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,9,inches);
  claw_back_close_time(300);
  }


void grab_goal_frontside(void) {
  
  lift_clamp_open_time(150);
  lift_front_down_time(100);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,9,inches);
  lift_clamp_close_time(750);
}
//** End of driver helper functions **//

//** ----------End of pre defined functions ---------- **\\