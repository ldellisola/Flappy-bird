
#include "keyboard_mouse.h"

void registerControlEventSources(ALLEGRO_EVENT_QUEUE * queue)
{
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());

}

void installControl(void)
{
	al_install_keyboard();
	al_install_mouse();
}

int manageEvents(ALLEGRO_EVENT * ev, bool gameMenu)
{
	int retCode = UNKNOWN;

	switch (ev->type)
	{
		case ALLEGRO_EVENT_DISPLAY_CLOSE :
			retCode = ENDGAME;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			if (gameMenu)
			{ 
			}
			else {
				switch (ev->keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					retCode = ENDGAME;
					break;
				case ALLEGRO_KEY_SPACE:
					retCode = JUMP;
					break;
				}
			}
			
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if(!gameMenu)
				retCode = ENDJUMP;
			break;
		case ALLEGRO_EVENT_TIMER:
			if (!gameMenu)
				retCode = TIME;
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (gameMenu)
				retCode = MOUSE;
			break;
	}
	return retCode;
}