#include "client.h"
#include "tools.h"
#include "globals.h"

#include <QDataStream>
#include <QDateTime>

Client::Client(QObject *parent) : QObject(parent)
{

    client = new QTcpSocket;

    connect(client, SIGNAL(connected()),this, SLOT(connected()));
    connect(client, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(client, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(client, SIGNAL(readyRead()),this, SLOT(readyRead()));
}

void Client::start(){
    qDebug() << "connecting...";

    client->connectToHost("localhost", 9090);


    if(!client->waitForConnected(5000)){
        qDebug() << "connect error:" << client->errorString();
    }
}

void Client::connected(){
    qDebug() << "connect success!";

    client->write(loginUser.toLocal8Bit());
    qDebug() << "login sucess!";
}

void Client::disconnected(){
    qDebug() << "disconnected!";
}

void Client::bytesWritten(qint64 bytes){
    qDebug() << bytes << " bytes written.";
}

void Client::readyRead(){
    qDebug() << "ready read.";

    QByteArray buff = client->readAll();

//    qDebug() << buff;

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

    emit receiveMsg(time, from, content);
}

void Client::sendMsg(QString &to, QString &content){
    QByteArray buff;

    qint64 timeStamp = QDateTime::currentSecsSinceEpoch();
    QByteArray timeBuff;
    QDataStream timeStream(&timeBuff, QIODevice::WriteOnly);
    timeStream << timeStamp;
    buff.push_back(timeBuff);

    QByteArray fromBuff(loginUser.toUtf8());
    for(int i = fromBuff.size(); i < 16; i++) fromBuff.push_back('\0');
    QByteArray toBuff(to.toUtf8());
    for(int i = toBuff.size(); i < 16; i++) toBuff.push_back('\0');
    buff.push_back(fromBuff);
    buff.push_back(toBuff);


    qint16 contentLen = content.size();
    QByteArray lenBuff, contentBuff(content.toUtf8());
    QDataStream lenStream(&lenBuff, QIODevice::WriteOnly);
    lenStream << contentLen;
    buff.push_back(lenBuff);
    buff.push_back(contentBuff);

    qDebug() << buff;
    client->write(buff);
}
