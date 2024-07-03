#include "street.h"
#include <QtMath>

Street::Street(City* stadt1, City* stadt2):
    city1(stadt1),
    city2(stadt2){
}


void Street::draw(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (3) ;
    pen.setColor (Qt::blue );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
    );
}

void Street::drawRed(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (7) ;
    pen.setColor (Qt::red );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
        );
}

bool Street::connectsCities(const QList<City*>& cityList) const {
    if (city1 == city2) return false; // Eine Strasse sollte nicht hinzugefügt werden, wenn sie nicht zwei verschiedene Städte verbindet
    City* exists = nullptr;
    for (auto city : cityList) {
        if (city == city1 && exists == city2) {
            return true;
        } else if (city == city1) {
            exists = city1;
        } else if (city == city2 && exists == city1) {
            return true;
        } else if (city == city2) {
            exists = city2;
        }
    }
    return false;
}

bool Street::connectsCity(const City* city) const {
    return city == city1 || city == city2;
}

City* Street::getOppositeCity(const City* city) const {
    if (city == city1) return city2;
    else if (city == city2) return city1;
    else return nullptr;
}

int Street::getLength() const {
    int xDiff = city1->getX() - city2->getX();
    int yDiff = city1->getY() - city2->getY();
    return qSqrt(xDiff*xDiff + yDiff*yDiff);
}


Street::~Street() {

}
