#include "city.h"
#include <QDebug>
#include <QGraphicsTextItem>
//#include <memory.h>

City::City(QString p_name, int p_x, int p_y):
    name(p_name),
    x(p_x),
    y(p_y) {

}

void City::draw(QGraphicsScene& scene) const {

    qDebug() << QString("Alte City mit dem Namen %1 wird an X: %2 Y: %3 gemalt.")
                    .arg(this->name)
                    .arg(this->x).arg(this->y);
    QPen pen ;
    pen.setWidth (3) ;
    pen.setColor (Qt::red);

    QBrush brush;
    brush.setColor(Qt::darkRed);
    brush.setStyle(Qt::Dense1Pattern);

    scene.addRect(this->x -5, this->y -5, 10, 10, pen, brush);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x -5, this->y+7) ; // Position des Textes
    text->setPlainText(this->name); // Text
    // Kein Smartpointer o.ä. benötigt, da .addItem() Ownership übernimmt
    scene.addItem ( text ) ;
}


bool City::operator==(const City& otherCity) const {
    return this->name == otherCity.getName();
}

bool City::operator==(const QString& cityName) const {
    return this->name == cityName;
}

