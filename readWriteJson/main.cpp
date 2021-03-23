#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile file(QDir::currentPath() + "/test.json");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open failed!";
    }
    else
    {
        QJsonObject jsonObj;
        jsonObj.insert("ip", "192.168.1.100");
        jsonObj.insert("port", "8888");

        // set up json object by QJsonDocument
        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObj);


        // write json file
        file.write(jsonDoc.toJson());
        file.close();

        qDebug() << "File configured!";
    }

    return a.exec();
}
