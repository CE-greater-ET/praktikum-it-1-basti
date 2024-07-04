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

    void setCityList(const QList<City*>);
    void setCity12(QString city1, QString city2);
    QList<Street*> findPath(Map&) const;
    Street* createStreet(Map*) const;

    ~PathDialog();

private slots:
    void on_startCity_Selection_currentTextChanged(const QString &arg1);

    void on_destinationCity_Selection_currentTextChanged(const QString &arg1);

private:
    Ui::PathDialog *ui;
};

#endif // PATHDIALOG_H
