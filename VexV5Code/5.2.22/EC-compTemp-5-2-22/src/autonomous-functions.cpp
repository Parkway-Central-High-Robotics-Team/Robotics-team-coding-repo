#include "vex.h"
#include "autonomous-functions.h"
using namespace vex;

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
  //turn_left_smooth_deg(360);
  Drivetrain.turnFor(left, 10, degrees);
  Drivetrain.stop(coast);
}

void all_corners_1_goal(void) {
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(reverse,41,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,5,inches);
  claw_back_close_time(500);
  Drivetrain.driveFor(forward,35,inches);
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

void left_side_2_goal_1_ring(void) {
  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(100, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(300); //while driving reverse, lowers the quick grab
  Quick_grab.spin(forward);
  wait(50, msec);
  Quick_grab.stop(coast);
  wait(340, msec);
  Drivetrain.stop(coast);
  wait(100, msec);
  Quick_grab.spin(reverse);
  wait(200, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,33,inches);//drives 
  Quick_grab.spin(forward);
  wait(300, msec);
  Quick_grab.stop(coast);
  wait(300, msec);
  Drivetrain.driveFor(forward,4,inches); 
  Quick_grab_up_time(800);
  Drivetrain.setDriveVelocity(100,percent);

  Drivetrain.turn(right);
  wait(725, msec);
  Drivetrain.stop(coast);

  Drivetrain.drive(reverse);
  wait(400, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(200);

  Drivetrain.driveFor(forward,20,inches);

  claw_back_open_time(200);
  claw_back.stop(coast);
  wait(300, msec);
  Drivetrain.drive(reverse);
  wait(100, msec);
  Drivetrain.stop(coast);
  claw_back_open_time(100);
  wait(300, msec);
  claw_back_close_time(200);
  claw_back.stop(coast);
  wait(300, msec);
  claw_back_open_time(200);
  claw_back_close_time(50);
  claw_back_open_time(50);
  claw_back.stop(coast);
  claw_back_open_time(200);

  //claw_back_close_time(300);
  lift_front_up_time(300);
  lift_clamp_close_time(275);
  lift_front_down_time(300);
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

void right_side_2_goal_1_ring (void) {
  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(100, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(300); //while driving reverse, lowers the quick grab
  Quick_grab.spin(forward);
  wait(50, msec);
  Quick_grab.stop(coast);
  wait(155, msec);
  Drivetrain.stop(coast);
  wait(100, msec);
  Quick_grab.spin(reverse);
  wait(200, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,28,inches);//drives 
  Quick_grab.spin(forward);
  wait(200, msec);
  Quick_grab.stop(coast);
  wait(200, msec);
  Drivetrain.driveFor(forward,4,inches); 
  Quick_grab_up_time(800);
  Drivetrain.setDriveVelocity(100,percent);

  Drivetrain.turn(right);
  wait(475, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(625, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(300);

  Drivetrain.driveFor(forward,17,inches);
  claw_back_open_time(200);
  claw_back.stop(coast);
  wait(300, msec);
  Drivetrain.driveFor(reverse,2,inches);
  claw_back_open_time(100);
  wait(300, msec);
  claw_back_close_time(200);
  claw_back.stop(coast);
  wait(300, msec);
  claw_back_open_time(200);
  lift_clamp_close_time(275);

  claw_back_close_time(300);
  lift_front_up_time(300);
  lift_clamp_close_time(275);
  lift_front_down_time(300);

  
}

void right_side_3_goal_no_ring (void) {

  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(100, msec);

  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(300); //while driving reverse, lowers the quick grab
  Quick_grab.spin(forward);
  wait(50, msec);
  Quick_grab.stop(coast);
  wait(160, msec);
  Drivetrain.stop(coast);

  wait(100, msec);
  Quick_grab.spin(reverse); //hooks the quick grab under the goal and pulls it back 
  wait(200, msec); 
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,8,inches);

  Quick_grab.spin(forward);
  wait(100, msec);
  Quick_grab.stop(coast);
  Drivetrain.setDriveVelocity(20,percent);
  Drivetrain.driveFor(forward,3,inches); // gets the quick grab unhooked from the goal
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.stop(coast);

  Drivetrain.turnFor(left, 41, degrees);
  //Drivetrain.turn(left);
  //wait(475, msec);
  //Drivetrain.stop(coast); // turns right and drives reverse to the center goal
  Drivetrain.drive(reverse); 
  wait(725, msec);
  Drivetrain.stop(brake);

  wait(250, msec);
  Quick_grab.spin(reverse);
  wait(400, msec);
  Drivetrain.setDriveVelocity(50,percent); // hooks the quick grab on the middle goal and pulls it back across the white line 
  Drivetrain.driveFor(forward,31,inches);
  Drivetrain.setDriveVelocity(100,percent);

  wait(100, msec);
  Quick_grab.spin(forward);
  wait(150, msec);
  Quick_grab.stop(coast);
  wait(600, msec);
  Drivetrain.setDriveVelocity(50,percent); // unhooks the quick grab from the middle goal and raises the quick grab
  Drivetrain.driveFor(forward,3,inches); 
  Drivetrain.setDriveVelocity(100,percent);
  Quick_grab_up_time(650);

  claw_back_open_time(300);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,9,inches); 
  Drivetrain.setDriveVelocity(100,percent); // drives reverse and turns to get inline with the first yellow goal
  Drivetrain.turn(right);
  wait(550, msec);
  Drivetrain.stop(coast);

  Drivetrain.driveFor(reverse,15,inches);
  Drivetrain.setDriveVelocity(20,percent); // dives reverse and clamps the 1st yellow goal
  Drivetrain.driveFor(reverse,3,inches);
  Drivetrain.setDriveVelocity(100,percent);
  claw_back_close_time(300);
  lift_front_up_time(300);
  lift_clamp_close_time(275);

  Drivetrain.setDriveVelocity(100,percent); 

  //Drivetrain.turnFor(left, 45, degrees);
  Drivetrain.turn(left);
  wait(700, msec);
  Drivetrain.stop(coast);
  lift_front_down_time(300);
  Drivetrain.setDriveVelocity(100,percent); // turns right for the front lift to be inline with the alliance goal and drives forward
  //Drivetrain.driveFor(forward,18,inches);
  //Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.drive(forward); //drives reverse 
  wait(900, msec);
  Drivetrain.stop(coast);
  lift_clamp_close_time(75);
  Drivetrain.turn(right);
  wait(200, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(forward); //drives reverse 
  wait(150, msec);
  Drivetrain.stop(coast);

  /*Drivetrain.turn(right);
  wait(500, msec);
  Drivetrain.stop(coast);
  Drivetrain.setDriveVelocity(100,percent); // drives forward and bumps the alliance goal off the white line 
  Drivetrain.drive(forward);
  wait(850, msec);
  Drivetrain.stop(coast);
  lift_clamp_open_time(250);*/
}

//end of auton 