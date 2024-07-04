#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

class Street
{
public:
    Street(City* , City*);

    virtual void draw(QGraphicsScene& scene) const;
    virtual void drawRed(QGraphicsScene& scene) const;

    int getLength() const;

    bool connectsCities(const QList<City*>&) const;
    bool connectsCity(const City* city) const;
    City* getOppositeCity(const City* city) const;

    ~Street();


protected:
    City* city1;
    City* city2;
    int tempolimit;
};

#endif // STREET_H
