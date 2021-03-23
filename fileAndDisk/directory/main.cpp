#include <QCoreApplication>
#include <QStringList>
#include <QString>
#include <QDir>
#include <QtDebug>



qint64 du(const QString &path)
{
    QDir dir(path);
    qint64 size = 0;
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        size += fileInfo.size();  // get file size
    }
    foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        size += du(path+QDir::separator()+subDir);
    }

    char unit ='B';
    qint64 curSize=size;
    if(curSize > 1024)
    {
        curSize /= 1024;
        unit = 'K';        // if size greater than 1024Byte than it is now KB
        if(curSize>1024)
        {
            curSize/=1024;
            unit='M';      // if size greater than 1024KB then it is now MB
            if (curSize>1024)
            {
                curSize /= 1024;
                unit='G';  // if size greater than 1024MB then it is now GB
            }
        }
    }
    // Returns str as a const char *. This is equivalent to str.toLocal8Bit().constData().
    qDebug() << "Current size => " << curSize << unit << "\t" << qPrintable(path) << endl;
    return size;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList args = a.arguments();
    QString path;
    if(args.count() > 1)
    {
        path = args[1];
    }
    else
    {
        path = QDir::currentPath();
    }
    qDebug() << path << endl;
    du(path);
    return a.exec();
}
