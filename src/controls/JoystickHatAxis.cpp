#include "controls/JoystickHatAxis.h"

#include "controls/Joysticks.h"

JoystickHatAxis::JoystickHatAxis(joystick_id jid, hat_id hid) :
m_joystick(Joysticks::get(jid)),
m_hatId(hid) { }

JoystickHatAxis::JoystickHatAxis(JoystickHatAxis const& other) :
m_joystick(other.m_joystick),
m_hatId(other.m_hatId) { }

JoystickHatAxis& JoystickHatAxis::operator=(JoystickHatAxis const& other)
{
	m_joystick = other.m_joystick;
	m_hatId = other.m_hatId;
	return *this;
}

JoystickHatAxis::~JoystickHatAxis() { }

float JoystickHatAxis::poll() const
{
	switch(SDL_JoystickGetHat(m_joystick, m_hatId))
	{
		case 0x2:		// E
			return 0;
		case 0x3:		// NE
			return 45;
		case 0x1:		// N
			return 90;
		case 0x9:		// NW
			return 135;
		case 0x8:		// W
			return 180;
		case 0xC:		// SW
			return 225;
		case 0x4:		// S
			return 270;
		case 0x6:		// SE
			return 315;
		default:		// None
			return -1;
	}
}
