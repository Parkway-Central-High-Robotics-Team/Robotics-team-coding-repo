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
  Drivetrain.drive(forward, 100, velocityUnits::pct);
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
  intakeOutTime(150, 100);
  indexer.setVelocity(100, velocityUnits::pct);
  wait(100, timeUnits::msec);
  indexer.spinFor(forward, 200, rotationUnits::deg);
  indexer.setBrake(brake);
  intakeInTime(2000, 100);
  indexer.spinFor(reverse, 250, timeUnits::msec);
}

void indexerUp(void){
  indexer.spinFor(forward, 400, timeUnits::msec);
}

void indexerFireAuton(void){
  intakeOutTime(100, 100);
  indexer.setVelocity(100, velocityUnits::pct);
  wait(100, timeUnits::msec);
  indexer.spinFor(forward, 100, rotationUnits::deg);
  indexer.setBrake(brake);
  intakeInTime(600, 100);
  wait(500, timeUnits::msec);
  intakeInTime(1000, 100);
  //indexer.spinFor(reverse, 250, timeUnits::msec);
}

void indexerFireSkills(){
  intakeOutTime(150, 100);
  indexer.setVelocity(100, velocityUnits::pct);
  wait(100, timeUnits::msec);
  indexer.spinFor(forward, 175, rotationUnits::deg);
  indexer.setBrake(brake);
  intakeInTime(2000, 100);
  indexer.spinFor(reverse, 250, timeUnits::msec);
}

void flywheel(int vel){
  spinMtrs.spin(forward, vel, velocityUnits::pct);
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

  void startIntake(void){
    intake.spin(forward, 100, velocityUnits::pct);
  }

  void stopIntake(void){
    intake.stop(coast);
  }

  void indexerDown(void){
    indexer.spinFor(reverse, 400, timeUnits::msec);
  }

  void testInertial(void){
    DrivetrainInertial.startCalibration();
    while(DrivetrainInertial.isCalibrating()){
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("calibrating");
    }
    
  }

 //////////////////////////////////////////////////////////
/*void PID(void){
  bool enableDrivePID = true;
  double kP = 0.0;
  double kI = 0.0;
  double kD = 0.0;
  int desiredValue = 200;
  double motorPower = 0;

  int error;
  int prevError = 0;
  int derivative ;
  int totalError = 0;

  while(enableDrivePID==true){
    int leftMotorPosition = LeftDriveSmart.position(degrees);
    int rightMotorPosition = RightDriveSmart.position(degrees);
    int averagePosition = (leftMotorPosition+rightMotorPosition)/2;

    error = averagePosition - desiredValue; //proportional value

    derivative = error - prevError; //derivative value

    totalError += error; //integral value

    motorPower = (error*kP + totalError*kI + derivative*kD);

    
    prevError = error;
    vex::task::sleep(20);
  }
}*/



/*bool enableDrivePID = true;
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;
int desiredValue = 200;
double motorPower = 0;

int error;
int prevError = 0;
int derivative ;
int totalError = 0;


int drivePID(){
  while(enableDrivePID==true){
    int leftMotorPosition = LeftDriveSmart.position(degrees);
    int rightMotorPosition = RightDriveSmart.position(degrees);
    int averagePosition = (leftMotorPosition+rightMotorPosition)/2;

    error = averagePosition - desiredValue; //proportional value

    derivative = error - prevError; //derivative value

    totalError += error; //integral value

    motorPower = (error*kP + totalError*kI + derivative*kD);

    
    prevError = error;
    vex::task::sleep(20);
  }

  return 1;
}*/

double returnPID(void){
  return 0.0;
}

void setTimeout(std::function<void()> func, int milli) {
  this_thread::sleep_for(std::chrono::milliseconds(milli));
  func();
}