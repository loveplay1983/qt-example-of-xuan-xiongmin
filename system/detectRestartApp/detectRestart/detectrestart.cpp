#include "detectrestart.h"
#include "ui_detectrestart.h"

DetectRestart::DetectRestart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DetectRestart)
{
    ui->setupUi(this);

    this->init();

}

DetectRestart::~DetectRestart()
{
    delete ui;
}


// Define QActions, i.e. the menu content
void DetectRestart::createActions(){

    // actions
    minimizeAction = new QAction(tr("最小化"), this);
    maximizeAction = new QAction(tr("最大化"), this);
    restoreAction = new QAction(tr("恢复窗口"), this);
    quitAction = new QAction(tr("退出"), this);
}

// Define QSystemTrayIcon and its relevant menus
void DetectRestart::createTrayIcon(){
    iconMenu = new QMenu(this);
    iconMenu->addAction(minimizeAction);
    iconMenu->addAction(maximizeAction);
    iconMenu->addAction(restoreAction);
    iconMenu->addSeparator();
    iconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(iconMenu);
    trayIcon->setIcon(QIcon(":/icon/icon"));
    trayIcon->show();
}

// if tryIcon is clicked
void DetectRestart::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    {
        showNormal(); break;
    }
    case QSystemTrayIcon::DoubleClick:
        showNormal(); break;
    default: break;
    }
}


// show trayIcon message when closeEvent is triggered
void DetectRestart::showMsg(){
    trayIcon->showMessage(tr("定时重启进程"), tr("定时扫描自助机进程，如果出现异常退出则自动重启"), QIcon(":/icon/icon"), 5000);
}

// overload function of QWidget, closeEvent()
void DetectRestart::closeEvent(QCloseEvent *event){
    this->showMsg();
    this->hide();
    event->ignore();   // ignore the downstream signal, i.e. ignore the signal which would cause the program to quit, keep the program alive
}

// Connect signal and slot for actions
void DetectRestart::createconnection(){
    // Clicked event
    connect(trayIcon, &QSystemTrayIcon::activated, this, &DetectRestart::iconActivated);

    // actions signal and slot
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);
}


void DetectRestart::timer(){
    processTimer = new QTimer;
    processTimer->setInterval(5000);
    processTimer->start();
    connect(processTimer, &QTimer::timeout, this, &DetectRestart::detector);
}


void DetectRestart::detector(){
    /*
    processControl = new QProcess;
//    QString taskName1 = "tasklist";
//    QString taskName2 = "C:\\Users\\Administrator\\Workspace\\xuan_work\\programming\\Qt\\Qt5Test\\netWork\\ipScanner\\deploy\\ouput\\ip_scan.exe";
    QString selfService = "C:\\Users\\Administrator\\Desktop\\NgariYYT.exe.lnk";
    processControl->start("tasklist", QStringList() << "-fi" << "imagename eq NgariYYT.exe");
    processControl->waitForReadyRead(1000);
    processControl->waitForFinished(1000);
    QString returned = processControl->readAll();

    qDebug() << returned;
    qDebug() << returned.indexOf("Image Name");
    qDebug() << returned.length();

    if(returned.contains("NgariYYT.exe", Qt::CaseInsensitive)){
        qDebug() << "The program is running";
    } else {
        processControl->start(selfService);
    }
*/

    processControl = new QProcess;
    QString test = "run.bat";
    processControl->start("tasklist", QStringList() << "-fi" << "imagename eq NgariYYT.exe");
    processControl->waitForReadyRead(1000);
    processControl->waitForFinished(1000);
    QString returned = processControl->readAll();

    if(returned.contains("NgariYYT.exe", Qt::CaseInsensitive)){
        qDebug() << "The program is running";
    } else {
        processControl->start(test);
    }
}

// Initialize the program
void DetectRestart::init(){
    DetectRestart::createActions();
    DetectRestart::createTrayIcon();
    DetectRestart::createconnection();
    DetectRestart::timer();   // check the process liveness periodically
}


