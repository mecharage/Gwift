#ifndef JOYSTICKAXISBUTTON_H
#define JOYSTICKAXISBUTTON_H

#include <SDL_joystick.h>

#include "util/math_utils.h"
#include "controls/Button.h"
#include "controls/Joysticks.h"

// Classe représentant un axe d'un joystick en tant que bouton.

class JoystickAxisButton : public Button
{
public:
	// threshold définit le seuil (sur [-1, 1]) à partir duquel le bouton réagit.
	// Son signe détermine la direction à laquelle réagir. Un threshold nul ne provoquera jamais de réaction.
	JoystickAxisButton(joystick_id jid, jaxis_id aid, float threshold);
	JoystickAxisButton(JoystickAxisButton const& other);
	JoystickAxisButton& operator=(JoystickAxisButton const& other);
	virtual ~JoystickAxisButton();

	virtual bool poll() const;

private:
	SDL_Joystick *m_joystick;
	jaxis_id m_axis;
	float m_threshold, m_dir;
};

#endif // JOYSTICKAXISBUTTON_H
