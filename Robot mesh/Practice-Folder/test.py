# VEX V5 Python Project with Competition Template
import sys
import vex
from vex import *
import motor_group
import drivetrain
import smartdrive
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
h
