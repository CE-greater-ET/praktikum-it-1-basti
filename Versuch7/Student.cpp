//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(ostream& outStream) const
{
    outStream << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}

/**
 * @brief Vergleichsoperator
 *
 * @return bool Äquivalenz der Matrikelnummern der beiden Studenten
 */
bool Student::operator==(const Student& otherStudent) const {
	if (this->matNr == otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Kleiner-Operator
 *
 * @return bool Relation der Matrikelnummern der beiden Studenten
 */
bool Student::operator<(const Student& otherStudent) const {
	if (this->matNr < otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Größer-Operator
 *
 * @return bool Relation der Matrikelnummern der beiden Studenten
 */
bool Student::operator>(const Student& otherStudent) const {
	if (this->matNr > otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Kleiner-Gleich-Operator
 *
 * @return bool Relation der Matrikelnummern der beiden Studenten
 */
bool Student::operator<=(const Student& otherStudent) const {
	if (this->matNr <= otherStudent.getMatNr()) return true;
	else return false;
}

/**
 * @brief Größer-Gleich-Operator
 *
 * @return bool Relation der Matrikelnummern der beiden Studenten
 */
bool Student::operator>=(const Student& otherStudent) const {
	if (this->matNr >= otherStudent.getMatNr()) return true;
	else return false;
}


/**
 * @brief Ausgabeoperator
 *
 * @param outStream Der Output stream (z.B. Datei oder cout)
 * @param student Student, der ausgegeben werden soll
 * @return Den Manipulierten outStream
 */
ostream& operator<<(ostream& outStream, const Student& student) {
	student.ausgabe(outStream);

	return outStream;
}


