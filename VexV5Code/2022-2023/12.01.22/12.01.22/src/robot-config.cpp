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
motor_group spinMtrs = motor_group(spinMtr1, spinMtr2);
digital_out Pneumatics = digital_out(Brain.ThreeWirePort.B);

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
      int rightXAxis = Controller1.Axis1.position();
      //int rightYAxis = Controller1.Axis2.position();
      int leftYAxis = Controller1.Axis3.position();
      int leftXAxis = Controller1.Axis4.position();
      
      if ((leftYAxis < 5 && leftYAxis > -5) && (rightXAxis < 5 && rightXAxis > -5) && (leftXAxis < 5 && leftXAxis > -5)) {
        // check if the right motor has already been stopped
        if (driveBool) {
          // stop the right drive motor
          leftMotorA.stop();
          leftMotorB.stop();
          rightMotorA.stop();
          rightMotorB.stop();
          // tell the code that the right motor has been stopped
          driveBool = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        driveBool = true;
      }
      
      //START OF TANK DRIVE 
      if (driveBool) {
        int leftFrontWheel = leftYAxis + rightXAxis + leftXAxis;
        int leftBackWheel = leftYAxis + rightXAxis - leftXAxis;
        int rightFrontWheel = leftYAxis - rightXAxis - leftXAxis;
        int rightBackWheel = leftYAxis - rightXAxis + leftXAxis;

        leftMotorA.spin(forward, leftFrontWheel, percent);
        leftMotorB.spin(forward, leftBackWheel, percent);
        rightMotorA.spin(forward, rightFrontWheel, percent);
        rightMotorB.spin(forward, rightBackWheel, percent);
      }
      // check if the value is inside of the deadband range

      if (Controller1.ButtonUp.pressing()) {
        Controller1UpDownButtonsControlMotorsStopped = false;
      } if (Controller1.ButtonDown.pressing()) {
        visionTest();
        //TrackWithLargeFunction();
        Controller1UpDownButtonsControlMotorsStopped = false;
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
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}