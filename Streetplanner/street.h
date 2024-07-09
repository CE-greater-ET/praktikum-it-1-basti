#ifndef STREET_H
#define STREET_H

#include <QGraphicsScene>

#include "city.h"

class Street
{
public:
    Street(City* , City*);

    /**
     * @brief Malt die Straße mit ihren Eigenschaften
     */
    virtual void draw(QGraphicsScene& scene) const;

    /**
     * @brief Malt die Straße in rot, um einen Path darzustellen
     */
    virtual void drawRed(QGraphicsScene& scene) const;

    int getLength() const;

    /**
     * @brief Prüfe, ob beide Endpunkte der Straße in der QList vorhanden sind
     * @return
     */
    bool connectsCities(const QList<City*>&) const;

    /**
     * @brief Prüfe, ob die Straße die gegebene Stadt verbindet
     * @return
     */
    bool connectsCity(const City* city) const;

    /**
     * @brief Gibt die Stadt zurück, die sich auf der anderen Seite befindet
     * Falls die gegebene Stadt nicht von der Straße verbunden wird, dann wird nullptr returned
     * @param city Die Stadt, dessen Gegenüber returned werden soll
     * @return Pointer auf die gegenüberliegende Stadt, oder nullptr
     */
    City* getOppositeCity(const City* city) const;

    ~Street();


protected:
    City* city1;
    City* city2;
    int tempolimit;
};

#endif // STREET_H
