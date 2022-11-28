#include "mainwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    HomePage h;
    h.setWindowFlags(Qt::Window);

    w.show();
    return a.exec();



}

