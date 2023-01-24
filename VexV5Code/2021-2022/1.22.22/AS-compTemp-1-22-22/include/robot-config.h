using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern inertial DrivetrainInertial;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA; 
extern motor rightMotorB; 
extern motor arm;
extern motor liftFront;
extern motor liftBack;
extern motor lift_clamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );