/*
 * DVD.cpp
 *
 *  Created on: 30 May 2024
 *      Author: bastian
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
	Medium(initTitel),
	altersfreigabe(initAltersfreigabe),
	genre(initGenre) {
}

void DVD::ausgabe() const {
	/*
ID: 2
Titel: Der unsichtbare Dritte
Status: Medium ist zurzeit nicht verliehen.
FSK: ab 12 Jahre
Genre: Action, Krimi
	 */
	Medium::ausgabe();
	cout << "FSK: ab " << this->altersfreigabe << " Jahre" << endl;
	cout << "Genre: " << this->genre << endl;
}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}

