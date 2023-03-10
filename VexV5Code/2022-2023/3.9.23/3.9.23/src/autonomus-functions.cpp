#include "vex.h"
#include "autonomous-functions.h"

using namespace vex;

void auton_skills(void){
  //enableDrivePID = false;
  startFlyWheel(75);
  rollerTime(500, 100);
  wait(1000, timeUnits::msec);
  moveForwardTime(75);
  turnLeftTime(150);
  wait(600, timeUnits::msec);
  indexerFireAuton();
  turnLeftTime(500);
  RightDriveSmart.spinFor(forward, 1600, timeUnits::msec);
  startFlyWheel(70);
  startIntake();
  moveBackwardTime(1700);
  turnRightTime(565);
  //intakeInTime(500, 100);
  wait(3000, timeUnits::msec);
  stopIntake();
  stopFlyWheel();



  //startIntake();
  //moveBackwardTime(3000);
  //stopIntake();
  //turnLeftTime(1000);
  //indexerFireAuton();
  //turnRightTime(1000);
  //moveBackwardTime(1000);
  
}


void auton_skills2(){

  // Does the starting roller and turns to the othe roller on the left
  startFlyWheel(62);
  rollerTime(300);
  startIntake();
  Drivetrain.driveFor(reverse, 17, distanceUnits::in, 75, velocityUnits::pct);
  wait(150, timeUnits::msec);
  Drivetrain.turnFor(right, 90, rotationUnits::deg);

  //Goes to the second roller, turns it, backs up, and turns to the blue goal
  wait(150, timeUnits::msec);
  moveBackwardTime(915);
  rollerTime(300);
  Drivetrain.driveFor(reverse, 10, distanceUnits::in);
  wait(150, timeUnits::msec);
  Drivetrain.turnFor(left, 91, rotationUnits::deg);

  //Dives to the blue goal and fires
  wait(150, timeUnits::msec);
  stopIntake();
  moveForwardTime(1250);
  indexerFireSkills();

  //Backs up and lines up with the three disc on the blue side. Then collects those disc
  Drivetrain.driveFor(forward, 22, distanceUnits::in, 55, velocityUnits::pct);
  Drivetrain.turnFor(left, 133, rotationUnits::deg);
  startIntake();
  Drivetrain.driveFor(forward, 55, distanceUnits::in, 75, velocityUnits::pct);
  stopIntake();

  //Turns and fires in the blue goal
  Drivetrain.turnFor(right, 93, rotationUnits::deg);
  indexerFireSkills();
  startIntake();
  Drivetrain.driveFor(forward, 1, distanceUnits::in, 75, velocityUnits::pct);

  //Turns to the 3 stack and collects it and fires it
  Drivetrain.turnFor(left, 92, rotationUnits::deg);
  Drivetrain.driveFor(forward, 49, distanceUnits::in, 55, velocityUnits::pct);
  Drivetrain.driveFor(reverse, 9, distanceUnits::in, 55, velocityUnits::pct); //3 Stack
  Drivetrain.turnFor(right, 53, rotationUnits::deg);
  Drivetrain.driveFor(reverse, 15, distanceUnits::in, 75, velocityUnits::pct);
  stopIntake();
  indexerFireSkills();

  //Drives to position to get roller
  Drivetrain.driveFor(forward, 25, distanceUnits::in, 75, velocityUnits::pct);
  Drivetrain.turnFor(left, 7, rotationUnits::deg);
  startIntake();

  //Turns to the blue side roller and rolls it
  Drivetrain.driveFor(forward, 15, distanceUnits::in, 75, velocityUnits::pct);
  Drivetrain.turnFor(left, 90, rotationUnits::deg);
  Drivetrain.driveFor(forward, 17, distanceUnits::in, 75, velocityUnits::pct);
  rollerTime(300);
  Drivetrain.driveFor(reverse, 18, distanceUnits::in, 75, velocityUnits::pct);

  //Turns to the red side roller and rolls it
  /*Drivetrain.turnFor(right, 90, rotationUnits::deg);
  Drivetrain.driveFor(forward, 15, distanceUnits::in, 75, velocityUnits::pct);
  rollerTime(300);
  Drivetrain.driveFor(reverse, 8, distanceUnits::in, 75, velocityUnits::pct);*/

  //Turns 180, drives to be in line with disc, and collects them
  Drivetrain.turnFor(right, 180, rotationUnits::deg);
  startIntake();
  Drivetrain.driveFor(forward, 15, distanceUnits::in, 75, velocityUnits::pct);
  Drivetrain.turnFor(right, 45, rotationUnits::deg);
  Drivetrain.driveFor(forward, 50, distanceUnits::in, 75, velocityUnits::pct);

  //Turns to red goal and fires
  Drivetrain.turnFor(right, 110, rotationUnits::deg);
  indexerFireSkills();

  //Turns back to far corner and drives there for expansion
  Drivetrain.turnFor(left, 60, rotationUnits::deg);
  Drivetrain.driveFor(reverse, 50, distanceUnits::in, 75, velocityUnits::pct);
  Drivetrain.turnFor(right, 15, rotationUnits::deg);
}

void autonSkillsBackup(void){
  startFlyWheel(65);
  rollerTime(300);
  //moveForwardTime(200);
  //wait(100, timeUnits::msec);
  //visionTurn();
  startIntake();
  moveForwardTime(500);
  turnRightTime(500);
  stopIntake();
  moveBackwardTime(815);
  rollerTime(300);
  moveForwardTime(200);
  turnLeftTime(490);
  moveForwardTime(1250);
  indexerFireSkills();
  moveBackwardTime(770);
  turnLeftTime(666);
  startIntake();
  moveBackwardTime(1950);
  stopIntake();
  turnRightTime(500);
  //visionTurn();
  indexerFireSkills();
  turnLeftTime(450);
  startIntake();
  moveBackwardTime(1800);

  /*
  startFlyWheel(62);
  rollerTime(300);
  //moveForwardTime(200);
  //wait(100, timeUnits::msec);
  //visionTurn();
  startIntake();
  //moveForwardTime(700);
  Drivetrain.driveFor(reverse, 17, distanceUnits::in, 75, velocityUnits::pct);
  wait(150, timeUnits::msec);
  Drivetrain.turnFor(right, 90, rotationUnits::deg);
  //turnRightTime(600);
  wait(150, timeUnits::msec);
  moveBackwardTime(915);
  rollerTime(300);
  stopIntake();
  Drivetrain.driveFor(reverse, 10, distanceUnits::in);
  //moveForwardTime(200);
  wait(150, timeUnits::msec);
  Drivetrain.turnFor(left, 92, rotationUnits::deg);
  //turnLeftTime(490);
  wait(150, timeUnits::msec);
  moveForwardTime(1250);
  //Drivetrain.driveFor(reverse, 24, distanceUnits::in);



  indexerFireSkills();
  //moveBackwardTime(770);
  Drivetrain.driveFor(forward, 22, distanceUnits::in, 55, velocityUnits::pct);
  //turnLeftTime(666);
  Drivetrain.turnFor(left, 133, rotationUnits::deg);

  startIntake();
  Drivetrain.driveFor(forward, 55, distanceUnits::in, 75, velocityUnits::pct);
  //moveBackwardTime(1950);
  stopIntake();
  Drivetrain.turnFor(right, 93, rotationUnits::deg);

  //turnRightTime(500);
  //visionTurn();
  indexerFireSkills();

  turnLeftTime(450);
  startIntake();
  moveBackwardTime(1800);
  */
}