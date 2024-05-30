/*
 * Magazin.cpp
 *
 *  Created on: 30 May 2024
 *      Author: bastian
 */

#include "Magazin.h"

using namespace std;

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
	Medium(initTitel),
	erscheinungsdatum(initDatumAusgabe),
	sparte(initSparte) {

}

void Magazin::ausgabe() const {
	/*
ID: 1
Titel: c’t - Magazin für Computertechnik
Status: Medium ist zurzeit nicht verliehen.
Ausgabe: 01/04/2018
Sparte: Computerzeitschrift
	 */
	Medium::ausgabe();
	cout << "Ausgabe: " << this->erscheinungsdatum << endl;
	cout << "Sparte: " << this->sparte << endl;
}


Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}
