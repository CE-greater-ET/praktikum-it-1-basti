#include "motorway.h"

Motorway::Motorway(City* city1, City* city2):
    Street(city1, city2),
    tempolimit(130) {
}


void Motorway::draw(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (7) ;
    pen.setColor (Qt::GlobalColor::white );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
        );

    QPen dashedPen(QBrush(Qt::black), 2, Qt::DashLine);

    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        dashedPen
        );

}

void Motorway::drawRed(QGraphicsScene& scene) const {
    QPen pen ;

    pen.setWidth (7) ;
    pen.setColor (Qt::GlobalColor::red );


    scene.addLine(
        this->city1->getX(),
        this->city1->getY(),
        this->city2->getX(),
        this->city2->getY(),
        pen
        );

}
