#include "main.h"
#include "relvgl/display.h"
#include "relvgl/label.h"
#include "relvgl/progressbar.h"

Display* display = new Display(lv_color_hex(0x23282D));

ProgressBar* bar;

void setBarPct(void* bar, int32_t pct) {
	((ProgressBar*)bar)->setProgress(pct);
}

// our bar animation (find a better way later)
lv_anim_t bar_anim;
void barAnim() {
	lv_anim_init(&bar_anim);
	lv_anim_set_exec_cb(&bar_anim, setBarPct);
	lv_anim_set_time(&bar_anim, 800);
	lv_anim_set_var(&bar_anim, bar);
	lv_anim_set_values(&bar_anim, 0, 100);
	lv_anim_start(&bar_anim);
}

void initialize() {
	display->init();

	Label* label = new Label("Initializing");
	label->setColor(0xFFFFFF);
	label->setFont(&lv_font_montserrat_32);
	label->setAlign(LV_ALIGN_CENTER, 0, -25);

	/*Label* label2 = new Label("Davis S. | v1.0.0");
	label2->setColor(0xFFFFFF);
	label2->setFont(&lv_font_montserrat_14);
	label2->setAlign(LV_ALIGN_BOTTOM_LEFT, 0, 0);*/

	bar = new ProgressBar(0, 0, 220, 20);
	bar->setAlign(LV_ALIGN_CENTER, 0, 25);
	bar->setColor(0xf5c116);
	bar->setBackgroundColor(0x000000);
	bar->setBackgroundOpacity(LV_OPA_COVER);
	barAnim();
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol() {}