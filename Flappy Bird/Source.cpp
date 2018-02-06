#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>
#include <stdint.h>
#include "bird.h"
#include "tube.h"
#include "keyboard_mouse.h"
#include "game.h"
#include "scoreboard.h"
#include "button.h"

// Display Constants
#define HEIGHT	1000
#define WIDTH	2000
#define REFRESH 30
#define DISPLAYCOLOR "black"

enum {ALLEGRO, DISPLAY,TIMER,PRIMITIVES,EVENT_QUEUE};
#define TOTAL  (EVENT_QUEUE + 1)

// Font Constants
#define FONTFILE "poke_font.ttf"

void setAllBoolElements(bool * arr, bool value, int size);
bool isArrayValid(bool * arr, int size);

int main(void)
{
	srand(time(NULL));

	// Allegro Pointers
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE * event_queue = NULL;
	ALLEGRO_TIMER * timer1 = NULL;
	
	bool valid_init[TOTAL];
	setAllBoolElements(valid_init, false,TOTAL);

	//Usefull variables
	int gap = 600;
	bool done = false;
	bool draw = true;
	bool keyboard = false;
	bool gameMenu = true;
	

	
	// Setup
	
	if (al_init())
	{
		valid_init[ALLEGRO] = true;

		installControl(); //Keyboard_and_mouse

		al_init_ttf_addon();

		if (display = al_create_display(WIDTH, HEIGHT))
		{
			valid_init[DISPLAY] = true;
			if (al_init_primitives_addon())
				valid_init[PRIMITIVES] = true;
		}

		if (event_queue = al_create_event_queue())
		{
			valid_init[EVENT_QUEUE] = true;
		}

		if (timer1 = al_create_timer(1.0 / REFRESH))
		{
			valid_init[TIMER] = true;
		}

		
	}


	// Objects
	bird flappy(FLAPPYSTARTINGX, FLAPPYSTARTINGY, FLAPPYRADIUS, FLAPPYBOOST);
	tube firstTube(TUBEWIDTH, al_color_name(TUBECOLOR), gap, TUBEVELOCITY, 0);
	tube secondTube(TUBEWIDTH, al_color_name(TUBECOLOR), gap, TUBEVELOCITY, TUBEOFFSET);
	scoreboard board(SCOREBOARDPOSITIONX, SCOREBOARDPOSITIONY, SCOREBOARDWIDTH, SCOREBOARDHEIGHT, FONTFILE, SCOREBOARDFONTSIZE, SCOREFILE);
	button startGame(STARTBUTTONX, STARTBUTTONY, STARTBUTTONHEIGHT, STARTBUTTONWIDTH, STARTBUTTONCOLOR, FONTFILE, STARTBUTTONFONTSIZE, STARTBUTTONFONTCOLOR, STARTBUTTONNAME);
	button quit(QUITBUTTONX, QUITBUTTONY, QUITBUTTONHEIGHT, QUITBUTTONWIDTH, QUITBUTTONCOLOR, FONTFILE, QUITBUTTONFONTSIZE, QUITBUTTONFONTCOLOR, QUITBUTTONNAME);
		

	// Main program
	if (isArrayValid(valid_init, TOTAL))
	{
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer1));
		registerControlEventSources(event_queue); //Keyboard_and_mouse

		al_start_timer(timer1);
		board.updateBoard();

		while (!done)
		{
			if (!gameMenu && !firstTube.isItOnScreen())
				firstTube.startOver(gap, 0);
			if (!gameMenu && !secondTube.isItOnScreen())
				secondTube.startOver(gap,0 );


			ALLEGRO_EVENT event;
			al_get_next_event(event_queue, &event);

			switch (manageEvents(&event, gameMenu))//Keyboard_and_mouse
			{
			case UNKNOWN:
				// If this ever happens, good luck future Lucas
				break;
			case ENDGAME:
				done = true;
				draw = false;
				break;
			case JUMP:
				keyboard = true;
				break;
			case ENDJUMP:
				keyboard = false;
				break;
			case MOUSE:
				if (quit.mouseClick(event.mouse.x, event.mouse.y))
					done = true;
				else if (startGame.mouseClick(event.mouse.x, event.mouse.y))
				{
					gameMenu = false;
					startOver(&flappy, FLAPPYSTARTINGX, FLAPPYSTARTINGY, &board, &firstTube, &secondTube, gap,TUBEOFFSET );
				}
				draw = false;

				break;
			case TIME:
				if (al_event_queue_is_empty(event_queue))
				{
					updateObjects(GRAVITY, &flappy, &firstTube, &secondTube,HEIGHT);
					if (collision(&flappy, &firstTube, &secondTube, HEIGHT))
						gameMenu = true;		// bird hits anything
					else 
						updateScore(&firstTube, &secondTube, &flappy, &board);
					draw = true;
				}

				if (keyboard)
				{
					keyboard = false;
					flappy.jump();
				}
				break;
			}
			if (draw && al_event_queue_is_empty(event_queue))
			{
				draw = false;
				if (gameMenu)
					drawMenu(&startGame, &quit, &board, DISPLAYCOLOR);
				else
					drawObjects(&flappy, &firstTube, &secondTube,&board, DISPLAYCOLOR );
			}
		}


	}


	if (valid_init[DISPLAY])
		al_destroy_display(display);
	if (valid_init[EVENT_QUEUE])
		al_destroy_event_queue(event_queue);
	if (valid_init[TIMER])
		al_destroy_timer(timer1);
	

}



void setAllBoolElements(bool * arr, bool value, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = value;
}

bool isArrayValid(bool * arr, int size)
{
	bool ret_value = true;;
	for (int i = 0; i < size; ++i)
	{
		if (!arr[i])
		{
			ret_value = false;
		}
	}
	return ret_value;
}
