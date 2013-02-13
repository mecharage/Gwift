#ifndef JOYSTICKHATAXIS_H
#define JOYSTICKHATAXIS_H

#include "Axis.h"
#include "Joysticks.h"

#include <SDL_joystick.h>

// Classe représentant la position d'un POV en tant qu'axe.
// La valeur retournée varie de 0 à 315 dans le sens direct par paliers de 45.
// Elle vaut -1 lorsque le POV est au repos.

class JoystickHatAxis : public Axis
{
public:
	JoystickHatAxis(joystick_id jid, hat_id hid);
	JoystickHatAxis(JoystickHatAxis const& other);
	JoystickHatAxis& operator=(JoystickHatAxis const& other);
	virtual ~JoystickHatAxis();

	virtual float poll() const;

private:
	SDL_Joystick *m_joystick;
	hat_id m_hatId;
};

#endif // JOYSTICKHATAXIS_H
