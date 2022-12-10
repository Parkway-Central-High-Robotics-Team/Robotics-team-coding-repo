#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;
void moveForward(int x){
  Drivetrain.drive(fwd, 100, velocityUnits::pct);
  wait(x, timeUnits::msec);
  Drivetrain.stop(brake);
  //wait(milliseconds, timeUnits::msec);
  
}

void moveBackward(int x){
  Drivetrain.drive(reverse, 100, velocityUnits::pct);
  wait(x, timeUnits::msec);
  Drivetrain.stop(brake);
}
  

void turnRight(int x){
  Drivetrain.turn(right);
  wait(x, timeUnits::msec);
  Drivetrain.stop(brake);
}

void turnLeft(int x){
  Drivetrain.turn(left);
  wait(x, timeUnits::msec);
  Drivetrain.stop(brake);
}

void expansion(void){
  //enter in pneumatic code from "pneumaticstestv3"
  Pneumatics.set(false);
  if(Pneumatics.value() == 0){
      Pneumatics.set(true);
      Brain.Screen.print("L1 is Pressing");
    }


}

void roller(int x){
  intake.spinFor(forward, x, timeUnits::msec, 100, velocityUnits::pct);
 
}


void auton_function_test(void) {
  //roller first
  roller(500);
  //wait(100, timeUnits::msec);
  // go forward, turn right, move backward
  moveForward(600);
  turnRight(1500);
  moveBackward(780);
  roller(500);
  moveForward(500);
  turnRight(3500);



  
  /*turnRight(1000);
  moveBackward(1000);
  // roller 
  //turn right until parallel with divison
  turnRight(1000);
  //move forward to top left roller
  moveForward(1000);
  //turn left
  turnLeft(1000);
  //roller
  //move backward, turn right
  moveBackward(1000);
  turnRight(1000);
  // roller
  //move out and expand
  */

}

void auton_skills(void){

}

void regular_auton(void) {
  intake.spinFor(forward, 15, rotationUnits::deg, 15, velocityUnits::pct);
  Drivetrain.driveFor(forward, 5, distanceUnits::in, 50, velocityUnits::pct);
  Drivetrain.turnFor(right, 120, rotationUnits::deg, 50, velocityUnits::pct);
  Drivetrain.driveFor(forward, 50, distanceUnits::in, 50, velocityUnits::pct);
  startFlyWheel(100);
  Drivetrain.turnFor(right, 90, rotationUnits::deg, 50, velocityUnits::pct);
  intakeIn(100);
  wait(3000, msec);
  intakeStop();
  stopFlyWheel();
}