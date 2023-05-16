# ReLVGL

**What is ReLVGL?**\
ReLVGL is an LVGL wrapper in the form of a PROS template. It allows you to utilise the object-oriented properties of C++ to efficiently create LVGL applications. If you hate having to manually create and manage LVGL styles, objects, and more, this library is for you! Still not convinced? Check out the examples below.

## Examples
**Hello World**

*Traditional LVGL:*
```cpp
static lv_style_t style_text;

int main() {
    // set display background to black
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_STATE_DEFAULT);

    // initialize our style
    lv_style_init(&style_text);
    lv_style_set_text_color(&style_text, lv_color_white());
    
    // create a label
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello World!");
    lv_obj_add_style(label, &style_text, LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}
```

*ReLVGL:*
```cpp
Display display;

int main() {
    // initialize our display
    display.init();

    // create a label
    Label label("Hello World!");
    label.setAlign(display, LV_ALIGN_CENTER);
}
```

That's half the code! Not only that, it's much more readable. Better yet, adding another label is as simple as creating another `Label` object, like this:

```cpp
Label label2("This is another label");
```

If we want to chnage the font, simply make a call to set the font.

```cpp
label2.setFont(&lv_font_montserrat_28);
```

The same code for two labels in traditional LVGL would look like this:

```cpp
static lv_style_t style_text;
static lv_style_t style_text2;

int main() {
    // set display background to black
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_STATE_DEFAULT);

    // initialize our style
    lv_style_init(&style_text);
    lv_style_set_text_color(&style_text, lv_color_white());

    // initialize our second style
    lv_style_init(&style_text2);
    lv_style_set_text_color(&style_text2, lv_color_white());
    lv_style_set_text_font(&style_text2, &lv_font_montserrat_28);
    
    // create a label
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello World!");
    lv_obj_add_style(label, &style_text, LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // create a second label
    lv_obj_t *label2 = lv_label_create(lv_scr_act());
    lv_label_set_text(label2, "This is another label");
    lv_obj_add_style(label2, &style_text2, LV_STATE_DEFAULT);
}
```

Compared to our identical code, it's far more verbose:

```cpp
Display display;

int main() {
    // initialize our display
    display.init();

    // create a label
    Label label("Hello World!");
    label.setAlign(display, LV_ALIGN_CENTER);

    // create a second label
    Label label2("This is another label");
    label2.setAlign(display, LV_ALIGN_CENTER);
    label2.setFont(&lv_font_montserrat_28);
}
```

**To be clear, I'm NOT bashing LVGL.** LVGL is C-based in the first place, will evidently perform better, and is not *bad* by any means. However, I personally find it much easier to use ReLVGL, and I hope you do too.