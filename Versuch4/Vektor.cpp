//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

using namespace std;


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}


/**
 * @brief Eine Funktion, die die Länge des Vektors zurückgibt
 *
 * @return Die Länge des Vektors
 */
double Vektor::laenge() const
{
    return sqrt(x*x+y*y+z*z);
}


/**
 * @brief Eine Funktion, die das Skalarprodukt zweier Vektoren ausgibt
 *
 * @param input Der Vektor, mit dem das Skalaprodukt gebildet werden soll
 *
 * @return Das Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return this->x*input.x + this->y*input.y + this->z*input.z;
}


/**
 * @brief Eine Funktion, die den Winkel zwischen zwei Vektoren ausgibt
 *
 * @param input Der Vektor, mit dem der Winkel berechnet werden soll
 *
 * @return Den Winkel zwischen den beiden Vektoren in Grad
 */
double Vektor::winkel(const Vektor& input) const
{
    return acos((this->skalarProd(input))/(this->laenge()*input.laenge())) * 180 / M_PI;
}


/**
 * @brief Eine Funktion, die zwei Vektoren voneinander subtrahiert
 *
 * @param input Der Vektor, der subtrahiert werden soll
 *
 * @return Den Ergebnisvektor (this - input)
 */
Vektor Vektor::sub(const Vektor& input) const
{
	Vektor returnVektor(
			this->x - input.x,
			this->y - input.y,
			this->z - input.z
		);
    return returnVektor;
}


/**
 * @brief Eine Funktion, um den Vektor um einen Winkel zu drehen
 *
 * @param rad Den Winkel in Radiant, um den der Vektor gedreht werden soll
 */
void Vektor::rotiereUmZ(const double rad)
{

	double newX = cos(rad) * this->x + (-sin(rad) * this->y);
	double newY = sin(rad) * this->x + (cos(rad) * this->y);

	this->x = newX;
	this->y = newY;
}







