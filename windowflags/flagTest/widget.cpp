#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Widget::setWindowFlag(Qt::FramelessWindowHint);
    Widget::setWindowFlag(Qt::WindowType(Qt::WindowFullScreen));
}

Widget::~Widget()
{
    delete ui;
}

