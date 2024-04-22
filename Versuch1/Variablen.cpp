//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code
    

    cout << "Bitte gib eine Zahl ein plssss:" << endl;
    cin >> iErste;
    cout << "Bitte gib NOCH EINE Zahl ein plssss:" << endl;
    cin >> iZweite;

    int iSumme = iErste + iZweite;

    int iQuotient = iErste / iZweite;

    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;


    double dSummeCast = (double) iErste + (double) iZweite;
    double dQuotientCast = (double) iErste / (double) iZweite;

    cout << "Das ist die (INT) Summe:" << iSumme << endl;
    cout << "Das ist der (INT) Quotient: " << iQuotient << endl;

    cout << "Das ist die (DOUBLE) Summe:" << dSumme << endl;
    cout << "Das ist der (DOUBLE) Quotient: " << dQuotient << endl;

    cout << "Das ist die (DOUBLE CAST) Summe:" << dSummeCast << endl;
    cout << "Das ist der (DOUBLE CAST) Quotient: " << dQuotientCast << endl;

    string sVorname;
    string sNachname;

    cout << "Gib nun bitte deinen Vornamen ein: ";
    cin >> sVorname;
    cout << "Gib nun bitte deinen Vornamen ein: ";
    cin >> sNachname;


    string sVornameName = sVorname + " " + sNachname;
	string sNameVorname = sNachname + ", " + sVorname;

	cout << "Vorname Nachname:  " << sVornameName << endl;
	cout << "Nachname, Vorname:  " << sNameVorname << endl;

	int iName1 = (int) sVorname[0];
	int iName2 = (int) sVorname[1];


	cout << iName1 << " : " << iName2 << endl;


	int iPos1 = iName1 - 65+1;
	if (iPos1 > 26 || iPos1 <= 0) {
		iPos1 -= 6 + 26;
		if (iPos1 > 26 || iPos1 <= 0) {
			cout << "Dein Anfangsbuchstabe ist nicht im Alphabet." << endl;
		}
	}
	cout << "Position von Anfangsbuchstabe im alphabet:" << iPos1 << endl;
	// TEST

	int iPos2 = iName2 - 65+1;
	if (iPos2 > 26 || iPos2 <= 0) {
		iPos2 -= 6 + 26;
		if (iPos2 > 26 || iPos2 <= 0) {
			cout << "Dein Zweitbuchstabe ist nicht im Alphabet." << endl;
		}
	}
	cout << "Position von Zweitbuchstabe im alphabet:" << iPos2 << endl;


	{
		int iFeld[] = {1,2};

		cout << iFeld[0] << " : " << iFeld[1] << endl;

		int iSpielfeld[2][3] = {{1,2,3},{4,5,6}};

		for (int i1 = 0; i1 < 2; i1++) {
			for (int i2 = 0; i2 < 3; i2++) {
					cout << iSpielfeld[i1][i2] << " ";
				}
			cout << "\n";
		}
		cout << endl;

		const int iZweite = 1;
		cout << "iZweite: " << iZweite << endl;

	}
	cout << "iZweite: " << iZweite << endl;

    return 0;

}
