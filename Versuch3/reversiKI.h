/**
 * Praktikum Informatik 1 
 * 
 *
 * @file reversiKI.h
 *
 * Stellt eine KI fuer das Spiel Reversi zur Verfuegung
 */

#ifndef REVERSIKI_H_
#define REVERSIKI_H_

#include "config.h"

/**
 * Eine Funktion, die eine KI fuer das Spiel Reversi zur Verfuegung stellt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return True wenn der Zug ausgefuehrt wurde. False wenn kein Zug moeglich ist.
 */
bool computerZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler);

#endif /* REVERSIKI_H_ */
