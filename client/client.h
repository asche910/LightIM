#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *client;

};

#endif // CLIENT_H
