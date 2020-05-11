#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

    client = new QTcpSocket;

    connect(client, SIGNAL(connected()),this, SLOT(connected()));
    connect(client, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(client, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(client, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    client->connectToHost("localhost", 9090);


    if(!client->waitForConnected(5000)){
        qDebug() << "connect error:" << client->errorString();
    }
}

void Client::connected(){
    qDebug() << "connect success!";
    client->write("admin");
}

void Client::disconnected(){
    qDebug() << "disconnected!";
}

void Client::bytesWritten(qint64 bytes){
    qDebug() << bytes << " bytes written.";
}

void Client::readyRead(){
    qDebug() << "ready read.";
    qDebug() << client->bytesAvailable();


    QByteArray *buffer = new QByteArray();

//    client->read

    QByteArray buff = client->readAll();

    qDebug() << buff;
}
