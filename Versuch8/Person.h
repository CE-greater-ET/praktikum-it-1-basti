/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Person.h
 */

#ifndef Person_H_
#define Person_H_

#include "Datum.h"
#include <string>

/*!
 * @brief Klasse Person
 *
 * Die Klasse Person speichert alle relevanten Informationenen einer Person ab,
 * die für die Bücherei relevant sind, dies beinhaltet:
 *  - Name
 *  - Geburtsdatum
 *
 */
class Person
{
public:
    /*!
     * @brief Konstruktor
     *
     * Konstruktor der Klasse Person
     *
     * \param std::string name: Name der Person, Default-Value ist ein leerer String
     * \param Datum initGeburtsdatum: Geburtsdatum der Person, Default-Value ist das aktuelle Datum
     */
    Person(std::string initName = "", Datum initGeburtsdatum = Datum());

    /*!
     * @brief Destruktor
     */
    ~Person();

    /*!
     * @brief Zugriffsfunktion auf den Namen der Person
     *
     * \return std::string: gibt den Namen der Person zurück
     */
    std::string getName() const;

    /*!
     * @brief Zugriffsfunktion auf das Geburtsdatum der Person
     *
     * \return Datum: gibt das Geburtsdautm der Person zurück
     */
    Datum getGeburtsdatum() const;

private:
    std::string name;
    Datum geburtsdatum;
};

#endif

