#include "ipscanner.h"
#include "ui_ipscanner.h"

#define COL1 0
#define COL2 1


IpScanner::IpScanner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IpScanner)
{
    ui->setupUi(this);
    this->init();
}

IpScanner::~IpScanner()
{
    delete ui;
}

int IpScanner::rowNum = 0;

// initialization
void IpScanner::init()
{
    // row number initialization
    //    rowNum = 0;

    // initialize table widget
    ui->hostInfoTable->horizontalHeader()->setStretchLastSection(true);
    ui->hostInfoTable->setRowCount(255);

    // connect signals and slots
    connect(ui->netAddr, SIGNAL(returnPressed()), this, SLOT(onNetAddrEntered()));
    connect(ui->saveOutput, SIGNAL(clicked()), this, SLOT(saveOutput()));
    connect(ui->resetList, SIGNAL(clicked()), this, SLOT(resetOutput()));
}


// slots
void IpScanner::lookupHostInfo(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError)
    {
        QMessageBox::information(this, tr("Error"), host.errorString());
        return;
    }

    if(host.addresses()[0].toString() == host.hostName())
        return;

    // display ip addr and hostname on the table
    ipItem = new QTableWidgetItem;
    hostName = new QTableWidgetItem;
    ipItem->setText(host.addresses()[0].toString());
    hostName->setText(host.hostName());

    if(ipItem->text() != hostName->text())
    {
        ipItem->setTextColor(QColor(Qt::red));
        hostName->setTextColor(QColor(Qt::red));
    }

    ui->hostInfoTable->setItem(rowNum, COL1, ipItem);
    ui->hostInfoTable->setItem(rowNum, COL2, hostName);

    rowNum++;
}

void IpScanner::onNetAddrEntered()
{
    ui->hostInfoTable->setRowCount(255);

    // After the network address is input and the enter is pressed
    for(int i = 1; i < 256; i++)
    {
        QHostInfo::lookupHost(QString(ui->netAddr->text()).append(".%1").arg(i), this, SLOT(lookupHostInfo(QHostInfo)));
    }
}



void IpScanner::saveOutput()
{

}

void IpScanner::resetOutput()
{
//    int rowCount = ui->hostInfoTable->rowCount();
//    for(int i = 0; i < rowCount; i++)
//    {
//        ui->hostInfoTable->removeRow(0);
//    }
    ui->hostInfoTable->setRowCount(0);
}

