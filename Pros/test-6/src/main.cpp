#include "main.h"
#define LEFT_FRONT_WHEELS_PORT 8
#define LEFT_BACK_WHEELS_PORT 9
#define RIGHT_FRONT_WHEELS_PORT 2
#define RIGHT_BACK_WHEELS_PORT 3

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");

  pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  pros::Motor left_front_wheels(LEFT_FRONT_WHEELS_PORT);
  pros::Motor left_back_wheels(LEFT_BACK_WHEELS_PORT);
  pros::Motor right_front_wheels(RIGHT_FRONT_WHEELS_PORT);
  pros::Motor right_back_wheels(RIGHT_BACK_WHEELS_PORT);
  pros::lcd::set_text(1, "Autonomous");
  pros::lcd::set_text(2, "Running");
  left_front_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_back_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_front_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_back_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_front_wheels.move_velocity(100);
  left_back_wheels.move_velocity(100);
  right_front_wheels.move_velocity(100);
  right_back_wheels.move_velocity(100);
  pros::delay(1000);
  left_front_wheels.move_velocity(0);
  left_back_wheels.move_velocity(0);
  right_front_wheels.move_velocity(0);
  right_back_wheels.move_velocity(0);
  pros::delay(1000);
  left_front_wheels.move_velocity(-100);
  left_back_wheels.move_velocity(-100);
  right_front_wheels.move_velocity(-100);
  right_back_wheels.move_velocity(-100);
  pros::delay(1000);
  left_front_wheels.move_velocity(0);
  left_back_wheels.move_velocity(0);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
  // std::int32_t pros::Controller::get_analog ( pros::controller_analog_e_t
  // channel ) std::int32_t motor_move ( const std::int8_t voltage )
  // pros::Controller master(pros::E_CONTROLLER_MASTER);

  autonomous();

  pros::Motor left_front_wheel(LEFT_FRONT_WHEELS_PORT);
  pros::Motor right_front_wheel(RIGHT_FRONT_WHEELS_PORT,
                                true); // This reverses the motor
  pros::Motor left_back_wheel(LEFT_BACK_WHEELS_PORT);
  pros::Motor right_back_wheel(RIGHT_BACK_WHEELS_PORT,
                               true); // This reverses the motor
  pros::Controller master(CONTROLLER_MASTER);

  while (true) {
    left_front_wheel.move(master.get_analog(ANALOG_LEFT_Y));
    right_front_wheel.move(master.get_analog(ANALOG_RIGHT_Y));
    left_back_wheel.move(master.get_analog(ANALOG_LEFT_Y));
    right_back_wheel.move(master.get_analog(ANALOG_RIGHT_Y));

    pros::delay(2);
  }
  /*pros::Controller master(pros::E_CONTROLLER_MASTER);
  pros::Motor left_mtr(1);
  pros::Motor right_mtr(2);

  while (true) {
          pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() &
  LCD_BTN_LEFT) >> 2, (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                           (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
          int left = master.get_analog(ANALOG_LEFT_Y);
          int right = master.get_analog(ANALOG_RIGHT_Y);

          left_mtr = left;
          right_mtr = right;
          pros::delay(20);
  }*/
}
