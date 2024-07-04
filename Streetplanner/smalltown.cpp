#include "smalltown.h"
#include <QGraphicsItem>


SmallTown::SmallTown(QString name, int x, int y):
    City(name, x, y) {
}

void SmallTown::draw(QGraphicsScene& scene) const {

    qDebug() << QString("Small City mit dem Namen %1 wird an X: %2 Y: %3 gemalt.")
                    .arg(this->name)
                    .arg(this->x).arg(this->y);
    QPen pen ;
    pen.setWidth (3) ;
    pen.setColor (Qt::cyan);

    QBrush brush;
    brush.setColor(Qt::darkCyan);
    brush.setStyle(Qt::Dense1Pattern);

    scene.addRect(this->x -5, this->y -5, 10, 10, pen, brush);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x -5, this->y+7) ; // Position des Textes
    text->setPlainText(this->name); // Text
    // Kein Smartpointer o.ä. benötigt, da .addItem() Ownership übernimmt
    scene.addItem ( text ) ;
}
