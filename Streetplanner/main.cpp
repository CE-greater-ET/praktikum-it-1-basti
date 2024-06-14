#include "mainwindow.h"
#include <QDebug>
#include <QString>

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString str1 = " rot ";
    QString str2 = " blau ";
    QString str3 = QString (" Das Buch ist vorne %1 , hinten %2. ").arg( str1, str2 );
    qDebug() << str3 ;


    return a.exec();
}
