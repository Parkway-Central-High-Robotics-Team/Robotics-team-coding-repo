/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\kaiserl4961                                      */
/*    Created:      Tue Nov 30 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// Controller1          controller                    
// lift                 motor         6               
// arm                  motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void auton() {
  Drivetrain.driveFor(vex::directionType::rev, 10, vex::distanceUnits::in, 100, vex::velocityUnits::pct, true);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}
