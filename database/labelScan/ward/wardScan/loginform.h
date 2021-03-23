#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "headers.h"
#include <QDialog>


extern QString uName;
extern QString uPass;

namespace Ui {
class Loginform;
}

class Loginform : public QDialog
{
    Q_OBJECT

public:
    explicit Loginform(QWidget *parent = nullptr);
    ~Loginform();

    void init();                 // initialization
    void sigSlots();             // signals and slots
    void conDb();                // connect to mysql db

public slots:
    void login();
    void quit();

private:
    Ui::Loginform *ui;

    QSqlDatabase dbConnection;
    QSqlTableModel *loginModel;

};

#endif // LOGINFORM_H
