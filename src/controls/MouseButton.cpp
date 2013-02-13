#include "controls/MouseButton.h"

#include <SDL_mouse.h>

Uint8 MouseButton::m_MouseState = 0;

MouseButton::MouseButton(mouse_button button) :
m_button(1 << (button - 1)) { }

MouseButton::~MouseButton() { }

bool MouseButton::poll() const
{
	return m_button & m_MouseState;
}
