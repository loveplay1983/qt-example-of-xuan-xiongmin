#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->init();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::init()
{
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clicked_()));
}

void Widget::clicked_()
{
    QMessageBox::Information(this, tr("test"), "hello world");
}

