#include "routerwidget.h"

RouterWidget::RouterWidget(QWidget *parent): QWidget(parent)
{

    setWindowTitle(tr("LightIM"));
    mainLayout = new QVBoxLayout;

    // windows
    login = new Login;
    mainwindow = new MainWindow;

    stackLayout = new QStackedLayout;
    stackLayout->addWidget(login);
    stackLayout->addWidget(mainwindow);
    stackLayout->setCurrentIndex(0);

    connect(login, &Login::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(mainwindow, &MainWindow::display, stackLayout, &QStackedLayout::setCurrentIndex);


    connect(login, &Login::sendData, mainwindow, &MainWindow::handleLogin);

    mainLayout->addLayout(stackLayout);
    setLayout(mainLayout);

    resize(600, 400);
}
