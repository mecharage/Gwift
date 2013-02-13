#include "controls/Controls.h"

#include <vector>
#include <string>
#include <SDL_events.h>

#include "controls/Button.h"
#include "controls/Axis.h"
#include "controls/KeyboardKey.h"
#include "controls/Joysticks.h"
#include "controls/MouseButton.h"

Controls::Controls() :
m_bufferFlipper(0),
m_keys(),
m_axis(),
m_mouseX(0),
m_mouseY(0)
{
	Joysticks::init();
}

Controls::~Controls()
{
	Joysticks::clear();
	for(NamedWrapper<Button> &k : m_keys)
		delete k.wrapped;
	m_keys.clear();
}

button_id Controls::addButton(std::string name, Button *button)
{
	m_keys.push_back(NamedWrapper<Button > (name, button));
	return m_keys.size() - 1;
}

void Controls::bindKey(button_id kid, Button *button)
{
	if(kid < m_keys.size())
	{
		delete m_keys[kid].wrapped;
		m_keys[kid].wrapped = button;
	}
}

axis_id Controls::addAxis(Axis *axis, std::string name)
{
	m_axis.push_back(NamedWrapper<Axis > (name, axis));
	return m_axis.size() - 1;
}

void Controls::bindAxis(axis_id aid, Axis *axis)
{
	if(aid < m_axis.size())
	{
		delete m_axis[aid].wrapped;
		m_axis[aid].wrapped = axis;
	}
}

bool Controls::held(button_id bid) const
{
	if(bid > m_keys.size())
		return false;
	return m_keys[bid].wrapped->m_value[m_bufferFlipper];
}

bool Controls::pressed(button_id bid) const
{
	if(bid > m_keys.size())
		return false;
	return m_keys[bid].wrapped->m_value[m_bufferFlipper] && !m_keys[bid].wrapped->m_value[!m_bufferFlipper];
}

bool Controls::released(button_id bid) const
{
	if(bid > m_keys.size())
		return false;
	return m_keys[bid].wrapped->m_value[!m_bufferFlipper] && !m_keys[bid].wrapped->m_value[m_bufferFlipper];
}

float Controls::value(axis_id aid) const
{
	if(aid > m_axis.size())
		return .0;
	return m_axis[aid].wrapped->m_value;
}

void grabMouse(bool grab)
{
	SDL_WM_GrabInput(grab ? SDL_GRAB_ON : SDL_GRAB_OFF);
}

bool isMouseGrabbed()
{
	return SDL_WM_GrabInput(SDL_GRAB_QUERY) != SDL_GRAB_OFF;
}

void Controls::update()
{
	SDL_PumpEvents();
	m_bufferFlipper = !m_bufferFlipper;

	KeyboardKey::update();
	Joysticks::update();
	MouseButton::m_MouseState = SDL_GetMouseState(&m_mouseX, &m_mouseY);

	for(NamedWrapper<Button> &k : m_keys)
		if(k.wrapped)
			k.wrapped->m_value[m_bufferFlipper] = k.wrapped->poll();

	for(NamedWrapper<Axis> &a : m_axis)
		if(a.wrapped)
			a.wrapped->m_value = a.wrapped->poll();
}
