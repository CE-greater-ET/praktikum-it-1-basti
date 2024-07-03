///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapionrw.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new City("Aachen", -100, 100);
    City* bonn = new City("Bonn", 0,200);
    City* koeln = new City("Köln", 0,0);
    City* duesseldorf = new City("Düsseldorf", 50,-100);

    Street* aachenKoeln = new Street(aachen, koeln);
    Street* bonnKoeln = new Street(bonn, koeln);
    Street* ddorfKoeln = new Street(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
