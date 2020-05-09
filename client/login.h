#ifndef LOGIN_H
#define LOGIN_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Login : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *editUserName;
    QLineEdit *editPassword;
    QPushButton *btnLogin;

private slots:


public:
    explicit Login(QWidget *parent = nullptr);

signals:

};

#endif // LOGIN_H
