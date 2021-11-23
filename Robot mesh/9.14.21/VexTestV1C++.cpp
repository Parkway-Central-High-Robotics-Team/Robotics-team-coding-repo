// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//#region config_globals
vex::brain      Brain;
vex::motor      left_drive_mtr(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor      right_drive_mtr(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::inertial   inertial_sensor(vex::PORT3);
vex::vision     vision_sensor(vex::PORT4);
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
        // This is the main loop for the driver control.  Each time through the loop you should update motor movements based on input from the controller.
        
        // ******* CODE TO REDUCE SENSITIVITY OF TANK MODE - BEGIN ******
            float max = 127.0;
            float left_percent = con.Axis3.value()/max;
            float right_percent = con.Axis2.value()/max;
           
            float left_new_percent = left_percent * left_percent * left_percent;
            float right_new_percent = right_percent * right_percent * right_percent;
           
            float motor_max = 100;
            int left_power = left_new_percent * motor_max;
            int right_power = right_new_percent * motor_max;
           
            left_drive_mtr.spin(fwd,left_power,vex::velocityUnits::pct);
            right_drive_mtr.spin(fwd,right_power,vex::velocityUnits::pct);
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
