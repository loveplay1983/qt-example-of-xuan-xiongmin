#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->init();
    this->connects();

}


void Widget::init()
{
    timer = new QTimer();
    progress = new QProgressBar;
    vbox = new QVBoxLayout(this);
    hbox = new QHBoxLayout();
    yes = new QPushButton(tr("开始"));
    no = new QPushButton(tr("停止"));

    hbox->addWidget(yes);
    hbox->addWidget(no);
    vbox->addWidget(progress);
    vbox->addLayout(hbox);

    // progressbar
    progress->setRange(0, 100);
    progress->setValue(10);

    // timer
    timer->setInterval(1000);   // 1000ms <-> 1 second
}


void Widget::connects()
{
    connect(yes, SIGNAL(clicked()), timer, SLOT(start()));
    connect(no, SIGNAL(clicked()), timer, SLOT(stop()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateProgress()));
}

void Widget::updateProgress()
{
    int current = progress->value();
    current++;
    if(current >= 100) { timer->stop(); }
    progress->setValue(current);
}


Widget::~Widget()
{
    delete ui;
}

