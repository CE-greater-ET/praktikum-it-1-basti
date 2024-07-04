///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

class MapIoFileinput : public MapIo
{
public:
    MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);
    ~MapIoFileinput();

    virtual void fillMap(AbstractMap &map);

protected:
    QString pathToCityFile;
    QString pathToStreetFile;
};

#endif // MAPIOFILEINPUT_H
