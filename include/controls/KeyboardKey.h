#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <SDL_keyboard.h>

#include "Button.h"

// Classe représentant une touche du clavier.

class KeyboardKey : public Button
{
public:
	// Paramètre : une constante de touche clavier, comme définies dans <SDL_keysym.h>.
	KeyboardKey(SDLKey key);
	virtual ~KeyboardKey();

	static void update();

protected:
	virtual bool poll() const;

	SDLKey m_key;

	static Uint8 *m_KbBuffer;
	static int m_KbSize;
};

#endif // KEYBOARDKEY_H
