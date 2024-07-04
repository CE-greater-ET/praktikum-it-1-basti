#include "stateroad.h"

Stateroad::Stateroad(City* city1, City* city2):
    Street(city1, city2),
    tempolimit(50) {

}


void Stateroad::draw(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (5) ;
    pen.setColor (Qt::GlobalColor::blue );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
    );

}

void Stateroad::drawRed(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (5) ;
    pen.setColor (Qt::GlobalColor::red );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
        );

}
