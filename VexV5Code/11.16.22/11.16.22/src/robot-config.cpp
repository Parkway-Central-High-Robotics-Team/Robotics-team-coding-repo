#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// VEXcode device constructors
// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
motor leftMotorA = motor(PORT8, ratio18_1, false);
motor leftMotorB = motor(PORT9, ratio18_1, false);
motor rightMotorA = motor(PORT3, ratio18_1, true);
motor rightMotorB = motor(PORT4, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 177.79999999999998, mm, 1);
motor_group StrafeAGroup = motor_group(leftMotorA, rightMotorB);
motor_group StrafeBGroup = motor_group(leftMotorB, rightMotorA);
inertial DrivetrainInertial = inertial(PORT11);
controller Controller1 = controller(primary);
motor intake = motor(PORT20, ratio18_1, false);
motor spinMtr1 = motor(PORT12, ratio18_1, true);
motor spinMtr2 = motor(PORT13, ratio18_1, false);
motor_group spinMtrs = motor_group(spinMtr1, spinMtr2);
motor discFlick = motor(PORT15, ratio18_1, false);

int speed(int level){
    int newNum1 = 0;
    if (level > 4)
    {
        if (level % 4 !=0)
        {
            level = level % 4;
        }else{
            level = 4;
        }
    }
    for (int i = 1; i <= level; i++) {
        newNum1 = 25*i;
    }
    return newNum1;
}
int numPres = 0;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool Controller1XBButtonsControlMotorsStopped = true;
bool Controller1YAButtonsControlMotorsStopped = true;
bool Controller1LeftRightButtonsControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;
bool DrivetrainStrafingNeedsToBeStopped_Controller1 = true;
bool buttonBState = false;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
       if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3
      // right = Axis2
      //int drivetrainStrafing = Controller1.Axis4.position();

      int rightXAxis = Controller1.Axis1.position();
      int rightYAxis = Controller1.Axis2.position();
      int leftYAxis = Controller1.Axis3.position();
      int leftXAxis = Controller1.Axis4.position();
      
      //START OF DRIVE CODE
      //START OF TANK DRIVE 
      int leftFrontWheel = leftYAxis + rightXAxis + leftXAxis;
      int leftBackWheel = leftYAxis + rightXAxis - leftXAxis;
      int rightFrontWheel = leftYAxis - rightXAxis - leftXAxis;
      int rightBackWheel = leftYAxis - rightXAxis + leftXAxis;

      leftMotorA.spin(forward, leftFrontWheel, percent);
      leftMotorB.spin(forward, leftBackWheel, percent);
      rightMotorA.spin(forward, rightFrontWheel, percent);
      rightMotorB.spin(forward, rightBackWheel, percent);

      //START OF BUTTON FUNCTIONS
      //DISCFLICK BUTTON
      if (Controller1.ButtonUp.pressing()) {
        flickDisk();
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1XBButtonsControlMotorsStopped) {
        discFlick.stop(coast);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        //I girlbossed too close to the sun :((((
        //pure of heart, dumb of ass
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      //INTAKE BUTTONS
      if(Controller1.ButtonR1.pressing()){
        intake.spin(forward, 100, velocityUnits::pct);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        intake.spin(reverse, 100, velocityUnits::pct);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        //I girlbossed too close to the sun :((((
        //pure of heart, dumb of ass
        Controller1RightShoulderControlMotorsStopped = false;
      }
      else if(!Controller1RightShoulderControlMotorsStopped){
        intake.stop(hold);
      }
      //SPIN MOTORS BUTTONS
      if (Controller1.ButtonL1.pressing()) {
        spinMtrs.spin(forward, 100, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        spinMtrs.stop(coast);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        discFlick.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        //I girlbossed too close to the sun :((((
        //pure of heart, dumb of ass
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      if (Controller1.ButtonY.pressing()) {
        spinMtrs.spin(forward, 85, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonX.pressing()) {
        spinMtrs.spin(forward, 90, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonA.pressing()) {
        spinMtrs.spin(forward, 95, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonB.pressing()) {
        spinMtrs.spin(forward, 100, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      }

      if(!Controller1.ButtonDown.pressing() && buttonBState){
        spinMtrs.spin(forward, speed(numPres), velocityUnits::pct);
        buttonBState = false;
      }
      if(Controller1.ButtonDown.pressing()){
        numPres += 1;
        buttonBState = true;
      }
      //END OF BUTTON FUNCTIONS
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}