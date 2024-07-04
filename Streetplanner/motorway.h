#ifndef MOTORWAY_H
#define MOTORWAY_H

#include "street.h"

class Motorway : public Street
{
public:
    Motorway(City*, City*);

    void draw(QGraphicsScene&) const override;
    void drawRed(QGraphicsScene&) const override;

protected:
    int tempolimit;
};

#endif // MOTORWAY_H
