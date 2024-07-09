#include "bigtown.h"
#include <QGraphicsTextItem>
#include <QPolygon>

BigTown::BigTown(QString name, int x, int y):
    City(name, x, y) {
}

void BigTown::draw(QGraphicsScene& scene) const {

    qDebug() << QString("Big Town mit dem Namen %1 wird an X: %2 Y: %3 gemalt.")
                    .arg(this->name)
                    .arg(this->x).arg(this->y);
    QPen pen ;
    pen.setWidth (3) ;
    pen.setColor(QColor(63, 0, 140));

    QBrush brush;
    brush.setColor(QColor(113, 5, 245));
    brush.setStyle(Qt::Dense2Pattern);

    QPolygonF cityShape;
    // Burg-Shape
    /*cityShape << QPointF(-10, 10)
              << QPointF(-10, -10)
              << QPointF(-7, -10)
              << QPointF(-7, -7)
              << QPointF(-4, -7)
              << QPointF(-4, -10)
              << QPointF(-1, -10)
              << QPointF(-1, -7)
              << QPointF(2, -7)
              << QPointF(2, -10)
              << QPointF(5, -10)
              << QPointF(5, -7)
              << QPointF(8, -7)
              << QPointF(8, -10)
              << QPointF(11, -10)
              << QPointF(11, 10)
              << QPointF(-10, 10);*/

    // Drachen-Shape
    cityShape << QPointF(-10, 0)
              << QPointF(0, 10)
              << QPointF(10, 0)
              << QPointF(0, -10)
              << QPointF(-10, 0);

    cityShape.translate(this->x, this->y);

    scene.addPolygon(cityShape, pen, brush);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x -10, this->y+5) ; // Position des Textes
    text->setPlainText(this->name); // Text
    // Kein Smartpointer o.ä. benötigt, da .addItem() Ownership übernimmt
    scene.addItem ( text ) ;
}
