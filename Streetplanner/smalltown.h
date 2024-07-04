#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "city.h"

class SmallTown : public City
{
public:
    SmallTown(QString name, int x, int y);

    void draw(QGraphicsScene& scene) const override;
};

#endif // SMALLTOWN_H
