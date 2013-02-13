#include "controls/JoystickAxis.h"

#include <SDL_joystick.h>

#include "util/math_utils.h"
#include "controls/Joysticks.h"

JoystickAxis::JoystickAxis(joystick_id jid, hat_id aid) :
m_joystick(Joysticks::get(jid)),
m_axis(aid) { }

JoystickAxis::JoystickAxis(JoystickAxis const& other) :
m_joystick(other.m_joystick),
m_axis(other.m_axis) { }

JoystickAxis& JoystickAxis::operator=(JoystickAxis const& other)
{
	m_joystick = other.m_joystick;
	m_axis = other.m_axis;
	return *this;
}

JoystickAxis::~JoystickAxis() { }

float JoystickAxis::poll() const
{
	return AXIS_FACTOR * SDL_JoystickGetAxis(m_joystick, m_axis);
}
