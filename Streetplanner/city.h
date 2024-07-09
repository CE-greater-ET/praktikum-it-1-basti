#ifndef CITY_H
#define CITY_H

#include <QMainWindow>
#include <QObject>
#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y);


    /**
     * @brief Malt die Stadt mit ihren Eigenschaften + Name
     */
    virtual void draw(QGraphicsScene& scene) const;

    /**
     * @brief Gibt die X-Koordinate wieder
     */
    int getX() const { return this->x; };

    /**
     * @brief Gibt die Y-Koordinate wieder
     */
    int getY() const { return this->y; };

    /**
     * @brief Gibt den Namen der Stadt wieder
     */
    QString getName() const { return this->name; };

    /**
     * @brief Vergleichsoperator mit einer Stadt - Vergleich erfolgt durch Namen
     */
    bool operator==(const City& otherCity) const;

    /**
     * @brief Vergleichsoperator mit einem Stadtnamen
     */
    bool operator==(const QString& cityName) const;

protected:
    int x;
    int y;
    QString name;
};

#endif // CITY_H
