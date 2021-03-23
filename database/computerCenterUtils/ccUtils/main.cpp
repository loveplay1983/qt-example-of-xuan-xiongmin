/*********************** README********************************************
** This is the "play for fun" computer center depart utils application.
** This program is not guaranteed to be safe and please do not use it under
** high security-demand environment.
*/

#include "ccutils.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCUtils w;
    w.show();
    return a.exec();
}
