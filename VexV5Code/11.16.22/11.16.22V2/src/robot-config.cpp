#include "vex.h"

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
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;
bool driveBool = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int rightXAxis = Controller1.Axis1.position();
      int rightYAxis = Controller1.Axis2.position();
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
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}