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
    editUserName->setPlaceholderText("username");
    editPassword = new QLineEdit;
    editPassword->setEchoMode(QLineEdit::Password);
    editPassword->setPlaceholderText("password");

    btnLogin = new QPushButton(tr("Login"));
    btnLogin->setStyleSheet(" width: 60px; height: 40px; background: #5DADE2; border-radius: 6px; color: #fff; font: 12pt");


    QGridLayout *gridLayout = new QGridLayout(this);

    for(int i = 0; i < 5; i++){
        gridLayout->setRowStretch(i, 1);
    }


    gridLayout->addWidget(logo, 0, 2, 1, 3);

    gridLayout->addWidget(labelUsername, 1, 0, 1, 1);
    gridLayout->addWidget(editUserName, 1, 1, 1, 4);

    gridLayout->addWidget(labelPassword, 2, 0, 1, 1);
    gridLayout->addWidget(editPassword, 2, 1, 1, 4);

    gridLayout->addWidget(btnLogin, 3, 2, 1, 1);


    gridLayout->setContentsMargins(100, 60, 100, 90);



    setLayout(gridLayout);

    resize(600, 400);

}
