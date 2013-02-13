#include "controls/Joysticks.h"

uint Joysticks::m_Number;
SDL_Joystick **Joysticks::m_Joysticks;

			 /* static */ void Joysticks::init()
{
	m_Joysticks = NULL;
	if((m_Number = SDL_NumJoysticks()))
	{
		m_Joysticks = new SDL_Joystick*[m_Number];
		for(uint i = 0; i < m_Number; i++)
			m_Joysticks[i] = SDL_JoystickOpen(i);
	}
}

			 /* static */ void Joysticks::clear()
{
	if(m_Joysticks)
	{
		for(uint i = 0; i < m_Number; i++)
			SDL_JoystickClose(m_Joysticks[i]);
		delete[] m_Joysticks;
	}
}

			 /* static */ SDL_Joystick* Joysticks::get(joystick_id id)
{
	if(id < m_Number)
		return m_Joysticks[id];
	return NULL;
}

			 /* static */ void Joysticks::update()
{
	SDL_JoystickUpdate();
}
