#include "vex.h"
#include "pre-defined-functions.h"
using namespace vex;

void intakeStop(void) {
  intake.stop();
}

void intakeIn(int vel){
  intake.spin(forward, vel, velocityUnits::pct);
}

void intakeInTime(int msc, int vel){
  intake.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
  intake.stop();
}

void intakeInDeg(int deg, int vel){
  intake.spinFor(forward, deg, rotationUnits::deg, vel, velocityUnits::pct);
  intake.stop();
}

void intakeOut(int vel){
  intake.spin(reverse, vel, velocityUnits::pct);
}

void intakeOutTime(int msc, int vel){
  intake.spinFor(reverse, msc, timeUnits::msec, vel, velocityUnits::pct);
  intake.stop();
}

void intakeOutDeg(int deg, int vel){
  intake.spinFor(reverse, deg, rotationUnits::deg, vel, velocityUnits::pct);
  intake.stop();
}

void startFlyWheel(int vel){
  spinMtrs.spin(forward, vel, velocityUnits::pct);
}

void stopFlyWheel(void){
  spinMtrs.stop();
}

void pneumaticsFunction(void){
  // NEEDS TO BE SET TO FALSE IN GLOBAL CODESPACE 
  Pneumatics.set(false);
    if(Pneumatics.value() == 0){
      Pneumatics.set(true);
      Brain.Screen.print("L1 is Pressing");
    }else if(Pneumatics.value() == 1){
     Pneumatics.set(false);
     Brain.Screen.print("L2 is Pressing");
  }
}

void opticalFunction(){
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Optical2.setLight(ledState::on);
  Optical2.setLightPower(50,percent);

  if (Optical2.isNearObject()){
    Brain.Screen.print("Object Detected");
    Brain.Screen.newLine();

    Brain.Screen.print("Brightness: ");
    Brain.Screen.print("%.2f", Optical2.brightness());
    Brain.Screen.newLine();

    Brain.Screen.print("Hue: ");
    Brain.Screen.print("%.2f", Optical2.hue());
    Brain.Screen.newLine();
    if(side == redSide){
      if(Optical2.color() == blue){
        intake.stop(brakeType::hold);
      }else {
        intake.spin(forward, 15, velocityUnits::pct);
      }
    }else if (side == blueSide) {
      if(Optical2.color() == red){
        intake.stop(brakeType::hold);
      }else {
        intake.spin(forward, 15, velocityUnits::pct);
      }
    }
  }
}

void moveForwardTime(int msc){
  Drivetrain.drive(reverse, 75, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
  //wait(milliseconds, timeUnits::msec);
}

void moveForwardTime(int msc, int vel){
  Drivetrain.drive(reverse, vel, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
  //wait(milliseconds, timeUnits::msec);
}

void moveForwardTime(int msc, int vel, vex::brakeType bt){
  Drivetrain.drive(reverse, vel, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(bt);
  //wait(milliseconds, timeUnits::msec);
}

////////////////////////////////////////////////////////////

void moveBackwardTime(int msc){
  Drivetrain.drive(forward, 65, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void moveBackwardTime(int msc, int vel){
  Drivetrain.drive(forward, vel, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void moveBackwardTime(int msc, int vel, vex::brakeType bt){
  Drivetrain.drive(forward, vel, velocityUnits::pct);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(bt);
}

/////////////////////////////////////////////////////////
  

void turnRightTime(int msc){
  Drivetrain.setTurnVelocity(75, velocityUnits::pct);
  Drivetrain.turn(right);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void turnRightTime(int msc, int vel){
  Drivetrain.setTurnVelocity(vel, velocityUnits::pct);
  Drivetrain.turn(right);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void turnRightTime(int msc, int vel, vex::brakeType bt){
  Drivetrain.setTurnVelocity(vel, velocityUnits::pct);
  Drivetrain.turn(right);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(bt);
}

/////////////////////////////////////////////////////

void turnLeftTime(int msc){
  Drivetrain.setTurnVelocity(75, velocityUnits::pct);
  Drivetrain.turn(left);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void turnLeftTime(int msc, int vel){
  Drivetrain.setTurnVelocity(vel, velocityUnits::pct);
  Drivetrain.turn(left);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(brake);
}

void turnLeftTime(int msc, int vel, vex::brakeType bt){
  Drivetrain.setTurnVelocity(vel, velocityUnits::pct);
  Drivetrain.turn(left);
  wait(msc, timeUnits::msec);
  Drivetrain.stop(bt);
}

/////////////////////////////////////////////////////

void rollerTime(int msc){
  intake.spinFor(forward, msc, timeUnits::msec, 100, velocityUnits::pct);
}

void rollerTime(int msc, int vel){
  intake.spinFor(forward, msc, timeUnits::msec, vel, velocityUnits::pct);
}

/////////////////////////////////////////////////////

void expansion(void){
  //enter in pneumatic code from "pneumaticstestv3"
  Pneumatics.set(false);
  if(Pneumatics.value() == 0){
      Pneumatics.set(true);
      Brain.Screen.print("L1 is Pressing");
    }
}

/////////////////////////////////////////////////////

void indexerFire(void){
  intakeOutTime(350, 100);
  indexer.setVelocity(100, velocityUnits::pct);
  wait(100, timeUnits::msec);
  indexer.spinFor(forward, 100, rotationUnits::deg);
  indexer.setBrake(brake);
  intakeInTime(3000, 100);
  indexer.spinFor(reverse, 250, timeUnits::msec);
}

/////////////////////////////////////////////////////
  /*if (Optical2.isNearObject()) {
    Brain.Screen.print("Object Detected");
    Brain.Screen.newLine();
    
    Brain.Screen.print("Brightness: ");
    Brain.Screen.print("%.2f", Optical2.brightness());
    Brain.Screen.newLine();

    Brain.Screen.print("Hue: ");
    Brain.Screen.print("%.2f", Optical2.hue());
    Brain.Screen.newLine();

    Brain.Screen.print("Detects a red object?: ");
    Brain.Screen.print("%s", Optical2.color() == red ? "TRUE" : "FALSE");
    Brain.Screen.newLine();

    Brain.Screen.print("Detects a blue object?: ");
    Brain.Screen.print("%s", Optical2.color() == blue ? "TRUE" : "FALSE");
    Brain.Screen.newLine();
  } else {
    Brain.Screen.print("No Object Detected");
  }*/

  //Optical2.setLight(ledState::off);