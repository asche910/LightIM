#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include "client.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

class ChatDialog : public QWidget
{
    Q_OBJECT
public:
    explicit ChatDialog(QWidget *parent = nullptr);


    QTextEdit *textEdit;
    QPlainTextEdit *inputEdit;
    QPushButton *btnSend ;

    Client *client;
public slots:
    void sendClicked();
    void appendMessage(QString from, QString content);
    void receiveMsg(QString &time, QString &from, QString &content);


signals:
    void sendMsg(QString &to, QString &content);

};

#endif // CHATDIALOG_H
