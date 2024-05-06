//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

using namespace std;

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setPrevious(back);
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setNext(front);
        front->setPrevious(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->erasePrevious();
        delete cursor;
    }
}

void Liste::popBack()
{
    ListenElement* cursor = back;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete back;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        back = back->getPrevious();
        back->eraseNext();
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrevious();
    }
}

Student Liste::deleteMatNr(unsigned int matNr) {


	Student foundStudent;
	bool didFind = false;

    ListenElement* cursor = front;


	while (cursor != nullptr) {
		if (cursor->getData().getMatNr() == matNr) {
			foundStudent = cursor->getData();
			didFind = true;

			if (cursor == front) {
				this->popFront();
			} else if (cursor == back) {
				this->popBack();
			} else {
				cursor->getNext()->setPrevious(cursor->getPrevious());
				cursor->getPrevious()->setNext(cursor->getNext());
			}
		}
		cursor = cursor->getNext();

	}

	if (didFind) return foundStudent;
	else throw 99;
}
