#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{

    setWindowTitle(tr("LightIM - Login"));

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *logo = new QLabel("LightIM");
    logo->setStyleSheet("font: 15pt; font-weight: 600; color:#000;");

    QLabel *labelUsername = new QLabel(tr("UserName:"));
    labelUsername->setStyleSheet("font: 12pt; color:#000;");
    QLabel *labelPassword = new QLabel(tr("Password:"));
    labelPassword->setStyleSheet("font: 12pt;");


    editUserName = new QLineEdit;
    editUserName->setFixedSize(300, 40);
//    editUserName->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
//    editUserName->setMinimumHeight(40);
//    editUserName->setMaximumHeight(40);

    editUserName->setPlaceholderText("username");
    editPassword = new QLineEdit;
    editPassword->setFixedSize(300, 40);
    editPassword->setEchoMode(QLineEdit::Password);
    editPassword->setPlaceholderText("password");

    btnLogin = new QPushButton(tr("Login"));
    btnLogin->setStyleSheet("QPushButton{ width: 60px; height: 40px; background: #5DADE2; border-radius: 6px; color: #fff; font: 12pt}"
                            "QPushButton:hover{ background: #57A0D1}"
                            "QPushButton:pressed{ background: #5599C6 }");


    QGridLayout *gridLayout = new QGridLayout(this);

    for(int i = 0; i < 5; i++){
        gridLayout->setRowStretch(i, 1);
    }


    gridLayout->addWidget(logo, 0, 2, 1, 3, Qt::AlignTop);

    gridLayout->addWidget(labelUsername, 2, 0, 1, 1);
    gridLayout->addWidget(editUserName, 2, 1, 1, 4);

    gridLayout->addWidget(labelPassword, 3, 0, 1, 1);
    gridLayout->addWidget(editPassword, 3, 1, 1, 4);

    gridLayout->addWidget(btnLogin, 4, 2, 1, 1);


    gridLayout->setContentsMargins(100, 60, 100, 90);



    connect(btnLogin, SIGNAL(clicked()), this, SLOT(login()));
    setLayout(gridLayout);

    resize(600, 400);
}


void Login::login(){
    QString username = editUserName->text();
    QString password = editPassword->text();
//    qDebug() << username;

    if(username.isEmpty()){
        QMessageBox::information(this, tr("error"), tr("username can't be empty!"));
        return;
    }
    emit display(1);
    emit sendData(username, password);
}
