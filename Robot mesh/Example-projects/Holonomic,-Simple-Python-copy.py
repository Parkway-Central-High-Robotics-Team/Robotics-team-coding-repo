import vex
import math

#region config
brain             = vex.Brain()
back_right_motor  = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO18_1, True)
back_left_motor   = vex.Motor(vex.Ports.PORT10, vex.GearSetting.RATIO18_1, False)
front_right_motor = vex.Motor(vex.Ports.PORT11, vex.GearSetting.RATIO18_1, True)
front_left_motor  = vex.Motor(vex.Ports.PORT20, vex.GearSetting.RATIO18_1, False)
con               = vex.Controller(vex.ControllerType.PRIMARY)
#endregion config

while True:
  # Get the raw sums of appropriate joystick axes
  front_left = (con.axis3.position(vex.PercentUnits.PCT) + con.axis4.position(vex.PercentUnits.PCT)) + con.axis1.position(vex.PercentUnits.PCT)
  back_left = (con.axis3.position(vex.PercentUnits.PCT) - con.axis4.position(vex.PercentUnits.PCT)) + con.axis1.position(vex.PercentUnits.PCT)
  front_right = (con.axis3.position(vex.PercentUnits.PCT) - con.axis4.position(vex.PercentUnits.PCT)) - con.axis1.position(vex.PercentUnits.PCT)
  back_right = (con.axis3.position(vex.PercentUnits.PCT) + con.axis4.position(vex.PercentUnits.PCT)) - con.axis1.position(vex.PercentUnits.PCT)
  # Find the largest raw sum or 100
  max_raw_value = max([math.fabs(front_left), math.fabs(back_left), math.fabs(front_right), math.fabs(back_right), 100])
  # Scale down each value if there was one larger than
  # 100, otherwise leave them alone
  # The largest value will be scaled down to 100, and
  # the others will be reduced by the same factor
  front_left = (float(front_left) / max_raw_value) * 100
  back_left = (float(back_left) / max_raw_value) * 100
  front_right = (float(front_right) / max_raw_value) * 100
  back_right = (float(back_right) / max_raw_value) * 100
  # Write the scaled sums out to the various motors
  front_left_motor.spin(vex.DirectionType.FWD, front_left, vex.VelocityUnits.PCT)
  back_left_motor.spin(vex.DirectionType.FWD, back_left, vex.VelocityUnits.PCT)
  front_right_motor.spin(vex.DirectionType.FWD, front_right, vex.VelocityUnits.PCT)
  back_right_motor.spin(vex.DirectionType.FWD, back_right, vex.VelocityUnits.PCT)
