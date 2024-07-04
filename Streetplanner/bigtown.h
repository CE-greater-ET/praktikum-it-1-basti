#ifndef BIGTOWN_H
#define BIGTOWN_H

#include "city.h"

class BigTown : public City
{
public:
    BigTown(QString name, int x, int y);


    void draw(QGraphicsScene& scene) const override;
};

#endif // BIGTOWN_H
