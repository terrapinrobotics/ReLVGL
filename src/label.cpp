#include "relvgl/label.h"   
#include "pros/apix.h"

Label::Label(const char* text, lv_coord_t x, lv_coord_t y) : label(lv_label_create(lv_scr_act())), LVObject(label) {
    // init object
    LVObject::initObject();
    LVObject::setPos(x, y);
    lv_label_set_text(label, text);
}

void Label::setColor(lv_color_t color) {
    // set the color
    lv_style_set_text_color(getStyle(), color);
}

void Label::setColor(const uint32_t color) {
    // set the color
    lv_style_set_text_color(getStyle(), lv_color_hex(color));
}

void Label::setText(const char* text) {
    // set the text
    lv_label_set_text(label, text);
}

void Label::setTextAlign(lv_text_align_t align) {
    // set the text alignment
    lv_style_set_text_align(getStyle(), align);
}

void Label::setDecoration(lv_text_decor_t decor) {
    // set the decorations
    lv_style_set_text_decor(getStyle(), decor);
}

void Label::setFont(const lv_font_t* font) {
    // set the font
    lv_style_set_text_font(getStyle(), font);
}