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

private:
    lv_color_t bg_color;
};