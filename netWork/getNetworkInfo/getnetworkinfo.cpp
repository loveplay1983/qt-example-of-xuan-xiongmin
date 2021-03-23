#include "getnetworkinfo.h"
#include "ui_getnetworkinfo.h"
#include <QtDebug>

getNetworkInfo::getNetworkInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::getNetworkInfo)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("Network infomation"));
    this->resize(400, 150);
    // Gui components
    labelHost = new QLabel(tr("HostName:"));
    lineEditHostName = new QLineEdit;
    labelIp = new QLabel(tr("Ip Address:"));
    lineEditAddr = new QLineEdit;
    btnDetail = new QPushButton(tr("Details"));

    // layout
    theLayout = new QGridLayout(this); //this indicates the QGridLayout is bound to its parent window therefore the getnetworkinfo class
    theLayout->addWidget(labelHost, 0, 0);
    theLayout->addWidget(lineEditHostName, 0, 1);
    theLayout->addWidget(labelIp, 1, 0);
    theLayout->addWidget(lineEditAddr, 1, 1);
    theLayout->addWidget(btnDetail, 2, 0, 1, 2); // 2, 0, 1, 2 indicates the second row, 0 index, one button, it takes 2 components wide
    getHostInfo();
    connect(btnDetail, SIGNAL(clicked()), this, SLOT(slotDetails()));
}

void getNetworkInfo::getHostInfo()
{
    QString hostName = QHostInfo::localHostName();
    lineEditHostName->setText(hostName);
    QHostInfo hostInfo = QHostInfo::fromName(hostName);

    // get host ip list
    QList<QHostAddress> listAddr = hostInfo.addresses();
    if(!listAddr.isEmpty())
    {
        lineEditAddr->setText(listAddr.at(listAddr.count()-1).toString());
    }
    for (int eachAddr = 0; eachAddr < listAddr.count(); eachAddr++) {
        if (listAddr.at(eachAddr).toString().endsWith("1.100"))
        {
            qDebug() << listAddr.at(eachAddr).toString();
        }

    }

}

void getNetworkInfo::slotDetails()
{
    QString detail = "";
    QList<QNetworkInterface> listNetworkInterface = QNetworkInterface::allInterfaces();

    for (int each = 0; each < listNetworkInterface.count(); each++)
    {
        QNetworkInterface interface = listNetworkInterface.at(each);
        detail = detail + tr("Device: ") + interface.name() + "\n";
        detail = detail + tr("Mac address: ") + interface.hardwareAddress() + "\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

        for (int eachEntry = 1; eachEntry < entryList.count(); eachEntry++)
        {
            // loop through each network address entry
            QNetworkAddressEntry entry = entryList.at(eachEntry);
            detail = detail + "\t" + tr("ip addr: ") + entry.ip().toString() + "\n";
            detail = detail + "\t" + tr("subnet mask: ") + entry.netmask().toString() + "\n";
            detail = detail + "\t" + tr("broadcast: ") + entry.broadcast().toString() + "\n";
        }
    }
    QMessageBox::information(this, tr("Details"), detail);
}



getNetworkInfo::~getNetworkInfo()
{
    delete ui;
}

