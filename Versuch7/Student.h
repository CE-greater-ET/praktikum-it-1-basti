//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std;

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const { ausgabe(cout); } ;
    void ausgabe(ostream& outStream) const;

    bool operator==(const Student& otherStudent) const;
    bool operator>(const Student& otherStudent) const;
    bool operator<(const Student& otherStudent) const;
    bool operator>=(const Student& otherStudent) const;
    bool operator<=(const Student& otherStudent) const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};


ostream& operator<<(ostream& outStream, const Student& student);


#endif
