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

bool DVD::ausleihen(Person person, Datum ausleihdatum) {
	if ((ausleihdatum - person.getGeburtsdatum())  < (this->altersfreigabe * 12)) {
		cout << "Die ausleihende Person ist nicht alt genug für diese DVD." << endl;
		return false;
	} else {
		return Medium::ausleihen(person, ausleihdatum);
	}
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

