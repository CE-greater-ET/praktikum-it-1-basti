#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./city.h"
#include "./street.h"
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsItem>
#include <QRect>
#include <QSize>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graphScene(new QGraphicsScene)
    , map(new Map)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(this->graphScene);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    setMouseTracking(true); // E.g. set in your constructor of your widget.

    City *newCity = new City(
        QString("CITY 0 0"),
        0,
        0
        );
    map->addCity(newCity);
    map->draw(*(this->graphScene));
}

// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
void MainWindow::mousePressEvent(QMouseEvent *event){
    QGraphicsView *view = this->ui->graphicsView;

    int viewW = view->width();
    int viewH = view->height();

    QPoint ptOnView = view->mapFromParent(event->position().toPoint());
    QPoint ptOnScene = view->mapToScene(ptOnView).toPoint();

    qDebug() << ptOnView;

    int newX = ptOnScene.x();
    int newY = ptOnScene.y();


    CityDialog newDialog;

    // newX > 0: rechts von linkem view Rand
    // newY > 0: unter oberem view Rand
    // viewW > ptOnView.x(): Links von rechtem view Rand
    // viewH > ptOnView.y(): Über unterem view rand
    if (newX > 0 && newY > 0 && viewW > ptOnView.x() && viewH > ptOnView.y()) {
        newDialog.setXYText(newX, newY);

        int success = newDialog.exec();
        if (!success) return;

        City *newCity = newDialog.createCity();
        this->map->addCity(newCity);
        this->map->draw(*(this->graphScene));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graphScene;
}

void MainWindow::on_test_pushButton_clicked()
{

    QString currText = ui->test_lineEdit->text();
    bool ok = false;
    int num = currText.toInt(&ok, 10);

    QMessageBox infoBox;
    infoBox.setStandardButtons(
        QMessageBox::Ok
    );
    infoBox.setText("Knopf wurde gedrückt");

    if (ok) {
        infoBox.setInformativeText(QString().setNum(num+4));
        qDebug() << QString("ZAHL '%1' (+4 hihi) EINGEGEBEN (WOHOO)").arg(num+4);
    } else {
        infoBox.setInformativeText(currText);
        qDebug() << QString("TEXT '%1' IST EINGEGEBEN (WOHOO)").arg(currText);
    }

    int randX = QRandomGenerator::global()->bounded(0,9);
    int randY = QRandomGenerator::global()->bounded(0,9);

    qDebug() << randX;
    qDebug() << randY;

    int tenthHeight = this->ui->graphicsView->height() / 10;
    int tenthWidth = this->ui->graphicsView->width() / 10;

    infoBox.setInformativeText(QString().setNum(tenthHeight));

    QPen pen ;
    pen.setWidth (5) ;
    pen.setColor (Qt::yellow );



    this->graphScene->clear();
    this->graphScene->addRect(QRectF(tenthHeight * randY, tenthWidth * randX, tenthHeight, tenthWidth), pen);



    infoBox.exec();
}

// Sowohl Option+E, als auch CMD+Q triggered diese Funktion
void MainWindow::on_actionExit_triggered()
{
    // qDebug() << "EXITED";
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    this->graphScene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Über", "Dies ist ein Programm aus dem Modul PI1 an der RWTH Aachen! \n\n'Made' by OnPoint");
}


void MainWindow::on_testCityButton_clicked()
{
    int randX = QRandomGenerator::global()->bounded(0,200);
    int randY = QRandomGenerator::global()->bounded(0,200);
    QString xStr;
    xStr.setNum(randX);
    QString yStr;
    yStr.setNum(randY);

    City stadt1(QString("TestStadtX%1Y%2").arg(xStr, yStr), randX, randY);
    City stadt2(QString("TestStadtX%2Y%1").arg(xStr, yStr), randY, randX);

    stadt1.draw(*(this->graphScene));
    stadt2.draw(*(this->graphScene));
}


void MainWindow::on_testMapButton_clicked()
{
    City *c1 = new City("city c1", 20,50);
    City *c2 = new City("city c2", 100,50);
    City *c3 = new City("city c3", 20,100);
    City *c4 = new City("city c4 (wird nie angezeigt)", 60,60);
    map->addCity(c1);
    map->addCity(c2);
    map->addCity(c3);
    Street *s1 = new Street(c1, c2);
    Street *s2 = new Street(c2, c3);
    Street *s3 = new Street(c2, c4); // Diese strasse sollte nicht hinzugefügt werden - da c4 nicht in stadt
    Street *s4 = new Street(c2, c2); // Diese strasse sollte nicht hinzugefügt werden -  da sie nicht logisch ist (von c2 zu c2)
    map->addStreet(s1);
    map->addStreet(s2);
    map->addStreet(s3);
    map->addStreet(s4);
    map->draw(*(this->graphScene));
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->testCityButton->setHidden(!checked);
    ui->testMapButton->setHidden(!checked);
    ui->test_pushButton->setHidden(!checked);
}



void MainWindow::on_addCity_button_clicked()
{
    CityDialog newDialog;

    int accepted = newDialog.exec();

    if (!accepted) {
        qDebug() << "Fehler beim hinzufügen der Stadt (Dialog failed)";
        return;
    }

    City *newCity = newDialog.createCity();

    this->map->addCity(newCity);

    this->map->draw(*(this->graphScene));

}

