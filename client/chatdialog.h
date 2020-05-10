#ifndef CHATDIALOG_H
#define CHATDIALOG_H

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
public slots:
    void sendEvent();
    void appendMessage(QString from, QString content);


signals:
    void sendMessage(QString from, QString content);

};

#endif // CHATDIALOG_H
