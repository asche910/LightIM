#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include "mainwindow.h"
#include "login.h"
#include "chatdialog.h"
#include "globals.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    resize(600, 400);
}

void MainWindow::start(){
    // left
    QListWidget *listWidget = new QListWidget;
    for(auto &i: userList){
        listWidget->addItem(i);
    }

    // right
    ChatDialog *chatDialog = new ChatDialog;


    QSplitter *centralSplitter = new QSplitter(this);

    centralSplitter->addWidget(listWidget);
    centralSplitter->addWidget(chatDialog);

    centralSplitter->setStretchFactor(0, 1);
    centralSplitter->setStretchFactor(1, 3);

    setCentralWidget(centralSplitter);


    connect(listWidget, &QListWidget::currentRowChanged, this, &MainWindow::listListen);

}

void MainWindow::handleLogin(QString username, QString password){
//    qDebug() << username;
//    qDebug() << password;
    loginUser = username;
    qDebug() << "login user:" << loginUser;
    start();
}

void MainWindow::listListen(int idx){
    curUserIndex = idx;
    qDebug() << idx << ": " << userList[idx];
}


MainWindow::~MainWindow()
{
}

