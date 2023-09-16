#pragma once

// ReLVGL display object
#include "liblvgl/lvgl.h"

class Display {
public:
    explicit Display(lv_color_t bg_color = lv_color_black());

    // init the display
    void init();

    // clear the display
    void clear();

    // set the background color as a hex value
    void setBackgroundColor(uint32_t color_hex);

    // set the background color as an lv_color_t
    void setBackgroundColor(lv_color_t color);

private:
    lv_color_t bg_color;
};