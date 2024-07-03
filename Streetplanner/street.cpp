#include "street.h"


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

bool Street::connectsCities(QList<City*>& cityList) const {
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

Street::~Street() {

}
