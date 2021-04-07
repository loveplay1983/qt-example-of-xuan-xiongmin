#include "ipscanner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IpScanner w;
    w.show();
    return a.exec();
}
