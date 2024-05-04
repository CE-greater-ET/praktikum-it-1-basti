/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


using namespace std;


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
	if (posX < 0 || posX >= GROESSE_X) {
		return false;
	}
	if (posY < 0 || posY >= GROESSE_Y) {
		return false;
	}

    // Hier erfolgt jetzt Ihre Implementierung ...
    return true;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
        	int pruefX = posX + j;
        	int pruefY = posY + i;

            // Hier erfolgt jetzt Ihre Implementierung ...
        	if (!aufSpielfeld(pruefX, pruefY)) {
        		continue;
        	}
        	if (spielfeld[pruefY][pruefX] == gegner) {

        		// do-while, damit ein vergleich gespart wird (hoffentlich ist das schneller)
        		do {

        			if (spielfeld[pruefY][pruefX] == 0) {
        				break;
        			} else if (spielfeld[pruefY][pruefX] == aktuellerSpieler) {
        				return true;
        			}
        			pruefX += j;
        			pruefY += i;


        		} while (aufSpielfeld(pruefX, pruefY));


        	}
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...

        	int laufX = posX + j;
			int laufY = posY + i;

        	if (!aufSpielfeld(laufX, laufY)) continue;

        	if (spielfeld[laufY][laufX] != gegner) continue;

			do {

				if (spielfeld[laufY][laufX] == aktuellerSpieler) {
					//  alle gegner ficken
					// TODO: kommentar entfernen
					laufX -= j;
					laufY -= i;

					while (spielfeld[laufY][laufX] == gegner) {
						spielfeld[laufY][laufX] = aktuellerSpieler;

						laufX -= j;
						laufY -= i;
					}
					spielfeld[posY][posX] = aktuellerSpieler;
					break;

				} else if (spielfeld[laufY][laufX] == 0) {
					break;
				}
				laufX += j;
				laufY += i;

			} while (aufSpielfeld(laufX, laufY));
        }
    }

}


/* Kommentar an self:
 *
 * 2 Ansätze: Finde spieler, suche in alle richtungen nach gegnern (bis zu leerem feld)
 * Problem: Felder werden mehrmals gezählt, wenn in mehrere Richtungen Gegner - Spieler stehen
 *
 * Anderer Ansatz (ohne das problem, aber rechenaufwendiger):
 * Finde leere felder - wenn in mind. eine richtung gegner-spieler sind, dann zähle diesen und gehe zum nächsten Feld.
 *
 * Performance negierbar, allerdings gibt es bestimmt einen besseren Ansatz.
 *
 *
 *
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
    
	int gegner = 3 - aktuellerSpieler;

	int possibleMoves = 0;

	for (int posX = 0; posX < GROESSE_X; posX++) {
		for (int posY = 0; posY < GROESSE_Y; posY++) {
			if (spielfeld[posY][posX] == 0) {
				bool isPossible = false;
				for (int j = -1; j <= 1; j++) {
					for (int i = -1; i <= 1; i++) {
						int laufX = posX + j;
						int laufY = posY + i;
						if (!aufSpielfeld(laufX, laufY)) continue;
						if (spielfeld[laufY][laufX] != gegner) continue;

						do {
							if (spielfeld[laufY][laufX] == aktuellerSpieler) {
								possibleMoves += 1;
								isPossible = true;
								break;
							} else if (spielfeld[laufY][laufX] == 0) {
								break;
							}
							laufX += j;
							laufY += i;
						} while (aufSpielfeld(laufX, laufY));

						if (isPossible) break;
					}
					if (isPossible) break;
				}
			}
		}
	}
	return possibleMoves;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;


    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    bool noMoves = false;

    int runden = 1;
    while (1) {
    	bool moegl;
    	if (spielerTyp[aktuellerSpieler - 1] == MENSCH) {
    		cout << endl;
    		zeigeSpielfeld(spielfeld);
    		moegl = menschlicherZug(spielfeld, aktuellerSpieler);

    	} else if (spielerTyp[aktuellerSpieler - 1] == COMPUTER) {
    		moegl = computerZug(spielfeld, aktuellerSpieler);
    		zeigeSpielfeld(spielfeld);
			// cout << "Spieler " << aktuellerSpieler << " noch " << moeglicheZuege(spielfeld, aktuellerSpieler) << " Züge." << endl;

    	} else {
    		break;
    	}
		if (!moegl && noMoves) break;
		else if (!moegl) noMoves = true;
		else noMoves = false;

		aktuellerSpieler = 3 - aktuellerSpieler;

    	cout << "Runde: " << runden++ << endl;

    }
    int gewinnerInt = gewinner(spielfeld);
    if (gewinnerInt == 0) {
    	cout << "Unentschieden! Better Luck next time!" << endl;
    	return;
    }

    switch (gewinnerInt + 4*spielerTyp[gewinnerInt-1])
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
    	case 1 + 4*MENSCH:
    		cout << "Spieler 1 hat gewonnen! Herzlichen Glückwunsch!" << endl;
    		break;
    	case 2 + 4*MENSCH:

    		cout << "Spieler 2 hat gewonnen! Herzlichen Glückwunsch!" << endl;
    		break;
    	case 1 + 4*COMPUTER:

			cout << "Computer 1 hat gewonnen! KI übernimmt bald die Welt!" << endl;
			break;

    	case 2 + 4*COMPUTER:

			cout << "Computer 2 hat gewonnen! KI übernimmt bald die Welt!" << endl;
			break;
    	default:
    		cout << "Keine Ahnung wer gewonnen hat..." << endl;
    		break;

    }
}

int spielmain ()
{
	int spielerTyp [2] = { MENSCH , MENSCH };
	spielen ( spielerTyp ) ;
	return 0;
}

int computermain() {
	int spielerTyp [2] = { MENSCH , COMPUTER };
		spielen ( spielerTyp ) ;
		return 0;
}

int kimain ()
{
	int spielerTyp [2] = { COMPUTER , COMPUTER };
	spielen ( spielerTyp ) ;
	return 0;
}

int testmain()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);





    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}


int main(){
	int testlist[4][4] =
		{
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
		};
	cout << testlist[2][-1] << endl;

	kimain();
	return 0;
}
