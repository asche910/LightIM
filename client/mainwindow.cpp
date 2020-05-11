#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include "mainwindow.h"
#include "login.h"
#include "chatdialog.h"
#include "globals.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{

    QPushButton *btn = new QPushButton;
    btn->setText("hello");

    QPushButton *btnCancel = new QPushButton;
    btnCancel->setText("Cancel");



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

    resize(600, 400);
}

void MainWindow::handleLogin(QString username, QString password){
    qDebug() << username;
    qDebug() << password;

    loginUser = username;
}

void MainWindow::listListen(int idx){
    curUserIndex = idx;
    qDebug() << idx << ": " << userList[idx];
}

MainWindow::~MainWindow()
{
}

