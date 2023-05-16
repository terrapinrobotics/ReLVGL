#pragma once

#include "relvgl/object.h"

class ProgressBar : public LVObject {
public:
    ProgressBar(lv_coord_t x = 0, lv_coord_t y = 0, lv_coord_t w = 0, lv_coord_t h = 0);

    void setProgress(int32_t progress, bool anim = true);
    void setColor(lv_color_t color) override;
    void setColor(const uint32_t color) override;
    void setBackgroundColor(lv_color_t color);
    void setBackgroundColor(const uint32_t color);

private:
    lv_obj_t* bar;
    lv_style_t* getStyle() {
        return LVObject::getStyle();
    }

    // the actual bar indicator style
    lv_style_t style_indicator;
};