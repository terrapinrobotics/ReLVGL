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

void Display::setBackgroundColor(lv_color_t color) {
    // set the background color
    lv_obj_set_style_bg_color(lv_scr_act(), color, LV_STATE_DEFAULT);
    bg_color = color;
}

void Display::setBackgroundColor(uint32_t color_hex) {
    // set the background color
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(color_hex), LV_STATE_DEFAULT);
    bg_color = lv_color_hex(color_hex);
}