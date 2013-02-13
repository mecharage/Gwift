#include "controls/JoystickButton.h"

JoystickButton::JoystickButton(joystick_id jid, jbutton_id bid) :
m_joystick(Joysticks::get(jid)),
m_button(bid) { }

JoystickButton::JoystickButton(JoystickButton const& other) :
m_joystick(other.m_joystick),
m_button(other.m_button) { }

JoystickButton& JoystickButton::operator=(JoystickButton const& other)
{
	m_joystick = other.m_joystick;
	m_button = other.m_button;
	return *this;
}

JoystickButton::~JoystickButton() { }

bool JoystickButton::poll() const
{
	return SDL_JoystickGetButton(m_joystick, m_button);
}
