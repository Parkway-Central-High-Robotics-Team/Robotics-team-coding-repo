#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision5__REDBOX = signature (1, 12019, 13155, 12587, -2917, -2513, -2715, 2.5, 0);
signature Vision5__BLUEBOX = signature (2, -4113, -2785, -3449, 4621, 6245, 5433, 3, 0);
vision Vision5 = vision (PORT5, 50, Vision5__REDBOX, Vision5__BLUEBOX);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}