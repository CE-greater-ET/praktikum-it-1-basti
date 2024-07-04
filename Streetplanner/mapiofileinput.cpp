///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapiofileinput.h"

#include <sstream>
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

#define CITY_EXTENSION
#define STREET_EXTENSION


#ifdef CITY_EXTENSION
    #include "bigtown.h"
    #include "smalltown.h"
#endif
#ifdef STREET_EXTENSION
    #include "motorway.h"
    #include "stateroad.h"
#endif



MapIoFileinput::MapIoFileinput(QString pathToCityFile, QString pathToStreetFile):
    pathToCityFile(pathToCityFile),
    pathToStreetFile(pathToStreetFile)
{

}

MapIoFileinput::~MapIoFileinput()
{

}

void MapIoFileinput::fillMap(AbstractMap &map)
{
    QString line;
    QString name;
    QString xPositionString;
    QString yPositionString;
    QString firstCityName;
    QString secondCityName;
#ifdef CITY_EXTENSION
    QString cityTyp;
#endif

#ifdef STREET_EXTENSION
    QString streetTyp;
#endif

    int xPosition, yPosition;
    QFile cityFile(pathToCityFile);
    QFile streetFile(pathToStreetFile);

    if (!cityFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open city file: " << pathToCityFile;
        return;
    }

    if (!streetFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open street file: " << pathToStreetFile;
        return;
    }

    // Using a String Stream to split the string into the single words.
    QTextStream input(&cityFile);

    // Read in City File
    while(!input.atEnd())
    {
        input >> name;
        input >> xPositionString;
        input >> yPositionString;

#ifdef CITY_EXTENSION
        input >> cityTyp;
#endif

        // Convert the strings into Integers
        xPosition = xPositionString.toInt();
        yPosition = yPositionString.toInt();

        City *city;

#ifdef CITY_EXTENSION
        if (cityTyp.compare("BigTown") == 0)
        {
            city = new BigTown(name, xPosition, yPosition);
        }
        else
        {
            city = new SmallTown(name, xPosition, yPosition);
        }
#else
        city = new City(name, xPosition, yPosition);
#endif
        map.addCity(city);
        input.readLine();
    }

    QTextStream inputStreet(&streetFile);

    // Read in Street File
    while (!inputStreet.atEnd())
    {
        inputStreet >> firstCityName;
        inputStreet >> secondCityName;
#ifdef STREET_EXTENSION
        inputStreet >> streetTyp;
#endif

        City* city1 = map.findCity(firstCityName);
        City* city2 = map.findCity(secondCityName);

        if (!city1) {
            qDebug() << "Failed to create Street. First city not found Data: " << line;
        }
        if (!city2) {
            qDebug() << "Failed to create Street. Second city not found Data: " << line;
        }

        Street *street;

#ifdef STREET_EXTENSION
        if (streetTyp.compare("Motorway") == 0)
        {
            street = new Motorway(city1, city2);
        }
        else
        {
            street = new Stateroad(city1, city2);
        }
#else
        street = new Street(city1, city2);
#endif

        bool success = map.addStreet(street);
        if (success == false)
        {
            qDebug() << "Failed to create Street. Data: " << line;
        }
        inputStreet.readLine();
    }

    streetFile.close();
    cityFile.close();

}
