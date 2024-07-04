#include "map.h"
#include <QtAlgorithms>
#include <algorithm>
#include <QtMath>

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

QList<City*> Map::getCitiesWithStreets() const {
    QList<City*> citiesWithStreets;

    for (auto city : cities) {
        for (auto street : streets) {
            if (street->connectsCity(city)) {
                citiesWithStreets.append(city);
                break;
            }
        }
    }
    return citiesWithStreets;
}

// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
City* Map::getClosestCityToXY(int x, int y) const {
    City* closestCity = nullptr;
    int shortestDistance = std::numeric_limits<int>::max();
    for (auto city : cities) {
        int xDiff = x - city->getX();
        int yDiff = y - city->getY();
        int distance = qSqrt(xDiff*xDiff + yDiff*yDiff);
        qDebug() << "distance " << city->getName() << " is " << distance;
        if (distance < shortestDistance) {
            shortestDistance = distance;
            closestCity = city;
        }
    }

    if (shortestDistance < 20) return closestCity;
    else return nullptr;
}


void Map::draw(QGraphicsScene& scene) const {

    scene.clear();

    for (auto street : this->streets) {
        street->draw(scene);
    }
    // Optimaler wäre, nur den gehighlighteten Weg zu zeichnen, allerdings wird hier aus faulheit der alte Weg übermalt.
    for (auto street : this->highlightedStreets) {
        street->drawRed(scene);
    }
    // Städte als zweites zeichnen, damit die Namen angezeigt werden.
    for (auto city : this->cities) {
        qDebug() << city->getX() << " und " << city->getY();
        city->draw(scene);
    }
}

void Map::setHighlightedStreets(QList<Street*> newStreets) {
    this->highlightedStreets = newStreets;
}



City* Map::findCity(const QString cityName) const {
    QList<City*>::ConstIterator foundCity = std::find_if(
        this->cities.begin(),
        this->cities.end(),
        [cityName](const City *cp) {
            return *cp == cityName;
        }
    );
    if (foundCity == this->cities.end()) return nullptr;
    return *foundCity;
}



QVector<Street*> Map::getStreetList(const City* city) const {
    // Alias für List =)
    QVector<Street*> returnList;

    for (auto street : streets) {
        if (street->connectsCity(city)) returnList.append(street);
    }
    return returnList;
}


City* Map::getOppositeCity(const Street* street, const City* city) const {
    return street->getOppositeCity(city);
}


double Map::getLength(const Street* street) const {
    return street->getLength();
}


Map::~Map() {
    qDeleteAll(cities);
    qDeleteAll(streets);
    qDeleteAll(highlightedStreets);
}
