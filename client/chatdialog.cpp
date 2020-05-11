#include "chatdialog.h"
#include "mainwindow.h"
#include "globals.h"

#include <QtWidgets>


ChatDialog::ChatDialog(QWidget *parent) : QWidget(parent)
{

    textEdit = new QTextEdit;
    textEdit->setReadOnly(true);
    textEdit->setFocusPolicy(Qt::NoFocus);
    inputEdit = new QPlainTextEdit;
    inputEdit->setFocusPolicy(Qt::StrongFocus);
    inputEdit->setMinimumHeight(30);
    inputEdit->setMaximumHeight(30);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->setMargin(0);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    btnSend = new QPushButton(tr("Send"));
    btnSend->setMaximumWidth(60);
    bottomLayout->addWidget(inputEdit);
    bottomLayout->addWidget(btnSend, Qt::AlignRight);

    vlayout->addWidget(textEdit);
    vlayout->addLayout(bottomLayout);

    vlayout->setStretch(0, 10);
    vlayout->setStretch(1, 1);

    setLayout(vlayout);

    connect(btnSend, SIGNAL(clicked()), this, SLOT(sendEvent()));
}

void ChatDialog::sendEvent(){
    QString content = inputEdit->toPlainText();
    emit appendMessage(userList[curUserIndex], content);
}

void ChatDialog::appendMessage(QString from, QString content){
    qDebug() << content;

    QTextTableFormat tableFormat;
    tableFormat.setBorder(0);

    QTextCursor cursor(textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText(from + ':');
    table->cellAt(0, 1).firstCursorPosition().insertText(content);
    QScrollBar *bar = textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}
