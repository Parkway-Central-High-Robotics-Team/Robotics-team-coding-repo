// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//We might have switch the project titles (EC vs AS).

//#region config_globals
vex::brain      Brain;
vex::motor      right_drive_mtr(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor      left_drive_mtr(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor      omni_drive_mtr(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor      lift_mtr(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor      clamp_lift(vex::PORT5, vex::gearSetting::ratio18_1, false);
vex::motor      clamp_mtr(vex::PORT6, vex::gearSetting::ratio18_1, false);
vex::limit      limit_A(Brain.ThreeWirePort.A);
vex::bumper     bumper_B(Brain.ThreeWirePort.B);
vex::pot        pot_C(Brain.ThreeWirePort.C);
vex::limit      forklift_limit(Brain.ThreeWirePort.D);
vex::limit      forklift_limit_down(Brain.ThreeWirePort.E);
vex::drivetrain dt(left_drive_mtr, right_drive_mtr, 319.1764, 292.1, 0, vex::distanceUnits::mm, 1);
vex::controller con(vex::controllerType::primary);
//#endregion config_globals

//The CubeUp program uses booleans to check if a thread is on or off
//and declares the threads here, finishing them in their own functions. This is not them most efficient way to do it.

/*static bool threadArmRunning = false;
static bool threadArm2Running = false;
static bool threadKillRunning = false;
static thread m_upthread1;
static thread m_downthread1;
static thread m_killthread1;*/
// Creates a competition object that allows access to Competition methods.
vex::competition Competition;

//Functions for autonomous:

// in terms of time: use functions with pauses Mssleep sort of thing. Can do deg later if neccessary
//need right and left for this
void turnDriveTrainRight(double velocity){
    right_drive_mtr.spin(directionType::fwd, velocity, velocityUnits::pct);
    left_drive_mtr.spin(directionType::rev, velocity, velocityUnits::pct);
}

void turnDriveTrainLeft(double velocity){
    right_drive_mtr.spin(directionType::rev, velocity, velocityUnits::pct);
    left_drive_mtr.spin(directionType::fwd, velocity, velocityUnits::pct);
}

void liftUp(double velocity){
    lift_mtr.spin(directionType::fwd, velocity, velocityUnits::pct);
}

void liftDown(double velocity){
    lift_mtr.spin(directionType::rev, velocity, velocityUnits::pct);
}

void liftStopCoast(){
    left_drive_mtr.stop(brakeType::coast);
}

void liftStopHold(){
    left_drive_mtr.stop(brakeType::hold);
}

void driveTrainStopCoast() {
    left_drive_mtr.stop(brakeType::coast);
    right_drive_mtr.stop(brakeType::coast);
}

void driveTrainStopHold() {
    left_drive_mtr.stop(brakeType::hold);
    right_drive_mtr.stop(brakeType::hold);
}

//The following three functions test the limit, potentiometer, and bumper sensors. 
//This is not necessary for the actual robot so it is commented out now along with the threads.
/*
void limitTest() {
    while (true){
        if (limit_A == 1) {
            right_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            left_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
    }
}
*/
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

void motorTest() {
    while(true) {
        Brain.Screen.clearScreen();
    
        // display the potentiometer rotation value on the screen
        //Brain.Screen.print("Arm rotation: %f degrees",right_drive_mtr.rotation(rotationUnits::deg));
        
        //Sleep the task for a short amount of time to prevent wasted resources.
        sleepMs(500);
    }
}
/*
void bumpTest() {
    while(true) {
        while(bumper_B.pressing()){
            right_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            left_drive_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
    }
}*/

//function which holds all motors, turned into a thread in main. not active currently
void killButton() {
    while(true) {
        if(con.ButtonA.pressing()){
            clamp_mtr.stop(vex::brakeType::hold);
            clamp_lift.stop(vex::brakeType::hold);
            lift_mtr.stop(vex::brakeType::hold);
            omni_drive_mtr.stop(vex::brakeType::hold);
            left_drive_mtr.stop(vex::brakeType::hold);
            right_drive_mtr.stop(vex::brakeType::hold);
        }
    }
}

//Function which raises and lowers the lift motor. This thread should be active
//The currently commented out code prepares for the limit switch addition.
void back_lift() {
    while(true) {
        if(con.ButtonR1.pressing()){ // == shouldnt be necessary, remove if this is the case.
            //lift_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit.pressing()) {
            //     lift_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                lift_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
                //lift_mtr.startRotateTo(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            //}
        } else if(con.ButtonR2.pressing()){
            //lift_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit_down.pressing()) {
                 //lift_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                lift_mtr.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            //}
        }
        else {
            lift_mtr.stop(vex::brakeType::hold);
        }
    }
}

void clamp_function() {
    while(true) {
        if(con.ButtonX.pressing()){ //OPENS CLAW
            //clamp_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit.pressing()) {
                 //clamp_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                clamp_mtr.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            //}
        } else if(con.ButtonY.pressing()){
            //clamp_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit_down.pressing()) {
                 //clamp_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                clamp_mtr.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            //}
        }
        else {
            clamp_mtr.stop(vex::brakeType::hold);
        }
    }
}

void clamp_lift_function() {
    while(true) {
        if(con.ButtonL1.pressing()){ // == shouldnt be necessary, remove if this is the case.
            //clamp_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit.pressing()) {
                 //clamp_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                clamp_lift.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            //}
        } else if(con.ButtonL2.pressing()){
            //clamp_mtr.rotateFor(5, vex::rotationUnits::deg, 10, vex::velocityUnits::pct, true);
            //if (forklift_limit_down.pressing()) {
                 //clamp_mtr.stop(vex::brakeType::hold);
            //}
            //else {
                clamp_lift.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            //}
        }
        else {
            clamp_lift.stop(vex::brakeType::hold);
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

void autonomousTestFunctions() {
    // Place autonomous code here
    //Saying rev makes it go forward now.
    dt.driveFor(vex::directionType::rev, 10, vex::distanceUnits::in, 100, vex::velocityUnits::pct, true);
    sleepMs(1000);
    //turn 90% velocity for 1 second
    turnDriveTrainRight(90); //RIGHT
    sleepMs(1000);
    driveTrainStopCoast();
    sleepMs(1000);
    dt.driveFor(vex::directionType::fwd, 10, vex::distanceUnits::in, 100, vex::velocityUnits::pct, true);
    //turn 90% velocity for 1 second
    turnDriveTrainLeft(90);
    sleepMs(1000);
    driveTrainStopCoast();
    sleepMs(1000);
    
    //DOESNT WORK
    //move arms
    
    //liftDown(50);
    //lift_mtr.spin(directionType::rev, velocity, velocityUnits::pct);
    //left_drive_mtr.stop(vex::brakeType::hold);
    //sleepMs(500);
    //STOP ARMS (very important)
    liftStopCoast();
    sleepMs(500);
    //down
    liftUp(50);
    sleepMs(500);
    //STOP ARMS (very important)
    liftStopCoast();
    sleepMs(500);

}

void nearestGoalRight() {
    
    
    //Brain.Screen.printLine(2, "Begin NearestGoalRight.");
    
    dt.driveFor(vex::directionType::fwd, 30, vex::distanceUnits::in, 80, vex::velocityUnits::pct, true);
    
    lift_mtr.spin(directionType::rev, 100, vex::velocityUnits::pct);
    sleepMs(2200);
    lift_mtr.stop(brakeType::hold);
    
    clamp_lift.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    sleepMs(1400);
    clamp_lift.stop(brakeType::hold);
    
    dt.driveFor(vex::directionType::fwd, 10, vex::distanceUnits::in, 60, vex::velocityUnits::pct, true);
    dt.driveFor(vex::directionType::fwd, 10, vex::distanceUnits::in, 30, vex::velocityUnits::pct, true);
    
    
    lift_mtr.spin(directionType::fwd, 50, vex::velocityUnits::pct);
    sleepMs(1900);
    lift_mtr.stop(brakeType::hold);
    
    dt.driveFor(vex::directionType::rev, 10, vex::distanceUnits::in, 40, vex::velocityUnits::pct, true);
    
    turnDriveTrainLeft(40); //Left
    sleepMs(1100);
    right_drive_mtr.stop(brakeType::coast);
    left_drive_mtr.stop(brakeType::coast);
    
    dt.driveFor(vex::directionType::fwd, 12, vex::distanceUnits::in, 50, vex::velocityUnits::pct, true);
    
    /*
    
    Brain.Screen.printLine(3, "Lift code Complete.");
    sleepMs(1000);*/
}

void nearestGoalLeft() {
    
    
    //Brain.Screen.printLine(2, "Begin NearestGoalRight.");
    
    dt.driveFor(vex::directionType::fwd, 30, vex::distanceUnits::in, 80, vex::velocityUnits::pct, true);
    
    lift_mtr.spin(directionType::rev, 100, vex::velocityUnits::pct);
    sleepMs(2200);
    lift_mtr.stop(brakeType::hold);
    
    clamp_lift.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    sleepMs(1400);
    clamp_lift.stop(brakeType::hold);
    
    dt.driveFor(vex::directionType::fwd, 10, vex::distanceUnits::in, 60, vex::velocityUnits::pct, true);
    dt.driveFor(vex::directionType::fwd, 10, vex::distanceUnits::in, 30, vex::velocityUnits::pct, true);
    
    
    lift_mtr.spin(directionType::fwd, 50, vex::velocityUnits::pct);
    sleepMs(1900);
    lift_mtr.stop(brakeType::hold);
    
    dt.driveFor(vex::directionType::rev, 10, vex::distanceUnits::in, 40, vex::velocityUnits::pct, true);
    
    turnDriveTrainRight(40); //
    sleepMs(1100);
    right_drive_mtr.stop(brakeType::coast);
    left_drive_mtr.stop(brakeType::coast);
    
    dt.driveFor(vex::directionType::fwd, 12, vex::distanceUnits::in, 50, vex::velocityUnits::pct, true);
}

void drivercontrol() {
    // Place drive control code here, inside the loop
    while (true) {
        // This is the main loop for the driver control.
        // Each time through the loop you should update motor
        // movements based on input from the controller.
        thread m_liftup = thread(back_lift);
        thread m_clamphinge = thread(clamp_function);
        thread m_clamphinge1 = thread(clamp_lift_function);
        //testing
        thread m_killthread = thread(killButton);
        
        float max = 160.0;
        float left_percent = con.Axis2.value()/max;
        float right_percent = con.Axis3.value()/max;
           
        float motor_max = 100;
        int left_power = left_percent * motor_max;
        int right_power = right_percent * motor_max;
        //omni wheel power
        float side_percent = con.Axis4.value()/max;
        int omni_power = side_percent * motor_max;
        
        right_drive_mtr.spin(vex::directionType::rev, left_power, vex::velocityUnits::pct); 
        left_drive_mtr.spin(vex::directionType::rev, right_power, vex::velocityUnits::pct);
        omni_drive_mtr.spin(vex::directionType::rev, omni_power, vex::velocityUnits::pct);

        
        
        //omni_drive_mtr.spin(vex::directionType::fwd, (this would be con.ButtonR1.pressing()), vex::velocityUnits::pct);
        //program thread that can stop all motors
        
        //left_drive_mtr1.spin(vex::directionType::fwd, left_power, vex::velocityUnits::pct); 
        //right_drive_mtr1.spin(vex::directionType::fwd, right_power, vex::velocityUnits::pct);
        
        wait(20,timeUnits::msec);
    }
}

int main() {
    // Do not adjust the lines below
    Brain.Screen.print("User Program has Started.");
    
    //Threads for sensor tests: these WORK but are not currently active
    
    /*thread m_limitthread = thread(limitTest);
    thread m_bumpthread1 = thread(bumpTest);*/
    
    //thread m_potthread = thread(potTest);
    
    
    // Set up (but don't start) callbacks for autonomous and driver control periods.
    Competition.autonomous(nearestGoalRight); //Change THIS to switch the autonomous program we are using!!!!!!
    Competition.drivercontrol(drivercontrol);
    

    // Run the pre-autonomous function.
    pre_auton();

    // Robot Mesh Studio runtime continues to run until all threads and
    // competition callbacks are finished.
}
