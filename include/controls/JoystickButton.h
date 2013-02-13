#ifndef JOYSTICKBUTTON_H
#define JOYSTICKBUTTON_H

#include <SDL_joystick.h>

#include "Button.h"
#include "Joysticks.h"

// Classe représentant un bouton d'un joystick.

class JoystickButton : public Button
{
public:
	JoystickButton(joystick_id jid, jbutton_id bid);
	JoystickButton(JoystickButton const& other);
	JoystickButton& operator=(JoystickButton const& other);
	virtual ~JoystickButton();

	virtual bool poll() const;

private:
	SDL_Joystick *m_joystick;
	jbutton_id m_button;
};

#endif // JOYSTICKBUTTON_H
