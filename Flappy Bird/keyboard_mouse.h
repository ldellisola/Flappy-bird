#pragma once

#include <allegro5\allegro.h>

#define UNKNOWN (0)
#define ENDGAME (1)
#define JUMP (2)
#define ENDJUMP (3)
#define TIME (4)
#define MOUSE (5)

// Installs all allegro addons that involve keyboard or mouse
void installControl(void);

// registers all keyboard/mouse event sources to the event queue
void registerControlEventSources(ALLEGRO_EVENT_QUEUE * queue);

// Recieves an allegro event for keyboard, mouse and timer and then it returns the action that the user wants
// (it wasn't necesary to do this with the timer event but it looks cleaner now)
int manageEvents(ALLEGRO_EVENT * ev, bool gameState);
