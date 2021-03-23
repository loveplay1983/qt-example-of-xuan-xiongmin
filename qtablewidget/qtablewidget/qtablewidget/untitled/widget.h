#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTimer>
#include <QFont>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void setUpTable();     // show table data
    void autoclear();
    void clearContent();   // clear table data

private:
    Ui::Widget *ui;

    QTimer *timer;


};

#endif // WIDGET_H
