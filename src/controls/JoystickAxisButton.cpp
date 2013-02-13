#include "controls/JoystickAxisButton.h"

#include <SDL_joystick.h>

#include "util/math_utils.h"
#include "controls/Joysticks.h"

JoystickAxisButton::JoystickAxisButton(joystick_id jid, jaxis_id aid, float threshold) :
m_joystick(Joysticks::get(jid)),
m_axis(aid),
m_threshold(ABS(threshold)),
m_dir(AXIS_FACTOR * SIGN(threshold)) { }

JoystickAxisButton::JoystickAxisButton(JoystickAxisButton const& other) :
m_joystick(other.m_joystick),
m_axis(other.m_axis),
m_threshold(other.m_threshold),
m_dir(other.m_dir) { }

JoystickAxisButton& JoystickAxisButton::operator=(JoystickAxisButton const& other)
{
	m_joystick = other.m_joystick;
	m_axis = other.m_axis;
	m_threshold = other.m_threshold;
	m_dir = other.m_dir;
	return *this;
}

JoystickAxisButton::~JoystickAxisButton() { }

bool JoystickAxisButton::poll() const
{
	return m_dir * SDL_JoystickGetAxis(m_joystick, m_axis) > m_threshold;
}
