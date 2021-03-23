#ifndef CCUTILS_H
#define CCUTILS_H

#include <QMainWindow>
#include "headers.h"
#include "cancelbed.h"
#include "cancelpzzxsmile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CCUtils; }
QT_END_NAMESPACE

class CCUtils : public QMainWindow
{
    Q_OBJECT

public:
    CCUtils(QWidget *parent = nullptr);
    ~CCUtils();


    void init();    // class initialization
    void sqls();    // sql combinations for all the utils
    QString dbConfig(QString);// database configuration references
    void conHisDatabase(QString, QString, QString);


public slots:

    // start menu
    void exitApp();
    void aboutApp();

    // utils menu
    void cancelBed();
    void cancelSmile();


private:
    Ui::CCUtils *ui;

    // database refs
    QString conHisString;
    QSqlDatabase dbObject;

    // canceclbed widget
    CancelBed *cancelBedNum;
    CancelPzzxSmile *cancelPzzxSmile;
};
#endif // CCUTILS_H
