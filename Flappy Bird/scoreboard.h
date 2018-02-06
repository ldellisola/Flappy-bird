#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_color.h>
#include "file_handler.h"

// Scoreboard Constants
#define SCOREBOARDPOSITIONX (0)
#define SCOREBOARDPOSITIONY (0)
#define SCOREBOARDWIDTH (400)
#define SCOREBOARDHEIGHT (250)
#define SCOREBOARDFONTSIZE (100)
#define SCOREFILE "score.txt"

class scoreboard
{
private:
	ALLEGRO_BITMAP * board;
	float x;
	float y;
	float width;
	float height;
	ALLEGRO_FONT * font;
	int score;
	char * scoreString;
	int highScore;
	char * highscoreString;
	char * file;
	
	
	
public:
	scoreboard(float x, float y, float width, float height, char * fontFile, float fontSize, char * file);
	~scoreboard();
	void increaseScore();
	void updateHighScore();
	void draw();
	void updateBoard();
	void showHighScore();
	void startOver();
};

