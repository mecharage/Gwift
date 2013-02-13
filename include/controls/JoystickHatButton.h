#ifndef JOYSTICKHATBUTTON_H
#define JOYSTICKHATBUTTON_H

#include <SDL_joystick.h>

#include "controls/Button.h"
#include "controls/Joysticks.h"

// Classe représentant une position particuli�re d'un POV en tant que bouton.

class JoystickHatButton : public Button
{
public:
	// state est le masque binaire représentant les positions du POV auxquelles réagir.
	// Il s'agit d'un OU binaire des masques SDL_HAT_* déclarés dans <SDL_joystick.h>.
	JoystickHatButton(joystick_id jid, hat_id hid, Uint8 state);
	JoystickHatButton(JoystickHatButton const& other);
	JoystickHatButton& operator=(JoystickHatButton const& other);
	virtual ~JoystickHatButton();

	virtual bool poll() const;

private:
	SDL_Joystick *m_joystick;
	hat_id m_hatId;
	Uint8 m_state;
};

#endif // JOYSTICKHATBUTTON_H
