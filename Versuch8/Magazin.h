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

	void ausgabe() const override;

private:
	Datum erscheinungsdatum;
	string sparte;
};

#endif /* MAGAZIN_H_ */
