#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>

// Start Button Constants
#define STARTBUTTONX (100)
#define STARTBUTTONY (HEIGHT/2)
#define STARTBUTTONHEIGHT (400)
#define STARTBUTTONWIDTH (700)
#define STARTBUTTONFONTSIZE (100)
#define STARTBUTTONFONTCOLOR "green"
#define STARTBUTTONCOLOR "white"
#define STARTBUTTONNAME "Start Game"

// Quit Button Constants
#define QUITBUTTONX (1100)
#define QUITBUTTONY (HEIGHT/2)
#define QUITBUTTONHEIGHT (400)
#define QUITBUTTONWIDTH (700)
#define QUITBUTTONFONTSIZE (100)
#define QUITBUTTONFONTCOLOR "red"
#define QUITBUTTONCOLOR "white"
#define QUITBUTTONNAME "Quit"

class button
{
private:
	float x;
	float y;
	int height;
	int width;
	char * name;
	ALLEGRO_COLOR buttonColor;
	ALLEGRO_COLOR fontColor;
	ALLEGRO_FONT * font;
	ALLEGRO_BITMAP * bitmap;

public:
	button(float x, float y, int height, int width, char * color, char * fontFile, int fontSize,char * fontColor, char * name);
	~button();
	bool mouseClick(float x, float y);
	void draw();
};

