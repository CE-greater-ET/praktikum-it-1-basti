#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graphScene(new QGraphicsScene)
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

    QRandomGenerator randGen;
    randGen.seed(23456);

    int randX = randGen.bounded(0,9);
    int randY = randGen.bounded(0,9);

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

