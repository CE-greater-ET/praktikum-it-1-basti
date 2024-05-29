/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Person.cpp
 */
 
#include "Person.h"

// Konstruktor
Person::Person(std::string initName, Datum initGeburtsdatum)
: name(initName)
, geburtsdatum(initGeburtsdatum)
{
}

// Destruktor
Person::~Person()
{
}

// Zugriffsfunktion auf das Geburtsdatum
Datum Person::getGeburtsdatum() const
{
    return geburtsdatum;
}

// Zugriffsfunktion auf den Namen
std::string Person::getName() const
{
    return name;
}
