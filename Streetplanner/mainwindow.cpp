#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./city.h"
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graphScene(new QGraphicsScene)
    , randGen(QRandomGenerator(23456))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(this->graphScene);
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

    int randX = this->randGen.bounded(0,9);
    int randY = this->randGen.bounded(0,9);

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
    int randX = this->randGen.bounded(0,200);
    int randY = this->randGen.bounded(0,200);
    QString xStr;
    xStr.setNum(randX);
    QString yStr;
    yStr.setNum(randY);

    City stadt1(QString("TestStadtX%1Y%2").arg(xStr, yStr), randX, randY);
    City stadt2(QString("TestStadtX%2Y%1").arg(xStr, yStr), randY, randX);

    stadt1.draw(*(this->graphScene));
    stadt2.draw(*(this->graphScene));
}

