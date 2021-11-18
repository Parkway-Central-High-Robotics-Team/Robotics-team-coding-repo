# VEX V5 Python Project
import sys
import vex
import math
from vex import *

#region config
brain       = vex.Brain()
motor_right = vex.Motor(vex.Ports.PORT15, vex.GearSetting.RATIO18_1, True)
motor_left  = vex.Motor(vex.Ports.PORT16, vex.GearSetting.RATIO18_1, False)
dt          = drivetrain.Drivetrain(motor_left, motor_right, 319.1764, 292.1, vex.DistanceUnits.MM, 1)
#endregion config

#set our standard velocity
dt.set_velocity(20, vex.VelocityUnits.PCT)
#advance four feet
dt.drive_for(vex.DirectionType.FWD, 48, vex.DistanceUnits.IN)
sys.sleep(1)
#retreat two feet
dt.drive_for(vex.DirectionType.REV, 24, vex.DistanceUnits.IN)
sys.sleep(1)
#set velocity a bit slower for more precision
dt.set_velocity(10, vex.VelocityUnits.PCT)
#turn to face a spot four feet to the right and two feet ahead
#the result of calculating that angle has to be converted from radians to degrees by
#multiplying by 180/pi
dt.turn_for(vex.TurnType.RIGHT, (math.atan(float(48) / 24) / math.pi * 180), vex.RotationUnits.DEG)
sys.sleep(1)
#increase velocity again
dt.set_velocity(20, vex.VelocityUnits.PCT)
#drive along the hypotenuse of the triangle we used to compute our turn
#if the length of the triangle's sides are a, b, and c, they are related by
#a^2 + b^2 = c^2, so c, the side we want, is the square root of a^2 + b^2
dt.drive_for(vex.DirectionType.FWD, (math.sqrt(24 * 24 + 48 * 48)), vex.DistanceUnits.IN)
#after finishing a driveFor or turnFor command, the motors will stop in Hold
#mode. To make them relax, you must explicitly stop them with another brakeType.
dt.stop(BrakeType.coast);
