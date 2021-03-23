#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr, Qt::WindowFlags flag=nullptr);
    ~Dialog();

public slots:
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::Dialog *ui;

    QLabel *left;
    QLabel *middle;
    QLabel *right;

    QLabel *state;

    QImage leftImg;
    QImage MiddleImg;
    QImage RightImg;
};
#endif // DIALOG_H
