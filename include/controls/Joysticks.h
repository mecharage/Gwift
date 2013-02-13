#ifndef JOYSTICKS_H
#define JOYSTICKS_H

#include <SDL_joystick.h>

#include "util/types.h"

// Facteur de conversion de signed short vers float [-1.0, 1.0]
#define AXIS_FACTOR 0.000030517578125

typedef ubyte joystick_id, hat_id, jbutton_id, jaxis_id;

// Classe encpsulant la gestion des joysticks par la SDL.

class Joysticks
{
public:
	static void init();
	// Retourne un pointeur sur le joystick portant cet identifiant. À utiliser à la place de SDL_JoystickOpen().
	static SDL_Joystick* get(joystick_id id);
	static void update();
	static void clear();

private:
	Joysticks();

	static uint m_Number;
	static SDL_Joystick **m_Joysticks;
};

#endif // JOYSTICKS_H
