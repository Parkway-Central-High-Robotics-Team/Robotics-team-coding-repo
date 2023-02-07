#include "vex.h"
//#include "vision.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT3, ratio18_1, false);
motor leftMotorB = motor(PORT4, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT8, ratio18_1, true);
motor rightMotorB = motor(PORT9, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
motor_group StrafeAGroup = motor_group(leftMotorA, rightMotorB);
motor_group StrafeBGroup = motor_group(leftMotorB, rightMotorA);
inertial DrivetrainInertial = inertial(PORT11);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 177.79999999999998, mm, 1);
controller Controller1 = controller(primary);
motor intake = motor(PORT20, ratio18_1, false);
motor spinMtr1 = motor(PORT12, ratio18_1, true);
motor spinMtr2 = motor(PORT13, ratio18_1, false);
motor indexer = motor(PORT19, ratio18_1, true);
motor_group spinMtrs = motor_group(spinMtr1, spinMtr2);
digital_out Pneumatics = digital_out(Brain.ThreeWirePort.B);
optical Optical2 = optical(PORT2);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool Controller1XBButtonsControlMotorsStopped = true;
bool Controller1YAButtonsControlMotorsStopped = true;
bool Controller1LeftRightButtonsControlMotorsStopped = true;
bool DrivetrainStrafingNeedsToBeStopped_Controller1 = true;

bool leftFrontWheelNeedsToBeStopped_Controller1 = true;
bool leftBackWheelNeedsToBeStopped_Controller1 = true;
bool rightFrontWheelNeedsToBeStopped_Controller1 = true;
bool rightBackWheelNeedsToBeStopped_Controller1 = true;

bool buttonBState = false;
bool driveBool = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      
      // calculate the drivetrain motor velocities from the controller joystick axies
      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();
      //int drivetrainStrafing = Controller1.Axis4.position();
      
      //START OF DRIVE CODE
      //START OF TANK DRIVE 

      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
      // check if the value is inside of the deadband range
      if(Pneumatics.value() == 0){
        if(Controller1.ButtonUp.pressing()){
          Pneumatics.set(true);
          Brain.Screen.print("L1 is Pressing");
        }
      }
      else if(Pneumatics.value() == 1){
        if(Controller1.ButtonDown.pressing()){
          Pneumatics.set(false);
          Brain.Screen.print("L1 is Pressing");
        }
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
        spinMtrs.spin(forward, 58.75, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        spinMtrs.stop(coast);
        Controller1LeftShoulderControlMotorsStopped = false;
      }

      if (Controller1.ButtonY.pressing()) {
        spinMtrs.spin(forward, 70, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonX.pressing()) {
        spinMtrs.spin(forward, 80, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonA.pressing()) {
        spinMtrs.spin(forward, 90, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if(Controller1.ButtonB.pressing()) {
        spinMtrs.spin(forward, 100, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      }
      if(Controller1.ButtonRight.pressing()){
        indexerFire();
      }
      else if(Controller1.ButtonLeft.pressing()){
        indexer.setVelocity(100, velocityUnits::pct);
        indexer.spinTo(-50, rotationUnits::deg);
        indexer.setBrake(brake);
      }
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
  Pneumatics.set(false);
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