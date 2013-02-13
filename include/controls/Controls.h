#ifndef CONTROLS_H
#define CONTROLS_H

#include <vector>
#include <string>

#include "Button.h"
#include "Axis.h"
#include "util/types.h"

typedef ubyte button_id, axis_id;

template <typename T>
struct NamedWrapper
{
	std::string name;
	T *wrapped;

	NamedWrapper(std::string n) : name(n), wrapped(NULL) { }

	NamedWrapper(std::string n, T * w) : name(n), wrapped(w) { }

	NamedWrapper(NamedWrapper const& other) : name(other.name), wrapped(other.wrapped) { }

	NamedWrapper& operator=(NamedWrapper const& other)
	{
		name = other.name;
		wrapped = other.wrapped;
		return *this;
	}
};

// Classe représentant un schéma de contrôles.
// Il est possible de déclarer et nommer des contrôles identifiés par leur id,
// et de les lier à des périphériques physiques de manière transparente.
// Les "boutons" sont des contrôles numériques, activés ou non, les "axes" sont
// des contrôles analogiques retournant une valeur en virgule flottante
// (pas nécessairement entre -1.0 et 1.0, voir les classes Axis concrètes)

class Controls
{
public:
	Controls();
	virtual ~Controls();

	// Ajoute, nomme et lie un bouton, et retourne son id.
	button_id addButton(std::string name, Button *button);

	button_id addButton()
	{
		return addButton("", NULL);
	}

	button_id addButton(Button *button)
	{
		return addButton("", button);
	}

	button_id addButton(std::string name)
	{
		return addButton(name, NULL);
	}
	// Lie un périphérique à un bouton existant.
	void bindKey(button_id bid, Button *button);

	// Ajoute, nomme et lie un axe, et retourne son id.
	axis_id addAxis(Axis *axis = NULL, std::string name = "");

	// Lie un périphérique à un axe existant.
	void bindAxis(axis_id aid, Axis *axis);

	// Retourne true si le bouton est activé.
	bool held(button_id bid) const;
	// Retourne true si le bouton a été activé depuis la dernière frame.
	bool pressed(button_id bid) const;
	// Retourne true si le bouton a été relâché depuis la dernière frame.
	bool released(button_id bid) const;

	// Retourne la valeur de l'axe.
	float value(axis_id aid) const;

	// Restriction du curseur à la fenêtre
	void grabMouse(bool grab);
	bool isMouseGrabbed();

	// Retournent la position de la souris par rapport à la fenêtre.
	int mouseX() const
	{
		return m_mouseX;
	}

	int mouseY() const
	{
		return m_mouseY;
	}

	void update();

private:
	bool m_bufferFlipper;
	std::vector<NamedWrapper<Button> > m_keys;
	std::vector<NamedWrapper<Axis> > m_axis;

	int m_mouseX, m_mouseY;
};

#endif // CONTROLS_H
