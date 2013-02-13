#ifndef MOUSEBUTTON_H
#define MOUSEBUTTON_H

#include "Button.h"
#include "util/types.h"

#include <SDL_types.h>

typedef ubyte mouse_button;

// Classe représentant un bouton de la souris.

class MouseButton : public Button
{
	friend class Controls;
public:
	// Ordre classique des boutons, le bouton gauche porte le numéro 1.
	MouseButton(mouse_button button);
	virtual ~MouseButton();

	static void update();

protected:
	virtual bool poll() const;

private:
	Uint8 m_button;

	static Uint8 m_MouseState;
};

#endif // MOUSEBUTTON_H
