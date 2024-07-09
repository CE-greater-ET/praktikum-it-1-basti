/*
 * DVD.h
 *
 *  Created on: 30 May 2024
 *      Author: bastian
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

using namespace std;

class DVD: public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	/**
	 * @brief Markiert die DVD als ausgeliehen, falls nicht bereits ausgeliehen
	 *
	 * @param person Die Person, an die ausgeliehen werden soll
	 * @param ausleihdatum Das Datum, zu dem ausgeliehen wird
	 * @return bool Ob das Ausleihen erfolgreich war
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;

	/**
	 * @brief Gibt die DVD aus
	 * @param outStream Der Outstream, in den ausgegeben werden soll
	 */
	void ausgabe(ostream& outStream = cout) const override;

private:
	int altersfreigabe;
	string genre;
};

#endif /* DVD_H_ */
