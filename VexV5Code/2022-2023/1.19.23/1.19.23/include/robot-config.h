using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor_group RightDriveSmart;
extern motor_group LeftDriveSmart;
extern motor_group StrafeAGroup;
extern motor_group StrafeBGroup;

extern motor intake;
extern motor liftA;
extern motor liftB;
extern motor discFlick;
extern motor shooter;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA; 
extern motor rightMotorB; 
extern motor_group lifts;

extern digital_out Pneumatics;
extern optical Optical2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );