///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

string verschluesseln(char schluessel[2][26], string wort)
{


	for(int i = 0; i < wort.length(); i++) {
		wort[i] = toupper(wort[i]);
		for(int i2 = 0; i2 < 26; i2++) {
			if (schluessel[0][i2] == wort[i]) {
				cout << "changing " << schluessel[0][i2] << " to " << schluessel[1][i2] << endl;
				wort[i] = schluessel[1][i2];
				break;
			}
		}
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	for(int i = 0; i < wort.length(); i++) {
		wort[i] = toupper(wort[i]);
		for(int i2 = 0; i2 < 26; i2++) {
			if (schluessel[1][i2] == wort[i]) {
				cout << "changing " << schluessel[1][i2] << " to " << schluessel[0][i2] << endl;
				wort[i] = schluessel[0][i2];
				break;
			}
		}
	}

	return wort;
}

int main()
{
	// Hier folgt Ihr Code

	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char out[] = "QWERTZUIOPASDFGHJKLYXCVBNM";


	char lookup[2][26] = {
			{'A'},
			{'Q'},
	};

	for (int i = 0; i < 26; i++) {
		lookup[0][i] = in[i];
		lookup[1][i] = out[i];
	}

	cout << "Bitte gib nun einen zu verschlüsselden Text ein: " << endl;

	string inputStr;

	cin >> inputStr;

	string result = verschluesseln(lookup, inputStr);

	cout << "CODIERT: " << result << endl;

	string entkodiert = entschluesseln(lookup, result);

	cout << "WIEDER NORMAL: " << entkodiert << endl;




	return 0;
}
