#include "citydialog.h"
#include "ui_citydialog.h"
#include "bigtown.h"
#include <QDebug>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QRandomGenerator>

CityDialog::CityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CityDialog)
{
    ui->setupUi(this);
    QPushButton *okBtn = this->ui->dialogButtons->button(QDialogButtonBox::Ok);
    okBtn->setDisabled(true);
    ui->x_input->setPlaceholderText(QString().setNum(QRandomGenerator::global()->bounded(20,200)));
    ui->y_input->setPlaceholderText(QString().setNum(QRandomGenerator::global()->bounded(20,200)));
}

CityDialog::~CityDialog()
{
    delete ui;
}


City* CityDialog::createCity() const {
    auto x_in = ui->x_input;
    auto y_in = ui->y_input;
    bool ok;

    auto x = x_in->text().toInt(&ok);
    if (!ok) x = x_in->placeholderText().toInt();

    auto y = y_in->text().toInt(&ok);
    if (!ok) y = y_in->placeholderText().toInt();

    auto name = ui->cityName_input->text();

    qDebug() << "STADT DIALOG X: " << x << " Y: " << y << " NAME: " << name;

    return new BigTown(name, x, y);
}


// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
void CityDialog::setXYText(int x, int y) {
    this->ui->x_input->setText(QString().setNum(x));
    this->ui->y_input->setText(QString().setNum(y));
}

// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
void CityDialog::on_cityName_input_textEdited(const QString &arg1)
{
    QPushButton *okBtn = this->ui->dialogButtons->button(QDialogButtonBox::Ok);
    if (arg1.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setDisabled(false);
    }
}

