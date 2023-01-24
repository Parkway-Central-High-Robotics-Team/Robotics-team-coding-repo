// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//#region config_globals
vex::brain      Brain;
vex::motor      motor_1(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor      motor_2(vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::limit      limit_A(Brain.ThreeWirePort.A);
vex::drivetrain dt(motor_1, motor_2, 319.1764, 292.1, 0, vex::distanceUnits::mm, 1);
vex::controller con(vex::controllerType::primary);
//#endregion config_globals


// Creates a competition object that allows access to Competition methods.
vex::competition Competition;

void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial positions

}

void autonomous() {
    // Place autonomous code here

}

void drivercontrol() {
    // Place drive control code here, inside the loop
    while (true) {
        dt.drive(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        sleepMs(3000);
        dt.stop(vex::brakeType::coast);
        dt.drive(vex::directionType::rev, 100, vex::velocityUnits::pct);
        // This is the main loop for the driver control.
        // Each time through the loop you should update motor
        // movements based on input from the controller.

    }
}

int main() {
    // Do not adjust the lines below

    // Set up (but don't start) callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Robot Mesh Studio runtime continues to run until all threads and
    // competition callbacks are finished.
}
