#include "ipscanner.h"
#include "ui_ipscanner.h"

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


// initialization
void IpScanner::init(){

    // connect signals and slots
    connect(ui->ipRange, SIGNAL(activated(const QString &)), this, SLOT(onIpActivated(const QString &)));
    connect(ui->saveOutput, SIGNAL(clicked()), this, SLOT(saveOutput()));
}



// slots
void IpScanner::onIpActivated(const QString &ipAddr)
{
    /* when the combobox item is activated, the scanning will be triggered, after that display it on the plaintexitedit */
    runNbtscan = new QProcess(this);
    runNbtscan->start("cmd", QStringList()<<"/c"<<"netscan "<<ipAddr);
    runNbtscan->waitForStarted();
    runNbtscan->waitForFinished(-1);
    QString hostInfo = QString::fromLocal8Bit(runNbtscan->readAllStandardOutput());

//    QMessageBox testMsg;
//    testMsg.setText(hostInfo);
//    testMsg.exec();

    ui->ipLog->setPlainText(hostInfo);

}

void IpScanner::saveOutput(){

}

