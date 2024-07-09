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

    /**
     * @brief Malt die Map auf die Szene - inkl. Straßen, Städten, Path
     */
    void draw(QGraphicsScene& scene) const;
    /**
     * @brief Malt die gegebenen Straßen in Rot
     */
    void setHighlightedStreets(QList<Street*>);

    // OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
    City* getClosestCityToXY(int x, int y) const;

    inline QList<City*> getCityList() const { return this->cities; };
    QList<City*> getCitiesWithStreets() const;

    /**
     * @brief Sucht die Stadt in der Map mit gegebenem Namen
     */
    City* findCity(const QString cityName) const override;

    /**
     * @brief Gibt alle Straßen wieder, die die gegebene Stadt verbinden
     */
    QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Helpermethode für Street::getOppositeCity
     */
    City* getOppositeCity(const Street* street, const City* city) const override;

    /**
     * @brief Gibt die Dauer wieder, die es dauert um diese Straße zu befahren (Länge in Pixel / Tempolimit in km/h)
     */
    double getLength(const Street* street) const override;

    ~Map();

private:
    QList<City*> cities;
    QList<Street*> streets;
    QList<Street*> highlightedStreets;
};

#endif // MAP_H
