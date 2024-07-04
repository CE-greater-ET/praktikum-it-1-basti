#include "pathdialog.h"
#include "ui_pathdialog.h"
#include "dijkstra.h"
#include <QDialogButtonBox>
#include <QPushButton>

PathDialog::PathDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PathDialog)
{
    ui->setupUi(this);
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    okBtn->setDisabled(true);
}

void PathDialog::setCityList(const QList<City*> cities) {
    if (cities.isEmpty()) {
        ui->startCity_Selection->setPlaceholderText("Keine Städte vorhanden");
        ui->destinationCity_Selection->setPlaceholderText("Keine Städte vorhanden");
        return;
    }
    for (auto city : cities) {
        QString name = city->getName();
        ui->startCity_Selection->addItem(name);
        ui->destinationCity_Selection->addItem(name);
    }
}

void PathDialog::setCity12(QString city1, QString city2) {
    ui->startCity_Selection->setCurrentText(city1);
    ui->destinationCity_Selection->setCurrentText(city2);
}

QList<Street*> PathDialog::findPath(Map& map) const {
    QString startName = ui->startCity_Selection->currentText();
    QString destinationName = ui->destinationCity_Selection->currentText();

    return Dijkstra::search(map, startName, destinationName);
}

Street* PathDialog::createStreet(Map* map) const {
    QString startName = ui->startCity_Selection->currentText();
    QString destinationName = ui->destinationCity_Selection->currentText();
    City* city1 = map->findCity(startName);
    City* city2 = map->findCity(destinationName);

    if (city1 == nullptr || city2 == nullptr) return nullptr;

    Street* strasse = new Street(city1, city2);
    return strasse;
}


PathDialog::~PathDialog()
{
    delete ui;
}

void PathDialog::on_startCity_Selection_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->destinationCity_Selection->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}


void PathDialog::on_destinationCity_Selection_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->startCity_Selection->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}

