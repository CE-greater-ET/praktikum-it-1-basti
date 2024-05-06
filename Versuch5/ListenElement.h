//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* previous;

public:
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrevious);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrevious(ListenElement* pPrevious);


    void eraseNext();
    void erasePrevious();


    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrevious() const;
};

#endif
