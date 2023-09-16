#include "main.h"
#include "liblvgl/misc/lv_style.h"
#include "pros/device.h"
#include "pros/rtos.hpp"
#include "relvgl/display.h"
#include "relvgl/label.h"
#include "relvgl/progressbar.h"

// make controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

Display *display = new Display(lv_color_hex(0x23282D));

ProgressBar *bar;

void setBarPct(void *bar, int32_t pct) {
  ((ProgressBar *)bar)->setProgress(pct);
}

// our bar animation (find a better way later)
lv_anim_t bar_anim;
void barAnim() {
  lv_anim_init(&bar_anim);
  lv_anim_set_exec_cb(&bar_anim, setBarPct);
  lv_anim_set_time(&bar_anim, 800);
  lv_anim_set_var(&bar_anim, bar);
  lv_anim_set_values(&bar_anim, 0, 100);
  lv_anim_start(&bar_anim);
}

void initialize() {
  display->init();

  Label *label = new Label("Initializing");
  label->setColor(0xFFFFFF);
  label->setFont(&lv_font_montserrat_32);
  label->setAlign(LV_ALIGN_CENTER, 0, -25);

  Label *label2 = new Label("Davis S. | v1.0.0");
  label2->setColor(0xFFFFFF);
  label2->setFont(&lv_font_montserrat_14);
  label2->setAlign(LV_ALIGN_BOTTOM_LEFT, 0, 0);

  bar = new ProgressBar(0, 0, 220, 20);
  bar->setAlign(LV_ALIGN_CENTER, 0, 25);
  bar->setColor(0xf5c116);
  bar->setBackgroundColor(0x000000);
  bar->setBackgroundOpacity(LV_OPA_COVER);
  barAnim();

  pros::delay(1000);
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol() {
  // clear the screen
  display->clear();

  // draw header
  Label *title = new Label("Dashboard");
  title->setColor(0xFFFFFF);
  title->setDecoration(LV_TEXT_DECOR_UNDERLINE);
  title->setFont(&lv_font_montserrat_32);
  title->setAlign(LV_ALIGN_TOP_LEFT, 12, 12);

  // make white labels numbered 1-21 and make them accessible outside of the
  // loop via an array
  Label *labels[21];
  for (int i = 0; i < 21; i++) {
    labels[i] = new Label(std::to_string(i + 1).c_str());
    labels[i]->setColor(0xFFFFFF);
    labels[i]->setFont(&lv_font_montserrat_14);
    labels[i]->setAlign(LV_ALIGN_TOP_LEFT, 12, 50 + (i * 20));
  }

  while (true) {
    // loop thru numbers 1-21 for all installed devices and check if they exist
    for (int i = 1; i <= 21; i++) {
      pros::c::v5_device_e_t type = pros::c::get_plugged_type(i);
      if (type == 0 || type == 255) {
        // device doesn't exist, so set the label to red
        labels[i - 1]->setColor(0xFF0000);
      }
    }

    pros::delay(10);
  }
}