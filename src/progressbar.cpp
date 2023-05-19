#include "relvgl/progressbar.h"
#include "relvgl/display.h"

ProgressBar::ProgressBar(lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h) : bar(lv_bar_create(lv_scr_act())) {
    LVObject::initObject(bar);
    LVObject::setPos(x, y);
    LVObject::setSize(w, h);

    // set the style of the bar indicator
    lv_style_init(&style_indicator);
    lv_obj_add_style(bar, &style_indicator, LV_PART_INDICATOR);
}

void ProgressBar::setProgress(int32_t progress, bool anim) {
    lv_bar_set_value(bar, progress, (anim ? LV_ANIM_ON : LV_ANIM_OFF));
}

void ProgressBar::setColor(lv_color_t color) {
    lv_style_set_bg_color(&style_indicator, color);
}

void ProgressBar::setColor(const uint32_t color) {
    lv_style_set_bg_color(&style_indicator, lv_color_hex(color));
}

void ProgressBar::setBackgroundColor(lv_color_t color) {
    LVObject::setColor(color);
}

void ProgressBar::setBackgroundColor(const uint32_t color) {
    LVObject::setColor(lv_color_hex(color));
}