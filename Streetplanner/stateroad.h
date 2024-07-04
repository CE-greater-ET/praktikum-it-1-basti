#ifndef STATEROAD_H
#define STATEROAD_H

#include "street.h"

class Stateroad : public Street
{
public:
    Stateroad(City* city1, City* city2);

    void draw(QGraphicsScene& scene) const override;
    void drawRed(QGraphicsScene& scene) const override;

protected:
    int tempolimit;
};

#endif // STATEROAD_H
