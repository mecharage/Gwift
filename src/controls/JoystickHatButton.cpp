#include "controls/JoystickHatButton.h"

#include "controls/Joysticks.h"

JoystickHatButton::JoystickHatButton(joystick_id jid, hat_id hid, Uint8 state) :
m_joystick(Joysticks::get(jid)),
m_hatId(hid),
m_state(state) { }

JoystickHatButton::JoystickHatButton(JoystickHatButton const& other) :
m_joystick(other.m_joystick),
m_hatId(other.m_hatId),
m_state(other.m_state) { }

JoystickHatButton& JoystickHatButton::operator=(JoystickHatButton const& other)
{
	m_joystick = other.m_joystick;
	m_hatId = other.m_hatId;
	m_state = other.m_state;
	return *this;
}

JoystickHatButton::~JoystickHatButton() { }

bool JoystickHatButton::poll() const
{
	Uint8 state = SDL_JoystickGetHat(m_joystick, m_hatId);
	return (state || !m_state) && (state | m_state) == m_state;
}
