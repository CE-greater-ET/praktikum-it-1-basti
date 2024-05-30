/*! 
 * Praktikum Informatik 1 MMXXIV
 *
 * @ file Buecherei.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 08: Vererbung und Polymorphie
//
// Datei:  Buecherei.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/* Durch setzen dieser Variable k�nnen Sie entscheiden, welche Includes alle eingebunden werden sollen
 * Bei setzen auf true sind alle abgeleiteten Klassen (Buch, DVD, Magazin) vorhanden
 * Bei setzen auf false ist nur die Basisklasse Medium vorhanden
 */
 
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Medium.h"
#include "Datum.h"

#if UNTERKLASSENVORHANDEN

    #include "Magazin.h"
    #include "Buch.h"
    #include "DVD.h"

#endif


// Vorwärtsdeklarationen aller vorhandenen Funktionen
void fuelleDatenbank(std::vector<Medium*>& medien);
void mediumHinzufuegen(std::vector<Medium*>& medien);
void mediumEntfernen(std::vector<Medium*>& medien);
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum);
void mediumZurueckgeben(std::vector<Medium*>& medien);
void alleMedienAusgeben(std::vector<Medium*>& medien);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    // Vektor mit allen Medien der Bücherei
    std::vector<Medium*> medien;

    // aktuelles Datum
    Datum aktuellesDatum;
    std::cout << "Aktuelles Datum: " << aktuellesDatum << std::endl;

    // Prüfen, ob Unterklassen schon programmiert wurden (siehe bedingtes Kompilieren)
    // entsprechend wird die Datenbank mit unterschiedlichen Medien gefüllt
    fuelleDatenbank(medien);

    char abfrage;
    do  // Anzeige des Menüs
    {
        std::cout << std::endl
                  << "Menue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Medium hinzufügen" << std::endl
                  << "(2): Medium löschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Ein Medium verleihen" << std::endl
                  << "(5): Ein Medium zurücknehmen" << std::endl
                  << "(7): Beenden" << std::endl;

        // Einlesen der Abfrage
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {

            /////////////////////////////////////////////
            // Ein Medium wird zur Datenbank hinzufügt //
            /////////////////////////////////////////////
            case '1':
            {
                mediumHinzufuegen(medien);
                break;
            }

            ////////////////////////////////////////////////
            // Ein Medium wird aus der Datenbank entfernt //
            ////////////////////////////////////////////////
            case '2':
            {
                mediumEntfernen(medien);
                break;
            }

            ///////////////////////////////////////////
            // Ausgabe aller Medien in der Datenbank //
            ///////////////////////////////////////////
            case '3':
            {
                alleMedienAusgeben(medien);
                break;
            }

            /////////////////////////////
            // Verleihen eines Mediums //
            /////////////////////////////
            case '4':
            {
                mediumAusleihen(medien, aktuellesDatum);
                break;
            }

            ////////////////////////////////////////
            // Medium an die Bücherei zurückgeben //
            ////////////////////////////////////////
            case '5':
            {
                mediumZurueckgeben(medien);
                break;
            }

            case '7':
            {
                std::cout << "Das Menü wird nun beendet." << std::endl;
                break;
            }

            default :
            {
                std::cout << "Falsche Eingabe, bitte nochmal versuchen.";
                break;
            }
        }
    }
    while (abfrage != '7');

    // Beim Beenden des Programms sämtliche Medien l�schen
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        delete (*it);
    }

    return 0;
}

/////////////////////////////////////////////////////////////
// Definition aller Vorwärtsdeklarierten Funktionen

/////////////////////////////////////////////////////////////
// Funktion fuellt die Datenbank der Buecherei automatisch //
/////////////////////////////////////////////////////////////
void fuelleDatenbank(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    {
        // Datenbank wird mit Medien gef�llt
        Medium* neuesMedium = new Buch("Das Parfum", "Patrick Suskind");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Tom Sawyer", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("Chip", Datum(1, 12, 2022), "Computer");
        medien.push_back(neuesMedium);

        neuesMedium = new DVD("Fluch der Karibik", 12, "Actionkomödie");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Huckleberry Finn", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("BRANDNEU!", Datum(), "Ghostwriter");
		medien.push_back(neuesMedium);

		// Folgendes würde nicht funktionieren, da Medium rein virutell ist!
//        neuesMedium = new Medium("BRANDNEU!");
//		medien.push_back(neuesMedium);

    }
#else
    {
        // Datenbank wird mit Medien gefüllt
        Medium* neuesMedium = new Medium("Das Parfum");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Harry Potter und der Stein der Weisen");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Tom Sawyer");
        medien.push_back(neuesMedium);
    }
#endif
}

/////////////////////////////////////////////////////////
// Funktion fuegt ein neues Medium zur Datenbank hinzu //
/////////////////////////////////////////////////////////
void mediumHinzufuegen(std::vector<Medium*>& medien)
{
    #if UNTERKLASSENVORHANDEN
    {
        std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
                  << "(1): Buch" << std::endl
                  << "(2): Magazin" << std::endl
                  << "(3): DVD" << std::endl;

        // Einlesen der aktuellen Abfrage
        // �ber std::cin.ignore(10,\n) wird die "Enter-Eingabe, die für std::cin benötigt wird ignoriert
        // Ansonsten würde der nächste getline Befehl nicht auf eine Eingabe warten...
        char abfrage;
        std::cin >> abfrage;
        std::cin.ignore(10,'\n');

        switch (abfrage)
        {
            // Case 1: Buch
            case '1':
            {
                // Einlesen des Buch-Titels
                std::string titel;
                std::cout << "Bitte geben Sie den Titel des Buchs ein: " << std::endl;
                std::getline(std::cin, titel);

                std::string autor;
                std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
                std::getline(std::cin, autor);

                // erzeugen eines neuen Buchs
                Medium* neuesMedium = new Buch(titel,autor);
                medien.push_back(neuesMedium);
            }
            break;

            //Case 2: Magazin
            case '2':
            {
                // Einlesen des Magazin-Titels
                std::string titel;
                std::cout << "Geben Sie den Titel des Magazins ein:" << std::endl;
                getline(std::cin, titel);

                // Einlesen der Magazin-Sparte
                std::string sparte;
                std::cout << "Geben Sie die Sparte an:" << std::endl;
                getline(std::cin, sparte);

                // Einlesen des Datums (siehe Überladener Eingabeoperator in der Klasse Datum)
                Datum datumAusgabe;
                std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an:" << std::endl;
                std::cin >> datumAusgabe;
                std::cin.ignore(10, '\n');

                // erzeugen eines neuen Magazins
                Medium* neuesMedium = new Magazin(titel, datumAusgabe, sparte);
                medien.push_back(neuesMedium);
            }
            break;

            // Case 3: DVD
            case '3':
            {
                // Einlesen des DVD-Titels
                std::string titel;
                std::cout << "Bitte geben Sie den Titel der DVD ein:" << std::endl;
                getline(std::cin, titel);

                // Einlesen des DVD-Generes
                std::string genre;
                std::cout << "Geben Sie das Genre an:" << std::endl;
                getline(std::cin, genre);

                // Einlesen der DVD-Altersfreigabe
                int altersfreigabe;
                std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
                std::cin >> altersfreigabe;
                std::cin.ignore(10, '\n');

                Medium* neuesMedium = new DVD(titel, altersfreigabe, genre);
                medien.push_back(neuesMedium);
            }
            break;

            // Ung�ltige Eingabe
            default:
                std::cout << "Ungütige Eingabe!" << std::endl;
                break;
        }
    }
    #else //UNTERKLASSEVORHANDEN
    {
        // Einlesen des Titels
        std::string titel;
        std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
        getline(std::cin, titel);

        // Erzeugen eines neuen Mediums
        Medium* neuesMedium = new Medium(titel);
        medien.push_back(neuesMedium);
    }
    #endif
}

////////////////////////////////////////////////////
// Funktion entfernt ein Medium aus der Datenbank //
////////////////////////////////////////////////////
void mediumEntfernen(std::vector<Medium*>& medien)
{
    // ID des Mediums, welches gelöscht werden soll

    unsigned int id;

    std::cout << "Geben Sie die ID des Mediums ein, welches gel�scht werden soll: " ;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    bool success = false;

    // Suchen des richtigen Mediums zum Löschen
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            delete (*it);  // Objekt löschen
            medien.erase(it); // Zeiger auf das Objekt löschen
            success = true; // Löschen war erfolgreich
            break; // Schleife abbrechen
        }
    }
    if(!success)
    {
        std::cout << "Keine gültige ID!" << std::endl;
    }
}

/////////////////////////////////////////////////////
// Funktion leiht ein Medium aus der Datenbank aus //
/////////////////////////////////////////////////////
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum)
{
    // Einlesen der ID (�ber std::cin.ignore(10, '\n'), wird die
    // Enter-Eingabe am Ende std::cin Eingabe ignoriert
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    // Einlesen des Namens der Person, die das Medium ausleihen möchte
    std::string name;
    std::cout << "Geben Sie den Namen der Person ein: ";
    getline(std::cin, name);

    // Einlesen des Geburtsdatums
    Datum geburtsdatum;
    std::cout << "Geben Sie das Geburtsdatum der Person ein: (Format TT.MM.JJJJ) ";
    std::cin >> geburtsdatum;
    std::cin.ignore(10, '\n');

    Person person(name,geburtsdatum);

    bool id_vorhanden = false;
    // Suchen des richtigen Elementes
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->ausleihen(person,aktuellesDatum);
            id_vorhanden = true; //Medium wurde gefunden
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine g�ltige ID!" << std::endl;
    }
}

////////////////////////////////////////////////////
// Funktion gibt ein ausgeliehenes Medium zurueck //
////////////////////////////////////////////////////
void mediumZurueckgeben(std::vector<Medium*>& medien)
{
    // Einlesen der ID (Über std::cin.ignore(10, '\n'), wird die
    // Enter-Eingabe am Ende std::cin Eingabe ignoriert)
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein: ";
    std::cin >> id;
    std::cin.ignore(10,'\n');

    bool id_vorhanden = false;
    // Suchen des richtigen Elementes
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->zurueckgeben();
            id_vorhanden = true;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine g�ltige ID!" << std::endl;
    }
}

////////////////////////////////////////////////////
// Funktion gibt alle Medien in der Datenbank aus //
////////////////////////////////////////////////////
void alleMedienAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Vorhandene Medien in der Bücherei:" << std::endl;

    for (unsigned int index = 0; index < medien.size(); index++)
    {
        std::cout << "*************************************************************" << std::endl;
        medien[index]->ausgabe();
    }
}
