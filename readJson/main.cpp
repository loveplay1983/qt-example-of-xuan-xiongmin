#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QSysInfo>
#include <cstdlib>
#include <iostream>
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    // A macro of Qt that eliminates warnings of unused variables, has no practical effect
    // defined as, #define Q_UNUSED(x) (void)x

    Q_UNUSED( argc );
    Q_UNUSED( argv );

    if (QSysInfo::productType() == "windows" ||
            QSysInfo::productType() == "winrt")
    {
        system("chcp 65001");   // change current code page to utf-8, system function is a c/c++ implementation for calling system command in windows
    }

    cout << "Current os type is -> " << QSysInfo::productType().toStdString() << endl;

    QFile file(QDir::currentPath() + "/test.json");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Open file error";
        exit(1);
    }
    else
    {
        qDebug() << "Open file successfully";
        QJsonParseError jsonParseError;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll(), &jsonParseError);

        // check json file existance and status of parsing
        if(!jsonDocument.isNull() && jsonParseError.error == QJsonParseError::NoError)
        {
            qDebug() << "Parse json file successfully";
            if(jsonDocument.isObject())
            {
                QJsonObject jsonObject = jsonDocument.object(); // assign jsonDocument object to QJsonObject class
                if(jsonObject.contains("ip"))
                {
                    qDebug() << "ip -> " << jsonObject.value("ip").toString() << endl;
                }
            }
        }

    }
    QCoreApplication a(argc, argv);

    return a.exec();
}
