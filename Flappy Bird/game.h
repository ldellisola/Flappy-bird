#pragma once

#include <allegro5\allegro.h>
#include "bird.h"
#include "tube.h"
#include "button.h"
#include "scoreboard.h"

void updateObjects(float gravity, bird * flappy, tube * firstTube, tube * secondTube, float height);

bool collision(bird * flappy, tube * firstTube, tube * secondTube, float height);

void drawObjects(bird * flappy, tube * firstTube, tube * secondTube, scoreboard * board, char * displayColor);

void drawMenu(button * start, button * quit, scoreboard * board, char * displayColor);

void updateScore(tube * firstTube, tube * secondTube, bird * flappy, scoreboard * board);

void startOver(bird * flappy, float flappyStartX, float flappyStartY, scoreboard * board, tube * firstTube, tube * secondTube, int gap, float offset);
