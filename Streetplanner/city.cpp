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

    QString xStr;
    xStr.setNum(this->x);

    QString yStr;
    yStr.setNum(this->y);

    qDebug() << QString("Stadt mit dem Namen %1 wird an X: %2 Y: %3 gemalt.").arg(this->name, xStr, yStr);
    QPen pen ;
    pen.setWidth (3) ;
    pen.setColor (Qt::red );

    scene.addRect(this->x, this->y, 3, 3, pen);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x, this->y+3) ; // Position des Textes
    text->setPlainText(this->name); // Text
    // Kein Smartpointer o.ä. benötigt, da .addItem() Ownership übernimmt
    scene.addItem ( text ) ;
}
