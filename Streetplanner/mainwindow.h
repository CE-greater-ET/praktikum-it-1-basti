#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "map.h"
#include "citydialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_test_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_testCityButton_clicked();

    void on_testMapButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_addCity_button_clicked();

private:
    // OPTIONALES FEATURE - MUSS NICHT EXISTIEREN (AUCH KEIN WAHLPFLICHT)
    void mousePressEvent(QMouseEvent *event);


    Ui::MainWindow *ui;
    QGraphicsScene *graphScene;
    Map *map;
};
#endif // MAINWINDOW_H
