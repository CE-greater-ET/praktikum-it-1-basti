/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Student.h"

using namespace std;


/**
 * Function to check whether a student exists
 *
 * @param studentenListe A vector of Students
 * @param matNr The matNr of the Student, which should be checked
 */
bool studentExists(vector<Student>* studentenListe, unsigned int matNr) {

	for (const Student& i : *studentenListe) {
		if (i.getMatNr() == matNr) return true;
	}

	return false;
}


int main()
{
    vector<Student> studentenListe;
    Student student;

    char abfrage;
//    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cout << "Wollen Sie Daten aus einer Datei einlesen? (j)/(n) ";

//    abfrage = 'n';

    std::cin >> abfrage;
    std::cin.ignore(10, '\n');
    if (abfrage == 'j') {
    	cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'studenten.txt)'";

    	string dateiname;
        getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen

        if (dateiname.empty()) dateiname = "studenten.txt";

        ifstream eingabe(dateiname);

        if (!eingabe)
        {
        	cout << " Fehler beim Oeffnen der Datei !";
        	exit(1) ;
        }


		int matNr;
		string name;
		string geburtsdatum;
		string adresse;

		eingabe >> matNr;

		while (!eingabe.eof())
        {
        	eingabe.ignore(1, '\n');
        	getline(eingabe , name);
        	getline(eingabe , geburtsdatum);
        	getline(eingabe , adresse);

        	student = Student(matNr, name, geburtsdatum, adresse);
			studentenListe.push_back(student);
			student.ausgabe();

			eingabe >> matNr;
        }


    };
/*
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }
*/
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
                  << "(7): Datenelement hinten entfernen" << std::endl
                  << "(8): Daten aus einer Datei einlesen" << std::endl
                  << "(9): Daten in eine Datei abspeichern" << std::endl
                  << "(S): Datenelemente in aufsteigender Reihenfolge sortieren" << std::endl
                  << "(0): Beenden" << std::endl;

        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

//        abfrage = '5';

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (vector<Student>::iterator it = studentenListe.begin() ; it != studentenListe.end(); ++it)
                        it->ausgabe();
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            // Datenbank rueckwarts ausgeben
            case '4':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in rücklaufender Reihenfolge:" << std::endl;
                    for (vector<Student>::reverse_iterator it = studentenListe.rbegin() ; it != studentenListe.rend(); ++it)
						it->ausgabe();
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            // Datenelement loeschen
            case '5':
            	{
					if(studentenListe.empty())
					{
						std::cout << "Die Liste ist leer!\n\n" << std::endl;
						break;
					}

					cout << "Bitte geben sie die Matrikelnummer an: " << endl;
					unsigned int matNrLoeschen;

//					matNrLoeschen = 34567;
					cin >> matNrLoeschen;

					Student tempStudent(matNrLoeschen, "", "", "");
					vector<Student>::iterator it = find(studentenListe.begin(), studentenListe.end(), tempStudent);

					if (it == studentenListe.end()) {
						cout << "Der Student wurde nicht gefunden...\n\n" << endl;
						break;
					}
					cout << "Der folgende Student wurde geloescht:\n\n" << endl;
					it->ausgabe();
					studentenListe.erase(it);

            	}
                break;

            // Datenelement vorne hinzufügen
            case '6':
            	{
            		unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					studentenListe.insert(studentenListe.begin(), student);
            	}

                break;

			// Datenelement hinten entfernen
			case '7':
				{
					if(!studentenListe.empty())
					{
						student = *(studentenListe.end());
						std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
						student.ausgabe();
						// nicht optimal, eigentlich sollte .erase(student) verwendet werden - aber Aufgabe will pop...
						studentenListe.pop_back();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n";
					}
				}
				break;

            // Daten aus einer Datei einlesen
			case '8':
				{
					bool mergeData = false;
					if(!studentenListe.empty())
					{
						cout << "Es sind bereits Daten vorhanden. Sollen diese:" << endl
								<< "(1) Gelöscht werden" << endl
								<< "(2) In die Datei 'tempStudents.txt' gespeichert, und dann lokal gelöscht" << endl
								<< "(3) Mit den einzulesenden Dateien gemerged werden (hierbei haben die vorhandenen Dateien Priorität)" << endl << endl
								<< "(Bei Falscheingabe ist Option (2) Standard)" << endl;

						std::cin >> abfrage;
						std::cin.ignore(10, '\n');

						switch (abfrage)
						{

							case '1':
								studentenListe.clear();
								break;


							case '3':
								mergeData = true;
								break;
							// CASE '2'
							default:
								ofstream ausgabe;
								ausgabe.open("tempStudents.txt");


								for(const Student& i : studentenListe) {
									ausgabe << i.getMatNr() << endl;
									ausgabe << i.getName() << endl;
									ausgabe << i.getGeburtstag() << endl;
									ausgabe << i.getAdresse() << endl;
								}

								ausgabe.close();

								studentenListe.clear();
								break;
						}

					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'studenten.txt)'";

					string dateiname;
					getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen

					if (dateiname.empty()) dateiname = "studenten.txt";

					ifstream eingabe(dateiname);

					if (!eingabe)
					{
						cout << " Fehler beim oeffnen der Datei !";
						exit(1) ;
					}


					int matNr;
					string name;
					string geburtsdatum;
					string adresse;

					eingabe >> matNr;

					while (!eingabe.eof())
					{
						eingabe.ignore(1, '\n');
						getline(eingabe , name);
						getline(eingabe , geburtsdatum);
						getline(eingabe , adresse);

						student = Student(matNr, name, geburtsdatum, adresse);

						if (mergeData && studentExists(&studentenListe, matNr)) {
							cout << "Folgender Student wurde nicht eingefügt, da die Matrikelnummer bereits existiert: " << endl;

						} else {
							studentenListe.push_back(student);
							cout << "Folgender Student wurde eingefügt: " << endl;
						}

						student.ausgabe();

						eingabe >> matNr;
					}

				}
				break;

            // Daten in eine Datei speichern
			case '9':
				{
					if(studentenListe.empty())
					{
						cout << "Es sind keine Daten vorhanden, die abgespeichert werden könnten." << endl;

						break;
					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'savedStudenten.txt)'";

					string dateiname;
					getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen

					if (dateiname.empty()) dateiname = "savedStudenten.txt";

					ofstream ausgabe;
					ausgabe.open(dateiname);

					if (!ausgabe)
					{
						cout << " Fehler beim oeffnen der Datei !";
						exit(1) ;
					}

					for(const Student& i : studentenListe) {
						ausgabe << i.getMatNr() << endl;
						ausgabe << i.getName() << endl;
						ausgabe << i.getGeburtstag() << endl;
						ausgabe << i.getAdresse() << endl;
					}

					ausgabe.close();

				}
				break;


			case 'S':

				sort(studentenListe.begin(), studentenListe.end());

				cout << "Daten nach dem sortieren: " << endl << endl;

				for(const Student& i : studentenListe) {
					cout << i << endl;
				}

				break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
