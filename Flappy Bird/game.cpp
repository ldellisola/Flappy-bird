#include "game.h"

void updateObjects(float gravity, bird * flappy, tube * firstTube, tube * secondTube, float height)
{
	firstTube->move();
	secondTube->move();
	flappy->fall(height);
	flappy->calculateVelocity(gravity, height);
}

bool collision(bird * flappy, tube * firstTube, tube * secondTube, float height)
{
	bool hit = false;

	if (firstTube->checkCollision(flappy->getXCoord(), flappy->getYCoord(), flappy->getRadius()))
		hit = true;
	else if (secondTube->checkCollision(flappy->getXCoord(), flappy->getYCoord(), flappy->getRadius()))
		hit = true;
	else if ((flappy->getYCoord() + flappy->getRadius()) >= height)
		hit = true;
	else if ((flappy->getYCoord() - flappy->getRadius()) <= 0)
		hit = true;
	return hit;
}

void drawObjects(bird * flappy, tube * firstTube, tube * secondTube, scoreboard * board, char * displayColor)
{
	al_clear_to_color(al_color_name(displayColor));
	firstTube->draw();
	secondTube->draw();
	flappy->draw();
	board->draw();
	al_flip_display();
}

void drawMenu(button * start, button * quit, scoreboard * board, char * displayColor)
{
	board->showHighScore();
	al_clear_to_color(al_color_name(displayColor));
	start->draw();
	quit->draw();
	board->draw();
	al_flip_display();
}

void updateScore(tube * firstTube, tube * secondTube, bird * flappy, scoreboard * board)
{
	if (firstTube->canScore() && firstTube->checkIfPoint(flappy->getXCoord(), flappy->getYCoord()))
	{
		firstTube->takePoint();
		board->increaseScore();
	}
	else if (secondTube->canScore() && secondTube->checkIfPoint(flappy->getXCoord(), flappy->getYCoord()))
	{
		secondTube->takePoint();
		board->increaseScore();
	}
}

void startOver(bird * flappy, float flappyStartX, float flappyStartY, scoreboard * board, tube * firstTube, tube * secondTube, int gap, float offset)
{
	board->startOver();
	firstTube->startOver(gap,0 );
	secondTube->startOver(gap,offset );
	flappy->startOver(flappyStartX, flappyStartY);
}
