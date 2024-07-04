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
    void setHighlightedStreets(QList<Street*>);

    // OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
    City* getClosestCityToXY(int x, int y) const;

    inline QList<City*> getCityList() const { return this->cities; };
    QList<City*> getCitiesWithStreets() const;


    City* findCity(const QString cityName) const override;
    QVector<Street*> getStreetList(const City* city) const override;
    City* getOppositeCity(const Street* street, const City* city) const override;
    double getLength(const Street* street) const override;

    ~Map();

private:
    QList<City*> cities;
    QList<Street*> streets;
    QList<Street*> highlightedStreets;
};

#endif // MAP_H
