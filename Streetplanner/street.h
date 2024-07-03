#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

class Street
{
public:
    Street(City* , City*);

    void draw(QGraphicsScene& scene) const;

    bool connectsCities(QList<City*>&) const;

    ~Street();


private:
    City* city1;
    City* city2;
};

#endif // STREET_H
