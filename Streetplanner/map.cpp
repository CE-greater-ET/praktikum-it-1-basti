#include "map.h"
#include <QtAlgorithms>

Map::Map()
    : cities(QList<City*>()), streets(QList<Street*>()) {

}

void Map::addCity(City* stadt) {
    cities.append(stadt);
}

bool Map::addStreet(Street* strasse) {
    if (strasse->connectsCities(cities)) {
        streets.append(strasse);
        return true;
    } else {
        qDebug() << "Die Straße verbindet keine Städte, die auf der Map sind.";
        return false;
    }
}


void Map::draw(QGraphicsScene& scene) const {

    scene.clear();

    qDebug() << cities.length();

    for (auto city : this->cities) {
        qDebug() << city->getX() << " und " << city->getY();
        city->draw(scene);
    }
    for (auto street : this->streets) {
        street->draw(scene);
    }
}

Map::~Map() {
    qDeleteAll(cities);
    qDeleteAll(streets);
}
