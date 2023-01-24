# VEX V5 Python Project
import sys
import vex
from vex import *
import motor_group
import drivetrain
import smartdrive

#region config
brain   = vex.Brain()
motor_1 = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO18_1, False)
motor_2 = vex.Motor(vex.Ports.PORT2, vex.GearSetting.RATIO18_1, True)
dt      = drivetrain.Drivetrain(motor_1, motor_2, 319.1764, 292.1, vex.DistanceUnits.MM, 1)
con     = vex.Controller(vex.ControllerType.PRIMARY)
#endregion config


#motor_1.spin_for(vex.DirectionType.FWD, 1000, vex.RotationUnits.DEG, 100, vex.VelocityUnits.PCT)
#motor_2.spin_for(vex.DirectionType.FWD, 1000, vex.RotationUnits.DEG, 100, vex.VelocityUnits.PCT)

dt.drive(vex.DirectionType.FWD, 1000, vex.VelocityUnits.RPM)
