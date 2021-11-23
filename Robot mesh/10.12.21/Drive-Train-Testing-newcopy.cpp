// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//#region config_globals
vex::brain  Brain;
vex::motor  left_drive_mtr(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor  right_drive_mtr(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::limit  limit_A(Brain.ThreeWirePort.A);
vex::bumper bumper_B(Brain.ThreeWirePort.B);
vex::pot    pot_C(Brain.ThreeWirePort.C);
vex::controller    con(vex::controllerType::primary);
vex::drivetrain dt(left_drive_mtr, right_drive_mtr, 319.1764, 292.1, 0, vex::distanceUnits::mm, 1);
//#endregion config_globals


// Creates a competition object that allows access to Competition methods.
vex::competition Competition;

void limitTest() {
    while (true){
        if (limit_A == 1) {
            left_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            right_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
    }
}

void potTest() {
    while(true) {
        Brain.Screen.clearScreen();
    
        // display the potentiometer rotation value on the screen
        Brain.Screen.printAt(1, 20, "rotation: %f degrees", pot_C.value(rotationUnits::deg));
    
        // display the potentiometer percent value on the screen
        Brain.Screen.printAt(1, 40, "percent: %f %%", pot_C.value(percentUnits::pct));
        
        // display the potentiometer analog value on the screen
        Brain.Screen.printAt(1, 60, "analog: %f mV", pot_C.value(analogUnits::mV));
        
        //Sleep the task for a short amount of time to prevent wasted resources.
        sleepMs(500);
    }
}

void bumpTest() {
    while(true) {
        while(bumper_B.pressing()){
            left_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            right_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
    }
}
void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial position

}

void autonomous() {
    // Place autonomous code here
    dt.driveFor(vex::directionType::rev, 9, vex::distanceUnits::in, 100, vex::velocityUnits::pct, true);
}

void drivercontrol() {
    // Place drive control code here, inside the loop
    while (true) {
        // This is the main loop for the driver control.
        // Each time through the loop you should update motor
        // movements based on input from the controller.
        
        float max = 100.0;
        float left_percent = con.Axis3.value()/max;
        float right_percent = con.Axis2.value()/max;
           
        float motor_max = 100;
        int left_power = left_percent * motor_max;
        int right_power = right_percent * motor_max;
        
        left_drive_mtr.spin(vex::directionType::fwd, left_power, vex::velocityUnits::pct); 
        right_drive_mtr.spin(vex::directionType::fwd, right_power, vex::velocityUnits::pct);
        
        //left_drive_mtr1.spin(vex::directionType::fwd, left_power, vex::velocityUnits::pct); 
        //right_drive_mtr1.spin(vex::directionType::fwd, right_power, vex::velocityUnits::pct);
        
        wait(20,timeUnits::msec);
    }
}

int main() {
    // Do not adjust the lines below
    Brain.Screen.print("User Program has Started.");
    thread m_limitthread = thread(limitTest);
    thread m_potthread = thread(potTest);
    thread m_bumpthread1 = thread(bumpTest);
    // Set up (but don't start) callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Robot Mesh Studio runtime continues to run until all threads and
    // competition callbacks are finished.
}
