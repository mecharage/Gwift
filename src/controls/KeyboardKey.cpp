#include "controls/KeyboardKey.h"

#include <SDL_keyboard.h>

Uint8 *KeyboardKey::m_KbBuffer = NULL;
int KeyboardKey::m_KbSize = 0;

KeyboardKey::KeyboardKey(SDLKey key) :
m_key(key) { }

KeyboardKey::~KeyboardKey() { }

bool KeyboardKey::poll() const
{
	if(m_KbBuffer)
		return m_KbBuffer[m_key];
	return false;
}

void KeyboardKey::update()
{
	m_KbBuffer = SDL_GetKeyState(&m_KbSize);
}
