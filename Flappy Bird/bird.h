#pragma once
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>

#define MAXSPEED (1)
#define DOUBLEJUMPSPEEDTHRESHOLD (0.0005)

// Bird Constants
#define FLAPPYSTARTINGX (WIDTH / 2)
#define FLAPPYSTARTINGY (HEIGHT / 2)
#define FLAPPYRADIUS (50)
#define FLAPPYBOOST (2)
#define GRAVITY (0.005)

class bird
{
public:
	bird(float xCoord, float yCoord, int radius, float boost);
	void jump();
	void draw();
	void calculateVelocity(float gravity, float height);
	void fall(float height);
	float getXCoord();
	float getYCoord();
	int getRadius();
	void startOver(float x, float y);

private:
	int r;
	float x;
	float y;
	float velocity;
	float birdBoost;


};

