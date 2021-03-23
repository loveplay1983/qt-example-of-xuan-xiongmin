#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>
//#include <QSqlDatabase>
#include <QTableView>
#include <QSqlQueryModel>
#include <QTextCodec>
#include <QString>

namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = nullptr);
    ~SearchForm();
    void init();

public slots:
    void query();
    void showDateRnage();
    void hideDateRange();

private:
    Ui::SearchForm *ui;

    QTableView *labelRec;   // show the label record
    // the model which connects sqlite3 db and the UI as it will control hwo the data display via tableview
    QSqlQueryModel *model;

    int width;

};

#endif // SEARCHFORM_H
