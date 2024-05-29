/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.h
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "Datum.h"
#include "Person.h"

/*! \brief Basisklasse f�r s�mtliche Medien
*
* Diese Klasse stellt eine Basisklasse f�r Objekte dar, die Medien beschreiben
* Von dieser Klasse werden alle anderen Medien, wie z.B. Buch oder DVD abgeleitet
*/
class Medium
{
public:
    /*!
     * @brief Konstruktor
     *
     * Konstruktor der Klasse Medium
     *
     * \param std::string initTitel: Titel des Mediums
     */
    Medium(std::string initTitel);

    /*!
     * @brief virtueller Destruktor
     */
    virtual ~Medium(void);

    /*!
     * @brief Ausgabefunktion
     *
     * Funktion gibt alle Informationen eines Mediums auf der Konsole aus
     */
    void ausgabe() const;

    /*!
     * @brief Ausleihen-Funktion
     *
     * \param Person person: Person die das Medium ausleihen m�chte
     * \param Datum ausleihdatum: Datum an dem das Medium ausgeliehen wird
     *
     * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und das Medium ausgeliehen werden kann
     *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und das Medium nicht ausgeliehen werden kann
     */
    bool ausleihen(Person person, Datum ausleihdatum);

    /*!
     * @brief Gibt ein Medium in die B�cherei zur�ck
     */
    void zurueckgeben();

    /*!
     * @brief ID des Mediums
     *
     * \return int: gibt die ID des Mediums zur�ck
     */
    unsigned int getID();

protected:
    /*!
     * @brief Statische Variable zum Erzeugen der fortlaufenden IDs
     */
    static unsigned int currentID;
     
    /*!
     * @brief Eindeutige ID des Mediums
     */
    unsigned int ID;

    /*!
     * @brief Titel des Mediums
     */
    std::string titel;

    /*!
     * @brief Status des Mediums (true: ausgeliehen, false: nicht ausgeliehen)
     */
    bool status;

    /*!
     * @brief Datum seit dem das Medium ausgeliehen ist
     */
    Datum datumAusgeliehen;

    /*!
     * @brief Person, die das Medium ausgeliehen hat
     */
    Person personAusgeliehen;

};
#endif
