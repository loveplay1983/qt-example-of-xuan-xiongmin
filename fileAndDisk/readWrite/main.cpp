#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


void write(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly |
                  QFile::Text))
    {
        qDebug() << "Could not open file for writing...";
        return;

    }

    // To write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out << "hello world" << '\n' << "dakljda";
    file.flush();
    file.close();
}

void read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|
                  QFile::Text))
    {
        qDebug() << "Could not open the specified file...";
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    qDebug() << text;

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "C:\\Users\\Administrator\\Workspace\\xuan_work\\programming\\Qt\\Qt5Test\\fileAndDisk\\readWrite\\test.txt";
    write(filename);
    read(filename);

    return a.exec();
}
