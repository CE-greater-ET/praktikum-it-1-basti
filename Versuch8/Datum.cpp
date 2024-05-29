/*!
 * Praktikum Informatik 1 MMXXIV
 *
 * @file Datum.cpp
 */

#include "Datum.h"

#include <time.h>
#include <sstream>


//Instanzierung des tage-Arrays
const int Datum::tageMonat[12] = { 31,30,31,28,31,30,31,31,30,31,30,31 };


//Standardkonstruktor
Datum::Datum()
{
    //aktuelle Zeit einlesen
    time_t aktuelleZeit; 
    time(&aktuelleZeit);

    //Zeiger auf aktuelles Array erstellen
    struct tm* aktuellesDatum = localtime(&aktuelleZeit);

    // Werte zuweisen
    tag   = aktuellesDatum->tm_mday;
    monat = aktuellesDatum->tm_mon + 1;
    jahr  = aktuellesDatum->tm_year + 1900;
}

// Konstruktor
Datum::Datum(int initTag, int initMonat, int initJahr)
: tag(initTag)
, monat(initMonat)
, jahr(initJahr)
{
}

// Destruktor
Datum::~Datum(void)
{
}


// Ausgabe des Datums in einen Ausgabestream
void Datum::ausgabe(std::ostream& out) const
{
    out << tag << ".";

    // Formatierung um z.B. 01 statt 1 ausgeben
    if (monat < 10)
    {
        out << '0';
    }

    out << monat << "." << jahr;
}

// Funktion liest aus einem Eingabestream ein Datum ein
void Datum::eingabe(std::istream& in)
{
    std::string DatumString;

    while (true) // Endlosschleife
    {
        in >> DatumString; //String einlesen
        try
        {
            // Abfangen der falschen L�nge der Eingabe
            if (DatumString.length() != 10)
            {
                throw (std::string("Falsches Format!"));
            }

            // Stringstream zum Umwandeln in Integer-Zahlen
            std::istringstream stringstream;
            stringstream.str(DatumString);

            // Tag einlesen
            stringstream >> tag;

            // Nach dem Tag muss ein Punkt stehen
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Monat einlesen
            stringstream >> monat;

            // �berpr�fen der G�ltigkeit des Monats
            if ((monat < 1) || (monat > 12))
            {
                throw (std::string("Ungültiger Monat!"));
            }

            // �berpr�fen, ob der eigegebene Tag zum Monat passt
            if ((tag > tageMonat[monat - 1]) || (tag < 1))
            {
                throw (std::string("Ungültiger tag!"));
            }

            // Nach dem Monat muss ein Punkt stehen
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Einlesen des Jahrs
            stringstream >> jahr;

            if(jahr < 1000 || jahr > 2021 )
            {
                throw(std::string("Ungültiges Jahr!"));
            }

            //Datum wurde korrekt eingelesen, also Endlosschleife verlassen
            return;
        }
        catch (std::string& fehler)
        {
            std::cout << fehler << std::endl;
            std::cout << "Bitte nochmal eingeben: ";
        }
    }
}


// �berladener Subtraktions-Operator
int Datum::operator-(const Datum datum) const
{
    int tagDiff = tag - datum.tag;
    int monatDiff = monat - datum.monat;
    int jahrDiff = jahr - datum.jahr;

    //Differenz der Monate abrunden
    if (tagDiff < 0)
    {
        monatDiff--;
    }

    // Berechung der Monatsdifferenz zwischen beiden Daten
    return monatDiff + 12 * jahrDiff;
}



Datum Datum::operator+(const int anzahl_Tage) const
{
    int tagNeu = tag + anzahl_Tage;
    int monatNeu = monat;
    int jahrNeu = jahr;

    //Mehrere Monate weiterspringen
    while (tagNeu > tageMonat[monatNeu-1])
    {
        //Monat erh�hen und die jeweiligen Tage abziehen
        tagNeu -= tageMonat[monatNeu-1];
        monatNeu++;

        // Monat darf nicht gr��er als 12 werden
        if (monatNeu > 12)
        {
            monatNeu -= 12;
            jahrNeu++;
        }
    }
    return Datum(tagNeu, monatNeu, jahrNeu);
}

//Zuweisungsoperator
Datum& Datum::operator=(Datum& Datum)
{
    jahr = Datum.jahr;
    monat = Datum.monat;
    tag = Datum.tag;

    return *this;
}

//Streamoperator f�r ostream
std::ostream& operator<<(std::ostream& out, const Datum& datum)
{
    datum.ausgabe(out);
    return out;
}

//Streamoperator f�r istream
std::istream& operator >> (std::istream& in, Datum& datum)
{
    datum.eingabe(in);
    return in;
}

