#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void init();
    void connects();

public slots:
    void updateProgress();

private:
    Ui::Widget *ui;

    // qtimer
    QTimer *timer;
    // qprogressbar
    QProgressBar *progress;

    // layout and buttons
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QPushButton *yes;
    QPushButton *no;


};
#endif // WIDGET_H
