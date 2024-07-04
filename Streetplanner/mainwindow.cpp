#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./city.h"
#include "./street.h"
#include "citydialog.h"
#include "pathdialog.h"
#include "mapionrw.h"
#include "mapiofileinput.h"
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsItem>
#include <QRect>
#include <QSize>
#include <QFileDialog>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graphScene(new QGraphicsScene)
    , map(new Map)
    , mapio(new MapIoNrw)
    , lastPressTime(0)
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
bool MainWindow::isPointOnView(QPoint ptOnView) {
    QGraphicsView *view = this->ui->graphicsView;

    int viewW = view->width();
    int viewH = view->height();


    // ptOnView.x() > 0: rechts von linkem view Rand
    // ptOnView.y() > 0: unter oberem view Rand
    // viewW > ptOnView.x(): Links von rechtem view Rand
    // viewH > ptOnView.y(): Über unterem view rand
    return (ptOnView.x() > 0 && ptOnView.y() > 0 && viewW > ptOnView.x() && viewH > ptOnView.y());

}


// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    QGraphicsView *view = this->ui->graphicsView;

    QPoint ptOnView = view->mapFromParent(event->position().toPoint());

    qDebug() << ptOnView;


    if (isPointOnView(ptOnView)) {
        CityDialog newDialog;

        QPoint ptOnScene = view->mapToScene(ptOnView).toPoint();
        int viewW = view->width();
        int viewH = view->height();
        int newX = ptOnScene.x();
        int newY = ptOnScene.y();

        newDialog.setXYText(newX, newY);

        int success = newDialog.exec();
        if (!success) return;

        City *newCity = newDialog.createCity();
        this->map->addCity(newCity);
        this->map->draw(*(this->graphScene));
    }
}

// OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
void MainWindow::mousePressEvent(QMouseEvent *event) {
    QGraphicsView *view = this->ui->graphicsView;

    QPoint ptOnView = view->mapFromParent(event->position().toPoint());
    QPoint ptOnScene = view->mapToScene(ptOnView).toPoint();


    if (!isPointOnView(ptOnView)) return;

    int timeDiff = event->timestamp() - lastPressTime;
    if (timeDiff > 3000) {
        lastPressTime = event->timestamp();
        lastPressLocation = ptOnScene;
        event->accept();
        return;
    }


    City* city1 = this->map->getClosestCityToXY(lastPressLocation.x(), lastPressLocation.y());
    if (city1 == nullptr) return;

    City* city2 = this->map->getClosestCityToXY(ptOnScene.x(), ptOnScene.y());
    if (city2 == nullptr) return;

    PathDialog newDialog;

    newDialog.setCityList(this->map->getCityList());
    newDialog.setCity12(city1->getName(), city2->getName());

    int success = newDialog.exec();
    if (!success) return;

    Street *newStreet = newDialog.createStreet(this->map);
    this->map->addStreet(newStreet);
    this->map->draw(*(this->graphScene));
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
        qDebug() << "Fehler beim hinzufügen der Stadt (Dialog failed / cancelled)";
        return;
    }

    City *newCity = newDialog.createCity();

    this->map->addCity(newCity);

    this->map->draw(*(this->graphScene));

}


void MainWindow::on_fillMapButton_clicked()
{
    mapio->fillMap(*(this->map));
    this->map->draw(*(this->graphScene));
}


void MainWindow::on_addStreet_button_clicked()
{
    PathDialog newDialog;
    newDialog.setCityList(map->getCityList());

    int accepted = newDialog.exec();

    if (!accepted) {
        qDebug() << "Fehler beim erstellen der strasse (Dialog failed / cancelled)";
        return;
    }

    Street *neueStrasse = newDialog.createStreet(this->map);

    if (neueStrasse == nullptr) {
        qDebug() << "Fehler beim erstellen der strasse (idk was, aber wahrscheinlich städte nicht gefunden (sollte nicht möglich sein))";
        return;
    }

    this->map->addStreet(neueStrasse);

    this->map->draw(*(this->graphScene));

}

void MainWindow::on_findPath_button_clicked()
{
    PathDialog newDialog;
    newDialog.setCityList(map->getCitiesWithStreets());

    int accepted = newDialog.exec();

    if (!accepted) {
        qDebug() << "Fehler beim finden des Weges (Dialog failed / cancelled)";
        return;
    }

    QList<Street*> strassenliste = newDialog.findPath(*(this->map));

    if (strassenliste.empty()) {
        qDebug() << "Fehler beim findes des Weges (weg wurde nicht gefunden)";
        return;
    }

    this->map->setHighlightedStreets(strassenliste);

    this->map->draw(*(this->graphScene));
}


void MainWindow::on_abstractMapTest_button_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map->getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}




void MainWindow::on_fillMapFile_button_clicked()
{
    QString cityFileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Cities"),
        QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
        tr("Text Files (*.txt)")
        );
    if (cityFileName.isEmpty()) return;

    QString streetFileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Streets"),
        "",
        tr("Text Files (*.txt)")
        );
    if (streetFileName.isEmpty()) return;

    MapIoFileinput *fileIn = new MapIoFileinput(cityFileName, streetFileName);
    this->mapio = fileIn;
    this->mapio->fillMap(*(this->map));
    this->map->draw(*(this->graphScene));
}

