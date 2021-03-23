#ifndef CANCELBED_H
#define CANCELBED_H

#include <QWidget>
#include "headers.h"
//#include <stdio.h>
//#include <iostream>
//#include <string>

namespace Ui {
class CancelBed;
}

class CancelBed : public QWidget
{
    Q_OBJECT

public:
    explicit CancelBed(QWidget *parent = nullptr);
    ~CancelBed();

    void init();
    void openDb();

public slots:

    void cancelIt();
    void exitDlg();

private:
    Ui::CancelBed *ui;

    QSqlDatabase db;
};

#endif // CANCELBED_H
