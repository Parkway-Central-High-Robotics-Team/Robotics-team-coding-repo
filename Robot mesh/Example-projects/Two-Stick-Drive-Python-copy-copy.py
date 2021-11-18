# VEX V5 Python Project
import sys
import vex
from vex import *

#region config
brain            = vex.Brain()
left_drive_mtr1  = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO18_1, False)
right_drive_mtr1 = vex.Motor(vex.Ports.PORT2, vex.GearSetting.RATIO18_1, False)
left_drive_mtr2  = vex.Motor(vex.Ports.PORT3, vex.GearSetting.RATIO18_1, False)
right_drive_mtr2 = vex.Motor(vex.Ports.PORT4, vex.GearSetting.RATIO18_1, False)
con              = vex.Controller(vex.ControllerType.PRIMARY)
#endregion config

while True:
  # Left motor, vertical axis of left joystick
  left_drive_mtr1.spin(vex.DirectionType.FWD, (con.axis3.position(vex.PercentUnits.PCT)*10), vex.VelocityUnits.PCT)
  left_drive_mtr2.spin(vex.DirectionType.FWD, (con.axis3.position(vex.PercentUnits.PCT)*10), vex.VelocityUnits.PCT)
  # Right motor, vertical axis of right joystick
  right_drive_mtr1.spin(vex.DirectionType.REV, (con.axis2.position(vex.PercentUnits.PCT)*10), vex.VelocityUnits.PCT)
  right_drive_mtr2.spin(vex.DirectionType.REV, (con.axis2.position(vex.PercentUnits.PCT)*10), vex.VelocityUnits.PCT)
