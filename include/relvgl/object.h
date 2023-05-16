#pragma once

#include "liblvgl/lvgl.h"

class LVObject {
public:
    void setSize(lv_coord_t w, lv_coord_t h) {
        lv_obj_set_size(obj, w, h);
    }

    void setPos(lv_coord_t x, lv_coord_t y) {
        lv_obj_set_pos(obj, x, y);
    }

    void setAlign(lv_align_t align, lv_coord_t x_offset = 0, lv_coord_t y_offset = 0) {
        lv_obj_align(obj, align, x_offset, y_offset);
    }

    void setStyle(lv_style_t* style, lv_style_selector_t selector = 0) {
        lv_obj_add_style(obj, style, selector);
    }

    lv_style_t* getStyle() {
        return &style;
    }

    virtual void setColor(lv_color_t color) {
        lv_style_set_bg_color(&style, color);
    }

    virtual void setColor(const uint32_t color) {
        lv_style_set_bg_color(&style, lv_color_hex(color));
    }

    void setBorderWidth(lv_coord_t width) {
        lv_style_set_border_width(&style, width);
    }

    void setBorderColor(lv_color_t color) {
        lv_style_set_border_color(&style, color);
    }

    void setBorderColor(const uint32_t color) {
        lv_style_set_border_color(&style, lv_color_hex(color));
    }

    void setBorderRadius(lv_coord_t radius) {
        lv_style_set_radius(&style, radius);
    }

    void setBackgroundOpacity(lv_opa_t opacity) {
        lv_style_set_bg_opa(&style, opacity);
    }

protected:
    LVObject(lv_obj_t* obj) : obj(obj) {
        lv_style_init(&style);
    }

    void initObject() {
        lv_obj_add_style(obj, &style, 0);
    }

private:
    lv_style_t style;
    lv_obj_t* obj;
};