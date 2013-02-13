#ifndef AXIS_H
#define AXIS_H

// Classe abstraite représentant tout périphérique assimilable à un axe.

class Axis
{
	friend class Controls;
public:
	Axis();
	virtual ~Axis();

protected:
	// Retourne la valeur actuelle de l'axe
	virtual float poll() const = 0;

private:
	float m_value;
};

#endif // AXIS_H
