#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QGraphicsScene>
#include "city.h"
#include "abstractmap.h"
#include "street.h"

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City*) override;
    bool addStreet(Street*) override;

    void draw(QGraphicsScene& scene) const;

    ~Map();

private:
    QList<City*> cities;
    QList<Street*> streets;
};

#endif // MAP_H
