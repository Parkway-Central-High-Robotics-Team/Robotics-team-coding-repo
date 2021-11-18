import vex
import sys

#region config
brain       = vex.Brain()
motor_arm   = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO18_1, False)
motor_claw  = vex.Motor(vex.Ports.PORT10, vex.GearSetting.RATIO18_1, False)
motor_right = vex.Motor(vex.Ports.PORT15, vex.GearSetting.RATIO18_1, True)
motor_left  = vex.Motor(vex.Ports.PORT16, vex.GearSetting.RATIO18_1, False)
con         = vex.Controller(vex.ControllerType.PRIMARY)
#endregion config

def armthread():
  # Arm thread
  while True:
    if con.buttonL1.pressing():
      motor_arm.spin(vex.DirectionType.FWD, 67, vex.VelocityUnits.PCT)
    elif con.buttonL2.pressing():
      motor_arm.spin(vex.DirectionType.REV, 67, vex.VelocityUnits.PCT)
    else:
      motor_arm.stop(vex.BrakeType.HOLD)
sys.run_in_thread(armthread)

def clawthread():
  # Claw thread
  while True:
    if con.buttonR1.pressing():
      motor_claw.spin(vex.DirectionType.FWD, 50, vex.VelocityUnits.PCT)
    elif con.buttonR2.pressing():
      motor_claw.spin(vex.DirectionType.REV, 50, vex.VelocityUnits.PCT)
    else:
      motor_claw.stop(vex.BrakeType.HOLD)
sys.run_in_thread(clawthread)

def forkedthread():
  i = 0 #this i is local, so different instances of this function use their own copies
  while True:
    sys.sleep(1)
    print i
    i = i+1
#A function can be started as a thread multiple times
sys.run_in_thread(forkedthread)
sys.run_in_thread(forkedthread)

# Drive train thread
while True:
  motor_right.spin(vex.DirectionType.FWD, (con.axis2.position(vex.PercentUnits.PCT)), vex.VelocityUnits.PCT)
  motor_left.spin(vex.DirectionType.FWD, (con.axis3.position(vex.PercentUnits.PCT)), vex.VelocityUnits.PCT)

