#ifndef JOYSTICKAXIS_H
#define JOYSTICKAXIS_H

#include <SDL_joystick.h>

#include "util/math_utils.h"
#include "controls/Axis.h"
#include "controls/Joysticks.h"

// Classe représentant un axe d'un joystick.

class JoystickAxis : public Axis
{
public:
	JoystickAxis(joystick_id jid, jaxis_id aid);
	JoystickAxis(JoystickAxis const& other);
	JoystickAxis& operator=(JoystickAxis const& other);
	virtual ~JoystickAxis();

	virtual float poll() const;

private:
	SDL_Joystick *m_joystick;
	jaxis_id m_axis;
};

#endif // JOYSTICKAXIS_H
