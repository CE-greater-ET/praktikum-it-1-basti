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

    virtual void draw(QGraphicsScene& scene) const;

    int getX() const { return this->x; };
    int getY() const { return this->y; };
    QString getName() const { return this->name; };
    bool operator==(const City& otherCity) const;
    bool operator==(const QString& cityName) const;

protected:
    int x;
    int y;
    QString name;
};

#endif // CITY_H
