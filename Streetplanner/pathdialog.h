#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QDialog>
#include <QList>
#include "city.h"
#include "street.h"
#include "map.h"

namespace Ui {
class PathDialog;
}

class PathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PathDialog(QWidget *parent = nullptr);

    /**
     * @brief Setze die auswählbaren Städte
     * @param QList Die Liste aus City*, aus denen ausgewählt werden darf
     */
    void setCityList(const QList<City*>);

    /**
     * @brief Setzt die ausgewählten Straßen im Dialog, z.B. für Standardauswahl
     */
    void setCity12(QString city1, QString city2);

    /**
     * @brief Findet den Weg der beiden ausgewählten Städte durch Dijkstra
     * @return Die Liste der Straßen, die zum verbinden nötig sind - falls möglich
     */
    QList<Street*> findPath(Map&) const;

    /**
     * @brief Erstellt eine Straße zwischen den beiden ausgewählten Städten
     * @return Die Erstellte Straße
     */
    Street* createStreet(Map*) const;

    ~PathDialog();

private slots:
    void on_startCity_Selection_currentTextChanged(const QString &arg1);

    void on_destinationCity_Selection_currentTextChanged(const QString &arg1);

private:
    Ui::PathDialog *ui;
};

#endif // PATHDIALOG_H
