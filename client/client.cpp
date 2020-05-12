#include "client.h"
#include "tools.h"

#include <QDataStream>
#include <QDateTime>

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

    qint64 timeStamp = QDateTime::currentSecsSinceEpoch();
//    qDebug() << timeStamp;

    QDateTime localAddSecs = QDateTime::fromSecsSinceEpoch(timeStamp);
//    qDebug() << localAddSecs.toString("yyyy-MM-dd hh:mm:ss");

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


//    client->read

    QByteArray buff = client->readAll();

    qDebug() << buff;

    QDataStream stream(buff.mid(0, 8));
    qint64 timestamp;
    stream >> timestamp;

    QDateTime localAddSecs = QDateTime::fromSecsSinceEpoch(timestamp);
    QString time = localAddSecs.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << time;

    QString from = Tools::parseName(buff.mid(8, 16));
    qDebug() << from;

    qint16 contentLen;
    QDataStream lenStream(buff.mid(42, 2));
    lenStream >> contentLen;

    QString content(buff.mid(42, contentLen));
    qDebug() << content;

}
