#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

class Street
{
public:
    Street(City* , City*);

    void draw(QGraphicsScene& scene) const;
    void drawRed(QGraphicsScene& scene) const;

    int getLength() const;

    bool connectsCities(const QList<City*>&) const;
    bool connectsCity(const City* city) const;
    City* getOppositeCity(const City* city) const;

    ~Street();


private:
    City* city1;
    City* city2;
};

#endif // STREET_H
