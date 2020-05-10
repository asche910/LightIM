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
    QVBoxLayout *mainLayout;

private slots:

public:
    explicit RouterWidget(QWidget *parent = nullptr);

    QStackedLayout *stackLayout;
signals:
    void display(int number);
};

#endif // ROUTERWIDGET_H
