#include "mainwindow.h"
#include "routerwidget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    Login login;
//    login.show();

    RouterWidget rw;
    rw.show();


    return a.exec();
}
