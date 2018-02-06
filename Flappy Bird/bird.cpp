#include "bird.h"





bird::bird(float xCoord, float yCoord, int radius, float boost)
{
	x = xCoord;
	y = yCoord;
	r = radius;
	velocity = 0;
	birdBoost = boost;
}

void bird:: jump()
{
	if (y + r + birdBoost > 0)
	{
		if (velocity <= MAXSPEED)
			if (((velocity > 0) ? velocity : -velocity) >= DOUBLEJUMPSPEEDTHRESHOLD)
				velocity += birdBoost;
			else
				velocity += birdBoost / 20;
		else {
			velocity = MAXSPEED;
		}
	}
}


void bird::draw()
{
	al_draw_filled_circle(x,y,r,al_color_name("hotpink"));
}

void bird::calculateVelocity(float gravity,float height)
{
	if ((y + r) < height)
		if (velocity >= -MAXSPEED)
			velocity -= gravity;
		else
			velocity = -MAXSPEED;
	else
		velocity = 0;
}

void bird::fall(float height)
{
	if (y < height)
		y -= velocity;
	else
	{
		velocity = 0;
		y = height;
	}
	
	if (y > 0)
		y -= velocity;
	else
	{
		velocity = 0;
		y = 0;
	}

}

float bird::getXCoord()
{
	return x;
}

float bird::getYCoord()
{
	return y;
}

int bird::getRadius()
{
	return r;
}

void bird::startOver(float x, float y)
{
	this->x = x;
	this->y = y;
	this->velocity = 0;
}
