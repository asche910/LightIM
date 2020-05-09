#include "routerwidget.h"

RouterWidget::RouterWidget(QWidget *parent): QWidget(parent)
{
    // windows
    login = new Login;
    mainwindow = new MainWindow;

    stackLayout = new QStackedLayout;
    stackLayout->addWidget(login);
    stackLayout->addWidget(mainwindow);
    stackLayout->setCurrentIndex(0);



    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackLayout);
    setLayout(mainLayout);

    resize(600, 400);
}
