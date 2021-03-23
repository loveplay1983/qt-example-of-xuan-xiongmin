#include "ipscanner.h"
#include "ui_ipscanner.h"

IpScanner::IpScanner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IpScanner)
{
    ui->setupUi(this);
}

IpScanner::~IpScanner()
{
    delete ui;
}

