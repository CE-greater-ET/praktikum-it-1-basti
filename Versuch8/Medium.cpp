/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
 
#include "Medium.h"

#include <string>
#include <iostream>

using namespace std;

unsigned int Medium::currentID = 1;

Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}


void Medium::ausgabe(ostream& outStream) const
{
	outStream << "ID: " << ID << std::endl;
	outStream << "Titel: " << titel << std::endl;

    if (status)
    {
    	outStream << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
    	outStream << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurückgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

unsigned int Medium::getID()
{
    return ID;
}

bool Medium::getStatus()
{
    return status;
}


ostream& operator<<(ostream& outStream, const Medium& ausgabeMedium) {

	ausgabeMedium.ausgabe(outStream);
	return outStream;
}
