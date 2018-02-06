#include "button.h"



button::button(float x, float y, int height, int width, char * buttonColor, char * fontFile, int fontSize,char * fontColor, char * name)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->buttonColor = al_color_name(buttonColor);
	this->fontColor = al_color_name(fontColor);
	this->font = al_load_ttf_font(fontFile, fontSize, 0);
	this->name = name;
}


button::~button()
{
	al_destroy_font(this->font);
}

bool button::mouseClick(float x, float y)
{
	bool click = false;

	if ((this->x <= x) && ((this->x + this->width) >= x))
		if ((this->y <= y) && ((this->y + this->height) >= y))
			click = true;
	return click;
}

void button::draw()
{
	al_draw_rectangle(this->x, this->y, this->x + this->width, this->y + this->height, this->buttonColor, 10);
	al_draw_text(this->font, this->fontColor, this->x + this->width / 2, this->y + this->height / 2, ALLEGRO_ALIGN_CENTER, this->name);
}
