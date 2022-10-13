#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// VEXcode device constructors
// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
motor leftMotorA = motor(PORT8, ratio18_1, false);
motor leftMotorB = motor(PORT9, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT3, ratio18_1, true);
motor rightMotorB = motor(PORT4, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
motor_group StrafeAGroup = motor_group(leftMotorA, rightMotorB);
motor_group StrafeBGroup = motor_group(leftMotorB, rightMotorA);
inertial DrivetrainInertial = inertial(PORT11);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 177.79999999999998, mm, 1);
controller Controller1 = controller(primary);
motor Quick_grab = motor(PORT14, ratio18_1, false);
motor lift_front = motor(PORT7, ratio18_1, false);
motor claw_back = motor(PORT6, ratio18_1, false); 
motor lift_clamp = motor(PORT5, ratio18_1, false); 

//** ----------Start of controler map---------- **\\
//                  Controller Map                \\
// Joysticks: Used for tank drive                 \\
// Button R1: Used to raise the back lift         \\
// Button R2: Used to lower the back lift         \\
// Button L1: Used to open the front claw         \\
// Button L2: Used to close the front claw        \\
// Button Y: Used to lift a goal on platform      \\
// Button A: Used to lower lift from platform     \\
// Button X: Used to open the lift clamp          \\
// Button B: Used to close the lift clamp         \\
// Button Up: Used to raise the quick grab        \\
// Button Down: Used to lower the quick grab      \\
// Button Left: Used for grab goal backside       \\
// Button Right: Used for grab goal frontside     \\
//** -----------End of controler map----------- **\\

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

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
       if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3
      // right = Axis2
      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();
      
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
      // check the ButtonL1/ButtonL2 status to control lift_back
      if (Controller1.ButtonL1.pressing()) {
        claw_back.spin(forward, 50, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        claw_back.spin(reverse, 50, velocityUnits::pct);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        claw_back.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      // check the ButtonR1/ButtonR2 status to control lift_front
      if (Controller1.ButtonR1.pressing()) {
        lift_front.spin(reverse, 100, velocityUnits::pct);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        lift_front.spin(forward, 100, velocityUnits::pct);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        lift_front.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }
      // check the ButtonUp/ButtonDown status to control lift_back
      if (Controller1.ButtonUp.pressing()) {
        Quick_grab.setStopping(hold);
        Quick_grab.spin(reverse, 100, velocityUnits::pct);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        Quick_grab.setStopping(coast);
        Quick_grab.spin(forward, 100, velocityUnits::pct);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (!Controller1UpDownButtonsControlMotorsStopped) {
        Quick_grab.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1UpDownButtonsControlMotorsStopped = true;
      }
      // check the ButtonX/ButtonB status to control lift_clamp
      if (Controller1.ButtonX.pressing()) {
        lift_clamp.spin(reverse, 100, velocityUnits::pct);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonB.pressing()) {
        lift_clamp.spin(forward, 100, velocityUnits::pct);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (!Controller1XBButtonsControlMotorsStopped) {
        lift_clamp.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1XBButtonsControlMotorsStopped = true;
      }
      // check the ButtonLeft/ButtonRight status to control the grab-goal pre-defined functions
      if (Controller1.ButtonLeft.pressing()) {
        StrafeAGroup.setVelocity(100, percent);
        StrafeBGroup.setVelocity(100, percent);
        StrafeAGroup.spin(forward);
        StrafeBGroup.spin(reverse);
      } else if (Controller1.ButtonRight.pressing()) {
        StrafeAGroup.setVelocity(100, percent);
        StrafeBGroup.setVelocity(100, percent);
        StrafeAGroup.spin(reverse);
        StrafeBGroup.spin(forward);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftRightButtonsControlMotorsStopped = false;
      }else{
          StrafeAGroup.setVelocity(0, percent);
          StrafeBGroup.setVelocity(0, percent);
      }
      // check the ButtonY/ButtonA status to control the goal-on-platform pre-defined functions
      if (Controller1.ButtonY.pressing()) {
        lift_goal_on_platform();
        Controller1YAButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonA.pressing()) {
        lower_lift_from_platform();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1YAButtonsControlMotorsStopped = false;
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