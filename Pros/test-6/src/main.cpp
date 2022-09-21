#include "main.h"

#define LVGL_SCREEN_WIDTH 480
#define LVGL_SCREEN_HEIGHT 240

#define LEFT_FRONT_WHEELS_PORT 8
#define LEFT_BACK_WHEELS_PORT 9
#define RIGHT_FRONT_WHEELS_PORT 2
#define RIGHT_BACK_WHEELS_PORT 3

lv_obj_t *myButton;
lv_obj_t *myButtonLabel;
lv_obj_t *myLabel;

lv_style_t myButtonStyleREL; // relesed style
lv_style_t myButtonStylePR;  // pressed style

static lv_res_t btn_click_action(lv_obj_t *btn) {
  uint8_t id =
      lv_obj_get_free_num(btn); // id usefull when there are multiple buttons

  if (id == 0) {
    char buffer[100];
    sprintf(buffer, "button was clicked %i milliseconds from start",
            pros::millis());
    lv_label_set_text(myLabel, buffer);
  }

  return LV_RES_OK;
}

lv_obj_t *createBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y,
                    lv_coord_t width, lv_coord_t height, int id,
                    const char *title) {
  lv_obj_t *btn = lv_btn_create(parent, NULL);
  lv_obj_set_pos(btn, x, y);
  lv_obj_set_size(btn, width, height);
  lv_obj_set_free_num(btn, id);

  lv_obj_t *label = lv_label_create(btn, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

  return btn;
}

lv_style_t *createBtnStyle(lv_style_t *copy, lv_color_t rel, lv_color_t pr,
                           lv_color_t tglRel, lv_color_t tglPr,
                           lv_color_t tglBorder, lv_color_t textColor,
                           lv_obj_t *btn) {
  lv_style_t *btnStyle = (lv_style_t *)malloc(sizeof(lv_style_t) * 4);

  for (int i = 0; i < 4; i++)
    lv_style_copy(&btnStyle[i], copy);

  btnStyle[0].body.main_color = rel;
  btnStyle[0].body.grad_color = rel;
  btnStyle[0].text.color = textColor;

  btnStyle[1].body.main_color = pr;
  btnStyle[1].body.grad_color = pr;
  btnStyle[1].text.color = textColor;

  btnStyle[2].body.main_color = tglRel;
  btnStyle[2].body.grad_color = tglRel;
  btnStyle[2].body.border.width = 2;
  btnStyle[2].body.border.color = tglBorder;
  btnStyle[2].text.color = textColor;

  btnStyle[3].body.main_color = tglPr;
  btnStyle[3].body.grad_color = tglPr;
  btnStyle[3].body.border.width = 2;
  btnStyle[3].body.border.color = tglBorder;
  btnStyle[3].text.color = textColor;

  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);

  return btnStyle;
}

void setBtnStyle(lv_style_t *btnStyle, lv_obj_t *btn) {
  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);
}

void btnSetToggled(lv_obj_t *btn, bool toggled) {
  if (toggled != (lv_btn_get_state(btn) >= 2))
    lv_btn_toggle(btn);
}

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
  // pros::lcd::initialize();
  // pros::lcd::set_text(1, "Hello PROS User!");

  // pros::lcd::register_btn1_cb(on_center_button);
  createBtn(lv_scr_act(), 0, 0, 200, 200, 1, "Fuck you, Baltimore!");
  /* createBtnStyle(&myButtonStyleREL, LV_COLOR_MAKE(150, 0, 0),
                 LV_COLOR_MAKE(0, 0, 150), LV_COLOR_MAKE(0, 150, 0),
                 LV_COLOR_MAKE(150, 0, 0), LV_COLOR_MAKE(0, 0, 150),
                 LV_COLOR_MAKE(0, 150, 0), myButton);
                 // setBtnStyle(&myButtonStyleREL, myButton);*/

  // lv_style_copy(&myButtonStyleREL, &lv_style_plain);
  //  myButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0,
  //  0); myButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0,
  //  150); myButtonStyleREL.body.radius = 0;
  //  myButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

  // lv_style_copy(&myButtonStylePR, &lv_style_plain);
  // myButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
  // myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
  // myButtonStylePR.body.radius = 0;
  // myButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

  // myButton = lv_btn_create(
  //     lv_scr_act(),
  //     NULL); // create button, lv_scr_act() is deafult screen
  //     object
  // lv_obj_set_free_num(myButton, 0); // set button is to 0
  // lv_btn_set_action(
  //     myButton, LV_BTN_ACTION_CLICK,
  //     btn_click_action); // set function to be called on
  //     button click
  // lv_btn_set_style(myButton, LV_BTN_STYLE_REL,
  //                  &myButtonStyleREL); // set the relesed
  //                  style
  // lv_btn_set_style(myButton, LV_BTN_STYLE_PR,
  //                  &myButtonStylePR); // set the pressed style
  // lv_obj_set_size(myButton, 40, 50);  // set the button size
  // lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 0,
  //              0); // set the position to top mid

  // myButtonLabel = lv_label_create(
  //     myButton, NULL); // create label and puts it inside of
  //     the button
  // lv_label_set_text(myButtonLabel, "Click the Button"); //
  // sets label text

  // myLabel = lv_label_create(lv_scr_act(),
  //                           NULL); // create label and puts it
  //                           on the screen
  // lv_label_set_text(myLabel,
  //                   "Button has not been clicked yet"); //
  //                   sets label text
  // lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 10,
  //              0); // set the position to center
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
  /*pros::Motor left_front_wheels(LEFT_FRONT_WHEELS_PORT);
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
  left_back_wheels.move_velocity(0);*/
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

  // autonomous();

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

// static void btn_event_cb(lv_event_t *e) {
//   lv_event_code_t code = lv_event_get_code(e);
//   lv_obj_t *btn = lv_event_get_target(e);
//   if (code == LV_EVENT_CLICKED) {
//     static uint8_t cnt = 0;
//     cnt++;

//     /*Get the first child of the button which is the label and change its
//     text*/ lv_obj_t *label = lv_obj_get_child(btn, 0);
//     lv_label_set_text_fmt(label, "Button: %d", cnt);
//   }
// }

// void lv_example_get_started_1(void) {
//   lv_obj_t *btn =
//       lv_btn_create(lv_scr_act()); /*Add a button the current screen*/
//   lv_obj_set_pos(btn, 10, 10);     /*Set its position*/
//   lv_obj_set_size(btn, 120, 50);   /*Set its size*/
//   lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL,
//                       NULL); /*Assign a callback to the button*/

//   lv_obj_t *label = lv_label_create(btn); /*Add a label to the button*/
//   lv_label_set_text(label, "Button");     /*Set the labels text*/
//   lv_obj_center(label);
// }