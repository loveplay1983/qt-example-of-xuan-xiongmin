#include "fileview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fileView w;
    w.show();
    return a.exec();
}
