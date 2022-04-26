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

  Drivetrain.turnFor(right, 10, degrees);
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

void new_auto_2_goal_works (void) {
  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(100, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(300); //while driving reverse, lowers the quick grab
  Quick_grab.spin(forward);
  wait(50, msec);
  Quick_grab.stop(coast);
  wait(150, msec);
  Drivetrain.stop(coast);
  wait(100, msec);
  Quick_grab.spin(reverse);
  wait(200, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,28,inches);//drives 
  Quick_grab.spin(forward);
  wait(100, msec);
  Quick_grab.stop(coast);
  //wait(500, msec);
  Drivetrain.driveFor(forward,3,inches); 
  Quick_grab_up_time(1000);
  Drivetrain.setDriveVelocity(100,percent);

  Drivetrain.turn(left);
  wait(475, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(625, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(300);

  Drivetrain.driveFor(forward,17,inches);

  //claw_back_open_time(500);
  /*Drivetrain.turn(right);
  wait(800, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(600, msec);
  Quick_grab_down_time(600);
  wait(500, msec);
  Drivetrain.stop(coast);
  Quick_grab_down_time(600);
  Drivetrain.driveFor(forward,42,inches);
  */
  //Drivetrain.driveFor(reverse,20,inches); 
  //claw_back_close_deg(175);
  //Drivetrain.driveFor(forward,21,inches);
}

void new_auto (void) {
  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(100, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(300); //while driving reverse, lowers the quick grab
  Quick_grab.spin(forward);
  wait(50, msec);
  Quick_grab.stop(coast);
  wait(150, msec);
  Drivetrain.stop(coast);
  wait(100, msec);
  Quick_grab.spin(reverse);
  wait(200, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,8,inches);//drives 
  Quick_grab.spin(forward);
  wait(100, msec);
  Quick_grab.stop(coast);
  //wait(500, msec);
  Drivetrain.driveFor(forward,3,inches); 
  //Quick_grab_up_time(1000);
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.stop(coast);

  //Drivetrain.turnFor(right, 90, degrees);
  //Drivetrain.turn(left);
  //Drivetrain.turn(right);
  //wait(465, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse); //drives reverse 
  wait(735, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  //Quick_grab_down_time(500); //while driving reverse, lowers the quick grab
  //wait(100, msec);
  Drivetrain.stop(brake); //stops driving

  wait(250, msec);
  Quick_grab.spin(reverse);
  wait(400, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,30,inches);
  Drivetrain.setDriveVelocity(100,percent);
  wait(1000, msec);
  //Drivetrain.drive(reverse); //drives reverse 
  //wait(100, msec);
  //Drivetrain.stop(brake); //stops driving
  Quick_grab.spin(forward);
  wait(150, msec);
  Quick_grab.stop(coast);
  wait(200, msec);

  //lift_front_up_time(400);
  //lift_clamp_close_time(300);
  //lift_front_down_time(350);

  //wait(500, msec);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,6,inches); 
  Drivetrain.setDriveVelocity(100,percent);
  Quick_grab_up_time(500);

  claw_back_open_time(500);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,12,inches); 
  Drivetrain.setDriveVelocity(100,percent);

  Drivetrain.turn(left);
  wait(485, msec);
  Drivetrain.stop(coast);

  Drivetrain.driveFor(reverse,14,inches);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(reverse,3,inches);
  Drivetrain.setDriveVelocity(100,percent);
  claw_back_close_time(500);

  Drivetrain.turn(right);
  wait(375, msec);
  Drivetrain.stop(coast);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,16,inches);
  Drivetrain.setDriveVelocity(100,percent);

  //lift_clamp_open_time(400);
  //lift_front_down_time(100);
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.drive(forward);
  wait(750, msec);
  Drivetrain.stop(coast);
  //Drivetrain.driveFor(forward,9,inches);
  //lift_clamp_close_time(450);

  //Drivetrain.turnFor(right, 45, degrees);
  Drivetrain.turn(right);
  wait(500, msec);
  Drivetrain.stop(coast);
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.driveFor(forward,10,inches);
  Drivetrain.setDriveVelocity(100,percent);

  /*Drivetrain.turn(right);
  wait(800, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(600, msec);
  Quick_grab_down_time(600);
  wait(500, msec);
  Drivetrain.stop(coast);
  Quick_grab_down_time(600);
  Drivetrain.driveFor(forward,42,inches);
  */
  //Drivetrain.driveFor(reverse,20,inches); 
  //claw_back_close_deg(175);
  //Drivetrain.driveFor(forward,20,inches);
}

//end of auton 