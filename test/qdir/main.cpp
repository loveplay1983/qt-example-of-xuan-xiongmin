/***************** QDir QString exam *********************/

#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include <string>
#include <QTextCodec>
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString test = "";
    test += QDir::currentPath() + "/test.json";
    qDebug() << test;   // output qstring object
    if(typeid(test) == typeid(QString))
    {
        cout << "QString" << endl;
    }

    // string and qstring conversion
    string testStdString = test.toStdString();
    QTextCodec* myCode = QTextCodec::codecForName("gb18030");
    if(nullptr != myCode)
    {
        testStdString = myCode->fromUnicode(test).data();
        cout << testStdString << endl;
        if(typeid(testStdString) == typeid(string))
        {
            cout << "string" << endl;
        }

    }


    return a.exec();
}


/*
QString qString("好好学习天天向上");
    std::string stdString = qString.toStdString();
    QTextCodec* pCode = QTextCodec::codecForName("gb18030");
    // 如果code为0，表示在运行的机器上没有装gb18030字符集。不过一般的中文windows系统中都安装了这一字符集
    if (NULL != pCode)
    {
        stdString = pCode->fromUnicode(qString).data();
    }


std::string stdString = "好好学习天天向上";
    QString strQ = QString::fromLocal8Bit(stdString.c_str());


int a;
if(typeid(a) == typeid(int)) cout<<"int";
if(typeid(a) == typeid(float)) cout<<"float";
*/
