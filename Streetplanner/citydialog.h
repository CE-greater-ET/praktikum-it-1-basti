#ifndef CITYDIALOG_H
#define CITYDIALOG_H

#include <QDialog>
#include "city.h"

namespace Ui {
class CityDialog;
}

class CityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CityDialog(QWidget *parent = nullptr);
    ~CityDialog();

    City* createCity() const;

    // OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
    void setXYText(int x, int y);

private slots:

    // OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
    void on_cityName_input_textEdited(const QString &arg1);

private:
    Ui::CityDialog *ui;
};

#endif // CITYDIALOG_H
