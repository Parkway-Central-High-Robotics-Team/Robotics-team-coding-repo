/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       james                                                     */
/*    Created:      Sat Nov 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// MotorLf              motor         1               
// MotorLb              motor         2               
// MotorRb              motor         9               
// MotorRf              motor         10              
// GyroA                gyro          A               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

/*----------------------------------------------------------------------------*/
// define the motor groups
// the motors should have been setup with correct the gear cartridge ratios
// and the reverse flag set as necessary so they rotate in the correct direction
// when commanded to more forwards

// left hand side of the robot has two motors
motor_group   leftDrive( MotorLb, MotorLf );

// right hand side of the robot has two motors
motor_group   rightDrive( MotorRb, MotorRf );

/*----------------------------------------------------------------------------*/
// define the drivetrain
// this one is a smart drive which uses the gyro
// gyro and all motors were defined using graphical config
// we have 4 inch wheels
// drive is 16 inches wide between the wheels
// drive has a 16 inch wheelbase (between fron and back wheel axles)
//
// this is how the above definition would be if no gyro is used
//drivetrain    robotDrive( leftDrive, rightDrive, 12.56, 16, 16, distanceUnits::in );


/*----------------------------------------------------------------------------*/
//
// A task that just displays motor velocity and position
// The motors that are part of a motor group and/or drivetrain can still be accessed
// directly.
//
int displayTask() {
    while(1) {
      // display some useful info
      Brain.Screen.newLine();
      Brain.Screen.newLine();

      // motor group velocity and position is returned for the first motor in the group

      // drivetrain velocity is the average of the motor velocities for left and right
      Brain.Screen.print( "  robotDrive speed: %4.0f", robotDrive.velocity( percent ) );
      Brain.Screen.newLine();

      // no need to run this loop too quickly
      wait( 20, timeUnits::msec );
    }

    return 0;
}

/*----------------------------------------------------------------------------*/
//
// main program entry and drive control
//
int main() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();

    // set 10 second timeout for robot drive movements
    robotDrive.setTimeout(10, seconds);

    // set the speed used for drive turns
    robotDrive.setTurnVelocity(50, percent);

    // start the display task
    task displayTaskInstance( displayTask );

    // loop forever
    while( true ) {
      // Buitton A is used to rotate drive 90 degrees
      if( Controller1.ButtonA.pressing() ) {
        // tell drivetrain to rotate 90 deg
        robotDrive.turnFor( 90, degrees );
        // wait for it to be done
        while( robotDrive.isMoving() )
          wait( 10, timeUnits::msec );
      }
      else {
        // not rotating, then we can drive using controller

        // read percent from controller axis
        int leftSpeed  = Controller1.Axis3.position();
        int rightSpeed = Controller1.Axis2.position();
        // deadband
        if( abs(leftSpeed)  < 10 ) leftSpeed  = 0;
        if( abs(rightSpeed) < 10 ) rightSpeed = 0;

        // send to motors
        leftDrive.spin( forward, leftSpeed, percent );
        rightDrive.spin( forward, rightSpeed, percent );
      }
          
      // no need to run this loop too quickly
      wait( 20, timeUnits::msec );
    }

    return 0;
}
