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
    void login();

public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void display(int number);
    void sendData(QString username, QString passsword);

};

#endif // LOGIN_H
