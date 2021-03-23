#include "getnetworkinfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    getNetworkInfo w;
    w.show();
    return a.exec();
}
