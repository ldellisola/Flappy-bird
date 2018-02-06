#include "tube.h"



tube::tube(float tubeWidth, ALLEGRO_COLOR tubeColor,float gap, float tubeVelocity, float offset)
{
	lowerBottom = al_get_bitmap_height(al_get_target_bitmap());
	top = rand() % (int) (lowerBottom - gap);
	upperTop = 0;
	bottom = top + gap;
	width = tubeWidth;
	color = tubeColor;
	x = al_get_bitmap_width(al_get_target_bitmap()) + offset;
	velocity = tubeVelocity;
	isPointAvailable = true;
}

void tube::move()
{
	x -= velocity;
}

void tube::draw()
{
	al_draw_filled_rectangle(x, upperTop, x + width, top, color);
	al_draw_filled_rectangle(x, lowerBottom, x + width, bottom, color);
}

bool tube::isItOnScreen()
{
	bool valid = true;
	if ((this->x + this->width) < 0)
		valid = false;
	return valid;
}

void tube::startOver(float gap, float offset)
{
	x = al_get_bitmap_width(al_get_target_bitmap()) + offset;
	top = rand() % (int)(al_get_bitmap_height(al_get_target_bitmap()) - gap);
	bottom = top + gap;
	isPointAvailable = true;
}

bool tube::checkCollision(float circleX, float circleY, int radius)
{
	bool valid = false;

	int caseXOne = abs((int)(circleX - x));
	int caseXTwo = abs((int)(circleX - x - width));
	bool caseXThree = (((x < circleX) && (circleX < x + width)) ? true : false);

	bool caseYOne = (((circleY + radius) > bottom) ? true : false);
	bool caseYTwo = (((circleY - radius) < top) ? true : false);

	if ((caseXOne < radius) || (caseXTwo < radius) || (caseXThree))
		if ((caseYOne) || (caseYTwo))
			valid = true;
			

	
	return valid;
}

bool tube::checkIfPoint(float CircleX, float circleY)
{
	bool point = false;
	if ((CircleX > this->x) && (CircleX < (this->x + this->width)))
		if( (circleY < bottom) && (circleY > top) )
			point = true;
	return point;
}

bool tube::canScore()
{
	return this->isPointAvailable;
}

void tube::takePoint()
{
	this->isPointAvailable = false;
}





