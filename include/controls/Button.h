#ifndef KEY_H
#define KEY_H

// Classe abstraite représentant tout périphérique assimilable à un bouton.

class Button
{
	friend class Controls;
public:
	Button();
	virtual ~Button();

protected:
	// Retourne vrai si le bouton est activé
	virtual bool poll() const = 0;

private:
	bool m_value[2];
};

#endif // KEY_H
