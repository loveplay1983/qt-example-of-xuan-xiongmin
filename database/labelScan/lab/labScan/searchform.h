#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <loginform.h>
#include <QWidget>

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
    void openDb();

public slots:
    void search();



private:
    Ui::SearchForm *ui;

    QSqlQueryModel *searchModel;
    QSqlDatabase db;
};

#endif // SEARCHFORM_H
