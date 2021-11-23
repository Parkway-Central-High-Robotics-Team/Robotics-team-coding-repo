# VEX V5 Python Project with Competition Template
import sys
import vex
import time
import turtle 
from vex import *
import motor_group
import drivetrain
import smartdrive

#region config
brain           = vex.Brain()
left_drive_mtr  = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO18_1, False)
right_drive_mtr = vex.Motor(vex.Ports.PORT2, vex.GearSetting.RATIO18_1, True)
inertial_sensor = vex.Inertial(vex.Ports.PORT3)
vision_sensor   = vex.Vision(vex.Ports.PORT4)
dt              = smartdrive.Smartdrive(left_drive_mtr, right_drive_mtr, inertial_sensor, 319.1764, 292.1, vex.DistanceUnits.MM, 1)
con             = vex.Controller(vex.ControllerType.PRIMARY)
#endregion config


# Creates a competition object that allows access to Competition methods.
competition = vex.Competition()

def pre_auton():
    # All activities that occur before competition start
    # Example: setting initial positions
    pass

def autonomous():
    # Place autonomous code here
    pass

def drivercontrol():
    # Place drive control code here, inside the loop
    while True:
        # This is the main loop for the driver control.
        # Each time through the loop you should update motor
        # movements based on input from the controller.
        pass

# Do not adjust the lines below

# Set up (but don't start) callbacks for autonomous and driver control periods.
competition.autonomous(autonomous)
competition.drivercontrol(drivercontrol)

# Run the pre-autonomous function.
pre_auton()

# Robot Mesh Studio runtime continues to run until all threads and
# competition callbacks are finished.
