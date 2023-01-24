using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor_group spinMtrs;
extern digital_out Pneumatics;
extern motor intake;
extern motor discFlick;
extern motor spinMtr1;
extern motor spinMtr2;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA; 
extern motor rightMotorB; 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );