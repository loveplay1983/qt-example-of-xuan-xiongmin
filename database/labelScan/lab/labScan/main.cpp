#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // login form
    Loginform login;
    // window forms
    MainWindow mainwin;

    // open each form by the login validation
    if(login.exec() == QDialog::Accepted)
    {
        mainwin.show();
        return a.exec();
    }
    else return 0;
}
