#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include "mainwindow.h"
#include "login.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{


    QPushButton *btn = new QPushButton;
    btn->setText("hello");

    QPushButton *btnCancel = new QPushButton;
    btnCancel->setText("Cancel");


    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&Username:"), btn);
    formLayout->addRow(tr("&Password:"), btnCancel);


    QWidget *wid = new QWidget(this);
    wid->setLayout(formLayout);

//    QSplitter *centralSplitter = new QSplitter(this);
//    centralSplitter->addWidget(btn);
//    centralSplitter->addWidget(btnCancel);
//    centralSplitter->addWidget(wid);



   setCentralWidget(wid);


//    setCentralWidget(centralSplitter);

    resize(600, 400);



//    connect(btn, SIGNAL(clicked()), this, SLOT());

}

void MainWindow::jump(){

}


MainWindow::~MainWindow()
{
}

