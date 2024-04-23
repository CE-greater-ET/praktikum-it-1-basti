/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


using namespace std;


struct Person {
	string sNachname;
	string sVorname;
	int iGeburtsjahr;
	int iAlter;
};


void vPersonAusgeben(Person pPerson) {
	cout <<
				"Du bist also " << pPerson.sVorname << " " << pPerson.sNachname <<
				", wurdest " << pPerson.iGeburtsjahr <<
				" geboren und bist " << pPerson.iAlter <<
				" Jahre alt! Schön dich kennenzulernen!" <<
				endl;
}



int main()
{

	Person nBenutzer;


	cout << "Bitte gib nun dein Vornamen ein: ";
	cin >> nBenutzer.sVorname;
	cout << "Bitte gib nun dein Nachnamen ein: ";
	cin >> nBenutzer.sNachname;
	cout << "Bitte gib nun dein Geburtsjahr ein: ";
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Bitte gib nun dein Alter ein: ";
	cin >> nBenutzer.iAlter;


	cout << "Super!" << endl;

	vPersonAusgeben(nBenutzer);

	Person nKopieGesamt = nBenutzer;
	Person nKopieEinzeln;

	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	cout << "Nun kommt gesamtkopie:" << endl;
	vPersonAusgeben(nKopieGesamt);

	cout << "Nun kommt einzelkopie:" << endl;
	vPersonAusgeben(nKopieEinzeln);

	// Noch nie habe ich mich mehr useless gefühlt.

    return 1;
    
}
