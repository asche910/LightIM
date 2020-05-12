#include "tools.h"

#include <QDebug>


Tools::Tools()
{

}

QString Tools::parseName(QByteArray arr){
    int idx = arr.indexOf('\0');
    return QString(arr.mid(0, idx));
}
