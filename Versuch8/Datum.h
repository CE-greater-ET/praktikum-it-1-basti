/*!
 * Praktikum Informatik 1 MMXXIV
 *
 * @file Datum.h
 */

#ifndef Datum_H_
#define Datum_H_

#include <string>
#include <iostream>


/*! \brief Klasse für ein Datum
 *
 * Speichert ein Datum, bestehend aus Tag, Monat und Jahr.
 * Die Klasse Datum bietet verschiedene Funktionalitäten/Operatoren
 * die zum Ausgeben/Bearbeiten/Vergleichen von verschiedenen Daten genutzt werden können
 *
 */

class Datum
{
public:
    /*!
     * @brief Standartkonstruktor
     *
     * Initialisiert die Klasse Datum mit dem heutigen Datum
     *
     */
    Datum();

    /*!
     * @brief Konstruktor für ein gegebenes Datum
     *
     * \param int initTag:    gegebener Tag
     * \param int initMonat:  gegebener Monat
     * \param int initJahr:   gegebenes Jahr
     *
     */
    Datum(int initTag, int initMonat, int initJahr);

    /*!
     * @Brief Destruktor
     */
    ~Datum(void);

    /*!
     * @brief Eingabe eines Datums über einen Eingabestream
     *
     * \param std::istream& in: Eingabestream zum Einlesen
     */
    void eingabe(std::istream& in);

    /*!
     * @brief Ausgabe eines Datums über einen Ausgabestream
     *
     * \param std::ostream out: Ausgabestream zum Ausgeben
     */
    void ausgabe(std::ostream& out) const;

    /*!
     * @brief Zuweisungsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite, welches der Ausgangspunkt für die Zuweisung ist
     */
    Datum& operator=(Datum& d);

    /*!
     * @brief Subtraktionsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite
     *
     * \return int: Gibt die Differenz der beiden Monate in Monaten zurück
     */
    int operator-(const Datum d) const;

    /*!
     * @brief Additionsoperator
     *
     * \param const int: anzahlTag Anzahl der Tage, die auf das aktuelle Datum addiert werden sollen
     *
     * \return Datum: Gibt das modifizierte Datum zurück
     */
    Datum operator+(const int anzahlTage) const;

private:
    int tag;
    int monat;
    int jahr;

    /*!
     * @brief Enthält die Anzahl der Tage pro Monat
     */
    static const int tageMonat[12];
};

/*!
 * @brief Überladung des Ausgabestream-Operators für die Klasse Datum
 *
 * \param std::ostream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::ostream&: Rückgabe des Streams auf den das Datum geschrieben wurde
 */
std::ostream& operator<<(std::ostream& out, const Datum& d);

/*!
 * @brief Überladung des Eingabestream-Operators für die Klasse Datum
 *
 * \param std::istream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::istream&: Rückgabe des Streams in den das Datum geschrieben wurde
 */
std::istream& operator >> (std::istream& in, Datum& d);

#endif
