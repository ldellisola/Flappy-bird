#include "scoreboard.h"



scoreboard::scoreboard(float x,float y, float width, float height, char * fontFile, float fontSize, char * file)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->score = 0;
	this->board = al_create_bitmap(this->width, this->height); // Probably should check if this goes through
	this->font = al_load_ttf_font(fontFile, fontSize, 0); //ttf addon MUST be installed

	this->file = file;
	this->highscoreString = (char *)malloc(sizeof(char) * 10);
	read_first_line(this->file, this->highscoreString, 9);
	if (highscoreString[0] == 0)
	{
		delete_file(this->file, "");
		write_first_line("0", this->file);
		read_first_line(this->file, this->highscoreString, 9);
	}
	this->highScore = convert_to_int(this->highscoreString);
	this->scoreString = (char *)malloc(sizeof(char) * 10);
	convert_to_string(this->score, this->scoreString, 9);


}


scoreboard::~scoreboard()
{
	al_destroy_bitmap(this->board);
	al_destroy_font(this->font);
	destroy_string(this->highscoreString);
}

void scoreboard::increaseScore()
{
	this->score++;
	convert_to_string(this->score, this->scoreString, 9);
	if (this->score > this->highScore)
		this->updateHighScore();
	this->updateBoard();

}

void scoreboard::updateHighScore()
{
	this->highScore = this->score;
	convert_to_string(this->highScore, this->highscoreString, 9);

	delete_file(this->file, "");
	write_first_line(this->highscoreString, this->file);
}

void scoreboard::draw()
{
	al_draw_bitmap(this->board, this->x, this->y,0);
}

void scoreboard::updateBoard()
{
	ALLEGRO_BITMAP * current = al_get_target_bitmap();
	
	al_set_target_bitmap(this->board);
	al_clear_to_color(al_color_name("white"));
	al_draw_text(this->font, al_color_name("hotpink"), 0, 0, ALLEGRO_ALIGN_LEFT,  this->scoreString);
	al_set_target_bitmap(current);
}

void scoreboard::showHighScore()
{
	ALLEGRO_BITMAP * current = al_get_target_bitmap();
	al_set_target_bitmap(this->board);
	al_clear_to_color(al_color_name("white"));
	al_draw_text(this->font, al_color_name("hotpink"), 0, 0, ALLEGRO_ALIGN_LEFT, this->highscoreString);
	al_set_target_bitmap(current);
}

void scoreboard::startOver()
{
	this->score = 0;
	convert_to_string(score, this->scoreString, 9);
	this->updateBoard();
}
