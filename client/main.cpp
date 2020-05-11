#include "client.h"
#include "mainwindow.h"
#include "routerwidget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    RouterWidget rw;
//    rw.show();

    Client client;


    return a.exec();
}
