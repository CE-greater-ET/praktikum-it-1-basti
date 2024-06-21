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

    void draw(QGraphicsScene& scene) const;

private:
    int x;
    int y;
    QString name;
};

#endif // CITY_H
