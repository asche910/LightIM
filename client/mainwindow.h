#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    static QList<QString> userList;
//    static int curUserIndex;

signals:
    void display(int number);

public slots:
    void handleLogin(QString username, QString password);
    void listListen(int idx);

};


#endif // MAINWINDOW_H
