#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>

// Tube constants
#define TUBECOLOR "white"
#define TUBEOFFSET (WIDTH / 2)
#define TUBEWIDTH (100)
#define TUBEVELOCITY (1)

class tube
{
private:
	float top;
	float upperTop;
	float x;
	float bottom;
	float lowerBottom;
	float width;
	ALLEGRO_COLOR color;
	float velocity;
	bool isPointAvailable;

public:
	tube(float tubeWidth, ALLEGRO_COLOR tubeColor, float gap, float tubeVelocity, float offset);
	void move();
	void draw();
	bool isItOnScreen();
	void startOver(float gap, float offset);
	bool checkCollision(float circleX, float circleY, int radius);
	bool checkIfPoint(float CircleX, float circleY);
	bool canScore();
	void takePoint();
};

