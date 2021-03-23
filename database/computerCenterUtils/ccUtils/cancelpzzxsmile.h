#ifndef CANCELPZZXSMILE_H
#define CANCELPZZXSMILE_H

#include <QWidget>
#include "headers.h"

namespace Ui {
class CancelPzzxSmile;
}

class CancelPzzxSmile : public QWidget
{
    Q_OBJECT

public:
    explicit CancelPzzxSmile(QWidget *parent = nullptr);
    ~CancelPzzxSmile();

    void init();
    void openDb();

public slots:
    void cancelIt();
    void exitDlg();

private:
    Ui::CancelPzzxSmile *ui;

    QSqlDatabase db;

};

#endif // CANCELPZZXSMILE_H
