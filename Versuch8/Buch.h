/*
 * Buch.h
 *
 *  Created on: 29 May 2024
 *      Author: bastian
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium {
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();

	void ausgabe() const;

private:
	Person autor;
};

#endif /* BUCH_H_ */
