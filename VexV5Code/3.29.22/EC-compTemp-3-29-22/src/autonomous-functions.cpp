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
  wait(425, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(475); //while driving reverse, lowers the quick grab
  //wait(100, msec);
  Drivetrain.stop(brake); //stops driving
  wait(350, msec);
  Quick_grab_down_time(100);
  Drivetrain.driveFor(forward,32,inches);//drives 
  Drivetrain.setDriveVelocity(25,percent);
  wait(500, msec);
  Drivetrain.driveFor(forward,2,inches);
  Quick_grab_up_time(1000);
  Drivetrain.setDriveVelocity(100,percent);

  Drivetrain.turn(left);
  wait(500, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse);
  wait(550, msec);
  Drivetrain.stop(coast);
  claw_back_close_time(500);

  Drivetrain.driveFor(forward,17,inches);

  claw_back_open_time(500);
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

void new_auto (void) {
  Drivetrain.setDriveVelocity(100,percent);
  claw_back.stop(hold);
  Drivetrain.drive(reverse); //drives reverse 
  wait(435, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(400); //while driving reverse, lowers the quick grab
  //wait(100, msec);
  Drivetrain.stop(brake); //stops driving
  wait(200, msec);
  //Drivetrain.driveFor(forward,32,inches);//drives 
  Drivetrain.driveFor(forward,10,inches);//drives 
  Drivetrain.setDriveVelocity(25,percent);
  wait(500, msec);
  Drivetrain.driveFor(forward,2,inches);
  Quick_grab_up_time(1000);
  Drivetrain.setDriveVelocity(100,percent);

  //Drivetrain.turn(left);
  Drivetrain.turn(right);
  wait(345, msec);
  Drivetrain.stop(coast);
  Drivetrain.drive(reverse); //drives reverse 
  wait(275, msec);
  //Drivetrain.driveFor(reverse,29,inches);
  Quick_grab_down_time(550); //while driving reverse, lowers the quick grab
  //wait(100, msec);
  Drivetrain.stop(brake); //stops driving
  wait(250, msec);
  Quick_grab_down_time(50);
  Drivetrain.driveFor(forward,10,inches);
  Quick_grab_up_time(1000);

  claw_back_open_time(500);
  Drivetrain.driveFor(reverse,20,inches);
  claw_back_close_time(500);
  Drivetrain.turn(left);
  wait(500, msec);
  Drivetrain.stop(coast);

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