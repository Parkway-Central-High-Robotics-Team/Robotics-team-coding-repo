// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//#region config_globals
vex::brain      Brain;
vex::motor      left_drive_mtr(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor      right_drive_mtr(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor      lift_mtr(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::limit      limit_A(Brain.ThreeWirePort.A);
vex::bumper     bumper_B(Brain.ThreeWirePort.B);
vex::pot        pot_C(Brain.ThreeWirePort.C);
vex::limit      forklift_limit(Brain.ThreeWirePort.D);
vex::drivetrain dt(left_drive_mtr, right_drive_mtr, 319.1764, 292.1, 0, vex::distanceUnits::mm, 1);
vex::controller con(vex::controllerType::primary);
//#endregion config_globals
bool conveyor_run_up = false;
bool conveyor_run_down = false;
bool button_held_R1 = false;
bool button_held_R2 = false;

// Creates a competition object that allows access to Competition methods.
vex::competition Competition;

//function for button R1
void conveyor_lift_R1_button_press() {
    Brain.Screen.print("This works 1");
    while(true) {
        if(con.ButtonR1.pressing()==true){
            button_held_R1 = true;
            }
        if(con.ButtonR1.pressing()==false && button_held_R1==true){
            conveyor_run_down = !conveyor_run_down;
            button_held_R1 = false;
        } 
    }
}

//function for button R2
void conveyor_lift_R2_button_press() {
    Brain.Screen.print("This works 1");
    while(true) {
        if(con.ButtonR2.pressing()==true){
            button_held_R2 = true;
            }
        if(con.ButtonR2.pressing()==false && button_held_R2==true){
            conveyor_run_up = !conveyor_run_up;
            button_held_R2 = false;
        } 
    }
}

//runs conveyor thread bassed on the bools dictated by the conveyor_lift_R2_button_press() and the conveyor_lift_R1_button_press()
void conveyor_thread(){
    while (true) {
        if (conveyor_run_up ==  true) {
            lift_mtr.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
            conveyor_run_down = false;
        }else if (conveyor_run_down ==  true) {
            lift_mtr.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
            conveyor_run_up = false;
        }else {
            lift_mtr.stop(vex::brakeType::hold);
        }
    }
}

void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial position

}

void autonomous() {
    // Place autonomous code here
            
}

void drivercontrol() {
    // Place drive control code here, inside the loop
    while (true) {
        // This is the main loop for the driver control.
        // Each time through the loop you should update motor
        // movements based on input from the controller.
        //thread call
        
        //one stick drive 
        /*
        float max = 200;
        float left_percent = con.Axis2.value()/max;
        float right_percent = con.Axis2.value()/max;
           
        float motor_max = 100;
        int left_power = left_percent * motor_max;
        int right_power = right_percent * motor_max;
        
        left_drive_mtr.spin(vex::directionType::fwd, left_power, vex::velocityUnits::pct); 
        right_drive_mtr.spin(vex::directionType::fwd, right_power, vex::velocityUnits::pct);
        
        wait(20,timeUnits::msec);
        */
        
        //tank drive
        float max = 200;
        float left_percent = con.Axis3.value()/max;
        float right_percent = con.Axis2.value()/max;
           
        float motor_max = 100;
        int left_power = left_percent * motor_max;
        int right_power = right_percent * motor_max;
        
        left_drive_mtr.spin(vex::directionType::fwd, left_power, vex::velocityUnits::pct); 
        right_drive_mtr.spin(vex::directionType::fwd, right_power, vex::velocityUnits::pct);
        
        wait(20,timeUnits::msec);
    }
}

int main() {
    // Do not adjust the lines below
    
    Brain.Screen.print("User Program has Started.");
    
    // Set up (but don't start) callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
    
    //Thread call
    thread m_conveyor_lift_R1_button_press = thread(conveyor_lift_R1_button_press);
    thread m_conveyor_lift_R2_button_press = thread(conveyor_lift_R2_button_press);
    thread m_conveyor_thread = thread(conveyor_thread);
    
    // Run the pre-autonomous function.
    pre_auton();

    // Robot Mesh Studio runtime continues to run until all threads and competition callbacks are finished.
}
