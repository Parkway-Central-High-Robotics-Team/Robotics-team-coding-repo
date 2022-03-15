using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision__BLUEBOX;
extern signature Vision__GREENBOX;
extern signature Vision__REDBOX;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern inertial DrivetrainInertial;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA; 
extern motor rightMotorB; 
extern motor Quick_grab;
extern motor lift_front;
extern motor claw_back;
extern motor lift_clamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );