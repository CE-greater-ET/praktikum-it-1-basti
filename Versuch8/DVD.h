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

	bool ausleihen(Person person, Datum ausleihdatum) override;
	void ausgabe() const override;

private:
	int altersfreigabe;
	string genre;
};

#endif /* DVD_H_ */
