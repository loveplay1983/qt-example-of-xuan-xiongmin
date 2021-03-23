#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    btn = new QPushButton("hello world");
//    label = new QLabel;
//    label->setText("he");
//    mainlayout = new QVBoxLayout(this);
//    mainlayout->addWidget(btn);
//    mainlayout->addWidget(label);

    ui->b->setText("dkaljfdsa");

}

Dialog::~Dialog()
{
    delete ui;
}

