/*
 * Buch.cpp
 *
 *  Created on: 29 May 2024
 *      Author: bastian
 */

#include "Buch.h"

using namespace std;

Buch::Buch(std::string initTitel, std::string initAutor):
	Medium(initTitel),
	autor(Person(initAutor, Datum())) {
	// TODO Auto-generated constructor stub

}

void Buch::ausgabe() const {

	Medium::ausgabe();

	cout << "Name des Autors: " << this->autor.getName() << endl;

}

Buch::~Buch() {
	// TODO Auto-generated destructor stub
}

