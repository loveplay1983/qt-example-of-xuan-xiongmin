#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QTableView>
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    onlineCount = 0;
    ui->setupUi(this);
    ui->tableWidget->setWindowTitle("ip list");
    ui->tableWidget->setSortingEnabled(false);           // disable sorting
    ui->tableWidget->verticalHeader()->setHidden(true);  // hide index column
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 200);

    QStringList header;
    header.append(QObject::tr("索引"));
    header.append(QObject::tr("IP地址"));
    header.append("是否在线?");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;");

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(startScan()));
    // sort column
    //    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortColumn(int)));
    //    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(resetList()));


    QString localIP = this->get_localmachine_ip();
    QStringList localIPList = localIP.split(".");
    // set default value.
    ui->lineEdit->setText(localIPList[0]+"."+localIPList[1]+"."+localIPList[2]+".1");
    ui->lineEdit_2->setText(localIPList[0]+"."+localIPList[1]+"."+localIPList[2]+".254");
    ui->label_local_ip->setText(localIP);
    loadingImage = new QMovie(":/images/loading.gif");
    ui->loadingLabel->setMovie(loadingImage);

    // initialize the progressbar for scanning ips
    currentScanNum = 0.0;
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
}

// get host name
//void MainWindow::sortColumn(int column){
//    ui->tableWidget->sortItems(column, Qt::AscendingOrder);
//}


//void MainWindow::lookupHostName(const QHostInfo &host, int hostIndex){
//    if(host.error() != QHostInfo::NoError){
//        qDebug() << "lookup host failed" << host.errorString();
//        return;
//    }
//    if(host.addresses()[0].toString() == host.hostName())
//        return;
//    // add hostname to table widget
//    QTableWidgetItem *hostItem = new QTableWidgetItem();
//    hostItem->setText(host.hostName());
//    ui->tableWidget->setItem(hostIndex, 1, hostItem);
//}


void MainWindow::onCommandSuccess(QString ip) {
    qDebug() << ip + " ping success";

    int hostIndex = scanHosts.indexOf(ip);


    // host name
    //        QHostInfo::lookupHost(QString(ip), this, SLOT(lookupHostName(QHostInfo, hostIndex)));
    //    QHostInfo host = QHostInfo::fromName(ip);
    //    if(host.error() != QHostInfo::NoError){
    //        qDebug() << "lookup host failed" << host.errorString();
    //        return;
    //    }
    //    QTableWidgetItem *hostItem = new QTableWidgetItem();
    //    hostItem->setText(host.hostName());
    //    ui->tableWidget->setItem(hostIndex, 1, hostItem);

    // host connection status icon
    QTableWidgetItem *statusItem = new QTableWidgetItem();
    statusItem->setIcon(QIcon(":/images/online_icon.png"));
    //    ui->tableWidget->setItem(hostIndex,2,statusItem);
    ui->tableWidget->setItem(hostIndex,2,statusItem);

    onlineCount++;
    onlineHosts << ip;
    //    currentHost = host.hostName();
    ui->onlineCount_label->setText(QString::number(onlineCount));  // show the totoal number of living host

    // add ip and host name to the onlineDevice list, will be used for displaying online hosts
    Device *device = new Device();
    device->setIp(ip);
    //    device->setName(currentHost);
    _onlineDevices.append(device);
}
void MainWindow::onCommandFailed(QString ip) {
    qDebug() << ip + " ping failed";

    int hostIndex = scanHosts.indexOf(ip);
    QTableWidgetItem *statusItem = new QTableWidgetItem();
    statusItem->setIcon(QIcon(":/images/offline_icon.png"));
    ui->tableWidget->setItem(hostIndex,2,statusItem);
    //    ui->tableWidget->setItem(hostIndex,2,statusItem);
    qDebug() << ip + " ping failed 111111";
}

void MainWindow::startScan() {

    QString ip1 = ui->lineEdit->text();
    QString ip2 = ui->lineEdit_2->text();
    QStringList ip1List = ip1.split(".");
    QStringList ip2List = ip2.split(".");

    if(ip1List.length() != 4){
        QMessageBox msgBox;
        msgBox.setText("Beginning ip not valid!");
        msgBox.exec();
        ui->lineEdit->setFocus();
        return;
    }

    if(ip2List.length() != 4){
        QMessageBox msgBox;
        msgBox.setText("Ending ip not valid!");
        msgBox.exec();
        ui->lineEdit_2->setFocus();
        return;
    }

    if(ip1List[0] != ip2List[0] || ip1List[1] != ip2List[1]) {
        QMessageBox msgBox;
        msgBox.setText("IP range must be in same lan!");
        msgBox.exec();
        ui->lineEdit_2->setFocus();
        return;
    }

    if(ip1List[2].toInt() > ip2List[2].toInt()) {
        QMessageBox msgBox;
        msgBox.setText("IP range not correct!");
        msgBox.exec();
        ui->lineEdit_2->setFocus();
        return;
    }else{
        if(ip1List[2].toInt() == ip2List[2].toInt()) {
            if(ip1List[3].toInt() >= ip2List[3].toInt()) {
                QMessageBox msgBox;
                msgBox.setText("IP range not correct!");
                msgBox.exec();
                ui->lineEdit_2->setFocus();
                return;
            }
        }else {

        }
    }

    if(ip1List[3].toInt() >= 255 || ip2List[3].toInt() >= 255 ){
        QMessageBox msgBox;
        msgBox.setText("IP not valid!");
        msgBox.exec();
        return;
    }

    QStringList ipRange;
    if(ip1List[2].toInt() == ip2List[2].toInt()){
        // 192.168.3.1 -> 192.168.3.240
        int startIPNumber = ip1List[3].toInt();
        int endIPNumber   = ip2List[3].toInt();
        for(int i=startIPNumber;i <= endIPNumber;++i){
            QString ip = ip1List[0] + "." + ip1List[1] + "." + ip1List[2] + "." + QString::number(i);
            ipRange << ip;
        }
    } else if(ip1List[2].toInt() < ip2List[2].toInt()){
        // 192.168.3.1 -> 192.168.5.240
        int startIPNumber = ip1List[2].toInt();
        int endIPNumber   = ip2List[2].toInt();
        int j=0;
        for(int i = startIPNumber;i <= endIPNumber; ++i){
            if(i == startIPNumber){
                for(j=ip1List[3].toInt();j <= 254;++j){
                    QString ip = ip1List[0] + "." + ip1List[1] + "." + QString::number(i) + "." + QString::number(j);
                    ipRange << ip;
                }
            } else if(i == endIPNumber){
                for(j = 2; j <= ip2List[3].toInt(); ++j){
                    QString ip = ip1List[0] + "." + ip1List[1] + "." + QString::number(i) + "." + QString::number(j);
                    ipRange << ip;
                }
            } else {
                for(j = 2; j <= 254; ++j){
                    QString ip = ip1List[0] + "." + ip1List[1] + "." + QString::number(i) + "." + QString::number(j);
                    ipRange << ip;
                }
            }
        }
    }

    onlineCount = 0;
    onlineHosts.clear();
    //initialize the progressbar for ip scanning
    currentScanNum = 0.0;
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
    // remove tablelist content
    ui->tableWidget->clearContents();
    // clear the QVector object which stores the living host data
    QVector<Device*>().swap(_onlineDevices);

    QString messageTip = "开始从IP "+ ip1 + "扫描到 " + ip2 + " ?";
    QMessageBox msgBox;
    msgBox.setWindowTitle("扫描IP");
    msgBox.setText(messageTip);
    msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    // start scanning, write index, ip addr to the first and second column respectively
    if(msgBox.exec() == QMessageBox::Yes){
        qDebug() << "Yes was clicked";
        this->scanHosts = ipRange;
        this->to_scanHosts = ipRange;
        ui->tableWidget->setRowCount(ipRange.size());
        for(int row_index=0;row_index<ipRange.size();++row_index) {
            QTableWidgetItem *rowInx = new QTableWidgetItem();
            rowInx->setData(Qt::DisplayRole, row_index+1);
            ui->tableWidget->setItem(row_index,0,rowInx);
            ui->tableWidget->setItem(row_index,1,new QTableWidgetItem(ipRange[row_index]));
        }

        int ipArraySize = ipRange.size();
        int perIPArraySize = ipArraySize / THREAD_SIZE;
        qDebug() << "ip in one thread size: " << perIPArraySize;
        int start_outer = 0;
        int start_innerer = 0;
        QStringList ip_in_thread[THREAD_SIZE];
        for(start_outer;start_outer<THREAD_SIZE;++start_outer){
            for(start_innerer =  start_outer*perIPArraySize;start_innerer< (start_outer+1) * perIPArraySize;start_innerer++) {
                ip_in_thread[start_outer] << ipRange[start_innerer];
            }
            qDebug() << "##### " << start_outer ;
            qDebug() << " ---- " << ip_in_thread[start_outer] << " .";
        }

        qDebug() << "start_innerer " << start_innerer ;
        qDebug() << "start_outer " << start_outer ;

        for(int new_start=start_innerer, thread_index=0;new_start<ipArraySize;new_start++){
            qDebug() << " ---- " << ipRange[new_start] << " .";
            ip_in_thread[thread_index] << ipRange[new_start];
            thread_index++;
        }

        // get the total nums of ip for scanning
        totalScanNum = (double)ipRange.size();

        /* start scanning within the certain sizes of system thread which was predefined by #define THREAD_SIZE 10*/
        ShellProcess *shellProcess;
        for(int i=0;i<THREAD_SIZE;i++){
            shellProcess= new ShellProcess(this);
            // update tablelist, mark and count the living host
            connect(shellProcess, SIGNAL(commandSuccess(QString)), this, SLOT(onCommandSuccess(QString)));
            connect(shellProcess, SIGNAL(commandFailed(QString)), this, SLOT(onCommandFailed(QString)));
            connect(shellProcess, SIGNAL(finished()), shellProcess, SLOT(deleteLater()));
            // update progressbar
            connect(shellProcess, SIGNAL(commandSuccess(QString)), this, SLOT(update_scanProgress(QString)));
            connect(shellProcess, SIGNAL(commandFailed(QString)), this, SLOT(update_scanProgress(QString)));
            shellProcess->setIpRange(ip_in_thread[i]);  // acquire the ip addrs list
            shellProcess->start();
        }

        ui->loadingLabel->show();
        loadingImage->start();

        // display scanning progressbar
        ui->progressBar->setVisible(true);
    }else {
        // do something else
        qDebug() << "Yes was *not* clicked";
    }
}

//void MainWindow::resetList(){
//    ui->tableWidget->clearContents();
//}


/*
 * name:generateRangeIP
 * usage:acquire localhost ip range
 * parameters:ip1, ip2
 * return:QStringList
 */
QStringList MainWindow::generateRangeIP(QString ip1, QString ip2) {
    QStringList ip1List = ip1.split(".");
    QStringList ip2List = ip2.split(".");
    //    if(ip1List.length() != 4 || ip2List.length() != 4){
    //        return NULL;
    //    }

    // #TODO

}

/*
 * name:get_localmachine_ip
 * usage:acquire localhost ip
 * parameters:null
 * return:QString
 */
QString MainWindow::get_localmachine_ip()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return ipAddress;
}


MainWindow::~MainWindow()
{
    delete loadingImage;
    delete ui;

}

void MainWindow::on_showOnlineDevicesButton_clicked() {
    ui->tableWidget->setRowCount(_onlineDevices.size());
    // sort columns
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    for(int row_index=0;row_index<_onlineDevices.size();++row_index) {
        ui->tableWidget->setItem(row_index,1,new QTableWidgetItem(_onlineDevices[row_index]->ip()));
        //        ui->tableWidget->setItem(row_index, 2, new QTableWidgetItem(_onlineDevices[row_index]->hostName()));
        QTableWidgetItem *statusItem = new QTableWidgetItem();
        statusItem->setIcon(QIcon(":/images/online_icon.png"));
        //        ui->tableWidget->setItem(row_index,2,statusItem);
        ui->tableWidget->setItem(row_index,2,statusItem);
    }
}

void MainWindow::on_testSSH_Button_clicked()
{
    // To-Do
}

void MainWindow::update_scanProgress(QString ip)
{
    currentScanNum += 1.0;
    double scanProgress = (currentScanNum/totalScanNum)*100;
    qDebug() << "ip" << ip << " scan finished!";
    qDebug() << "scan progress: " << scanProgress <<endl;
    ui->progressBar->setValue(scanProgress);
    if(100 == (int)scanProgress){//ip scan is done
        // disable the visibility of scanning icon and hide the progressbar after the ip scan is done
        ui->progressBar->setVisible(false);
        ui->loadingLabel->setVisible(false);
    }
}
