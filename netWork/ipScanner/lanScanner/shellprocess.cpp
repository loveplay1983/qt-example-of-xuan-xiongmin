#include "shellprocess.h"
#include <QtCore>

ShellProcess::ShellProcess(QObject *parent): QThread(parent){
}

//ShellProcess::~ShellProcess(){
//}

QStringList ShellProcess::getIpRange() {
    return this->ipRange;
}

void ShellProcess::setIpRange(QStringList ipRange) {
    this->ipRange = ipRange;
}

void ShellProcess::run() {

    QString ip;
    foreach( ip, ipRange ){

        QString cmdStr = QString("ping %1 -n -2 -w %2").arg(ip).arg(1000);
        QProcess cmd;
        cmd.start(cmdStr);
        cmd.waitForReadyRead(1000);
        cmd.waitForFinished(1000);

        QString hostResponse = cmd.readAll();
        if(hostResponse.indexOf("TTL") == -1){
            emit commandFailed(ip);
            qDebug() << "shell ping " + ip + " failed";
        } else {
            emit commandSuccess(ip);
            qDebug() << "shell ping " + ip + " success";
        }
    }
}

