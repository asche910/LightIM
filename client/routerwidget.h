#ifndef ROUTERWIDGET_H
#define ROUTERWIDGET_H

#include "login.h"
#include "mainwindow.h"
#include <QtWidgets>

class Login;
class QStackedLayout;
class QVBoxLayout;


class RouterWidget:  public QWidget
{   
    Q_OBJECT
private:
    Login *login;
    MainWindow *mainwindow;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;

private slots:

public:
    explicit RouterWidget(QWidget *parent = nullptr);
};

#endif // ROUTERWIDGET_H
