/*
 * Magazin.h
 *
 *  Created on: 30 May 2024
 *      Author: bastian
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

using namespace std;


class Magazin: public Medium {
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();

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
	Datum erscheinungsdatum;
	string sparte;
};

#endif /* MAGAZIN_H_ */
