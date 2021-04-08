#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("诸暨市人民医院");
    app.setApplicationName("Lan Test Utility");
    MainWindow w;
    w.setWindowTitle("局域网测试工具(诸人医计算机中心--测试版)");
    w.show();

    return app.exec();
}
