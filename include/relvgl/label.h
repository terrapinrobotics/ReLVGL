#pragma once

#include "relvgl/object.h"

class Label : public LVObject {
public:
    Label(const char* text, lv_coord_t x = 0, lv_coord_t y = 0);

    // set color
    void setColor(lv_color_t color) override;
    void setColor(const uint32_t color) override;

    // set text
    void setText(const char* text);

    // set text allignment
    void setTextAlign(lv_text_align_t align);

    // set decorations
    void setDecoration(lv_text_decor_t decor);

    // set font
    void setFont(const lv_font_t* font);

private:
    lv_obj_t* label;
    lv_style_t* getStyle() {
        return LVObject::getStyle();
    }
};