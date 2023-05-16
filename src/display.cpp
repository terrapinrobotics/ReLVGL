#include "relvgl/display.h"

Display::Display(lv_color_t bg_color) : bg_color(bg_color) {}

void Display::init() {
    // set bg color to black
    lv_obj_set_style_bg_color(lv_scr_act(), bg_color, LV_STATE_DEFAULT);
}

void Display::clear() {
    // clear the screen
    lv_obj_clean(lv_scr_act());
}