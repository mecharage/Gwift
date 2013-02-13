#include "util/Vecteur.h"

Vecteur::Vecteur(const float x, const float y) : x(x), y(y) { }

Vecteur::Vecteur(const Vecteur& p) : x(p.x), y(p.y) { }

Vecteur::~Vecteur() { }

Vecteur Vecteur::operator= (const Vecteur& c)
{
	x = c.x;
	y = c.y;
	return *this; //inutile de tester si &c==this : cas rare et sans bug.
}

Vecteur operator| (const Vecteur& incident, const Vecteur& droite)
{
	Vecteur incident_(incident);
	return incident_ |= droite;
}

Vecteur Vecteur::operator|= (const Vecteur& droite)
{
	//facteur est l'inverse de la norme du projeté orthogonal de ce vecteur sur la droite.
	float facteur = (droite.x * x        + droite.y * y)
                  / (droite.x * droite.x + droite.y * droite.y);
	//Le vecteur "facteur*droite" est ainsi le projeté orthogonal du vecteur courant sur droite.
	x = facteur * droite.x;
	y = facteur * droite.y;
	return *this;
}

Vecteur operator>> (const Vecteur& incident, const Vecteur& droite)
{
	Vecteur incident_(incident);
	return incident_ >>= droite;
}

Vecteur operator<< (const Vecteur& droite, const Vecteur& incident)
{
	Vecteur incident_(incident);
	return incident_ >>= droite;
}

Vecteur Vecteur::operator>>= (const Vecteur& droite)
{
	//facteur est le double de l'inverse de la norme du projeté orthogonal de ce vecteur sur la droite.
	float facteur = 2.0f * (droite.x * x        + droite.y * y)
                         / (droite.x * droite.x + droite.y * droite.y);
	//Le vecteur "facteur*droite" est ainsi le projeté orthogonal sur droite, multiplié par 2.
	//Il ne reste plus qu'à calculer le symétrique par rapport à ce projeté = 2*projeté - incident (d'où le "2.0*")
	x = facteur * droite.x - x;
	y = facteur * droite.y - y;
	return *this;
}


/*Distance entre 2 points*/

		   /*static*/ float Point::distance (const Point& a, const Point& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

/*Vecteur Vecteur::normer_safe(Vecteur& defaut){
	float norme=sqrt(x*x + y*y);
	if (norme!=0.0){
		x/=norme;
		y/=norme;
	}else{ //vecteur nul
		x=defaut.x;
		y=defaut.y;
	}
	return *this;
}*/

Vecteur Vecteur::accelerer(const float v) const
{
	float facteur = 1.0f + v / norme();
	return Vecteur(facteur * (*this));
}

float operator^ (const Vecteur& a, const Vecteur& b)
{
	float cosAB = a * b / sqrt(a.normeCarre() * b.normeCarre());
	if ((a & b) >= 0.0f)
	{
		return acos(cosAB);
	}
	else
	{
		return -acos(cosAB);
	}
}

Vecteur Vecteur::rotation(const float a) const
{
	float cosA = cos(a);
	float sinA = sin(a);
	return Vecteur(x * cosA - y*sinA, x * sinA + y * cosA);
}

ostream& operator<< (ostream& os, Vecteur& p)
{
	return os << "(" << p.x << "," << p.y << ")";
}
