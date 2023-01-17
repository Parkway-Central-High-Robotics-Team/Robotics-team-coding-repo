/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Mon Aug 24 2020                                           */
/*    Description:  Optical Sensing                                           */
/*                                                                            */
/*    This program will demonstrate how to use the Optical Sensor to          */
/*    report brightness, hue, and color information if an object is detected  */
/*    in its range                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// Optical2             optical       2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Print all Optical Sensor values to the screen in an infinite loop
  while (true) {
    
    // Clear the screen and set the cursor to top left corner at the start of each loop
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    // Check if an object is detected by the Optical Sensor
    if (Optical2.isNearObject()) {
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

      Brain.Screen.print("Detects a green object?: ");
      Brain.Screen.print("%s", Optical2.color() == green ? "TRUE" : "FALSE");
      Brain.Screen.newLine();

      Brain.Screen.print("Detects a blue object?: ");
      Brain.Screen.print("%s", Optical2.color() == blue ? "TRUE" : "FALSE");
      Brain.Screen.newLine();
    } else {
      Brain.Screen.print("No Object Detected");
    }

    // A brief delay to allow text to be printed without distortion or tearing
    wait(0.2, seconds);
  }
}
