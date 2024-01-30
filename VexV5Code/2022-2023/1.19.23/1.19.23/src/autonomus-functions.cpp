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
  intake.spinFor(reverse, x, timeUnits::msec, 100, velocityUnits::pct);
 
}




void auton_function_test(void) {
  //roller first
  roller(500);
  //wait(100, timeUnits::msec);
  // go forward, turn right, move backward
    


  
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
  roller(250);
  //expansion(); 
}

void regular_auton(void) {
  
}

void roller2(void){
  roller(250);
}