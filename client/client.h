#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void start();
signals:
    void receiveMsg(QString &time, QString &from, QString &content);

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

    void sendMsg(QString &to, QString &content);
private:
    QTcpSocket *client;

};

#endif // CLIENT_H
