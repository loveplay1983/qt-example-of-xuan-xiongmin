#include "detectrestart.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DetectRestart w;
//    w.show();
    w.hide();
    return a.exec();
}
