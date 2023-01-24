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

front_left = None
back_left = None
front_right = None
back_right = None
max_raw_value = None
max_XYstick_value = None
max_rotating_motor_value = None


# main thread
while True:
    # Get the raw sums of appropriate joystick axes
    front_left = con.axis3.position(vex.PercentUnits.PCT) + con.axis4.position(vex.PercentUnits.PCT)
    back_left = con.axis3.position(vex.PercentUnits.PCT) - con.axis4.position(vex.PercentUnits.PCT)
    front_right = con.axis3.position(vex.PercentUnits.PCT) - con.axis4.position(vex.PercentUnits.PCT)
    back_right = con.axis3.position(vex.PercentUnits.PCT) + con.axis4.position(vex.PercentUnits.PCT)
    # Find the largest possible raw sum
    max_raw_value = math.fabs(con.axis3.position(vex.PercentUnits.PCT)) + math.fabs(con.axis4.position(vex.PercentUnits.PCT))
    # Find the largest joystick value
    max_XYstick_value = max([math.fabs(con.axis3.position(vex.PercentUnits.PCT)), math.fabs(con.axis4.position(vex.PercentUnits.PCT))])
    # The largest value will be scaled down to the
    # largest joystick value, and the others will be
    # scaled by the same amount to preserve direction
    if max_raw_value != 0:
        front_left = (front_left / max_raw_value) * max_XYstick_value
        back_left = (back_left / max_raw_value) * max_XYstick_value
        front_right = (front_right / max_raw_value) * max_XYstick_value
        back_right = (back_right / max_raw_value) * max_XYstick_value
    # Now to consider rotation!
    # Naively add the rotational axis
    front_left = front_left + con.axis1.position(vex.PercentUnits.PCT)
    back_left = back_left + con.axis1.position(vex.PercentUnits.PCT)
    front_right = front_right - con.axis1.position(vex.PercentUnits.PCT)
    back_right = back_right - con.axis1.position(vex.PercentUnits.PCT)
    # Largest, including 100%?
    max_rotating_motor_value = max([math.fabs(front_left), math.fabs(back_left), math.fabs(front_right), math.fabs(back_right), math.fabs(100)])
    # Scale everything down by the factor that
    # makes the largest only 100%
    front_left = (front_left / max_rotating_motor_value) * 100
    back_left = (back_left / max_rotating_motor_value) * 100
    front_right = (front_right / max_rotating_motor_value) * 100
    back_right = (back_right / max_rotating_motor_value) * 100
    # Write the manipulated values out to the motors
    front_left_motor.spin(vex.DirectionType.FWD, front_left, vex.VelocityUnits.PCT)
    back_left_motor.spin(vex.DirectionType.FWD, back_left, vex.VelocityUnits.PCT)
    front_right_motor.spin(vex.DirectionType.FWD, front_right, vex.VelocityUnits.PCT)
    back_right_motor.spin(vex.DirectionType.FWD, back_right, vex.VelocityUnits.PCT)
