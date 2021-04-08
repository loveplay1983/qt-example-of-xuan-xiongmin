# Local area network utility
> This project is built for lan user detection, remote control, the original code comes from github

* reference
  1. [QProcess调用外部ping程序实现网络状态检测](https://blog.csdn.net/houwenbin1986/article/details/52640315)
  2. [在Qt中使用QProcess类实现检测当前网络是否能ping通某段IP地址](https://blog.csdn.net/qq_37354286/article/details/77514876)
  3. [QTableWidget](https://www.cnblogs.com/sherlock-lin/articles/11708999.html)


* code sinppets
```
/*
 * Brief 检测当前网络是否能ping通某段IP地址
 * Param ip (QString) IP地址(类型：QString)
 * Return bool 是否能ping通传入的IP地址
 * /
 *
#include <QProcess>
bool QtPing(const QString ip)
{
    // #Linux指令 "ping -s 1 -c 1 IP"
    //QString cmdstr = QString("ping -s 1 -c 1 %1")
    //      .arg(ip);

    // #Windows指令 "ping IP -n 1 -w 超时(ms)"
    QString cmdstr = QString("ping %1 -n 1 -w %2")
            .arg(ip).arg(1000);

    QProcess cmd;
    cmd.start(cmdstr);
    cmd.waitForReadyRead(1000);
    cmd.waitForFinished(1000);

    QString response = cmd.readAll();
    if (res.indexOf("TTL") == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
```


```
//判断IP地址及端口是否在线
    static bool IPLive(QString ip, int port, int timeout = 1000) {
        QTcpSocket tcpClient;
        tcpClient.abort();
        tcpClient.connectToHost(ip, port);
        //100毫秒没有连接上则判断不在线
        return tcpClient.waitForConnected(timeout);
    }
//判断是否通外网
    static bool IsWebOk() {
        //能接通百度IP说明可以通外网
        return IPLive("115.239.211.112", 80);
    }
```

```
# QHostInfo
int nID = QHostInfo::lookupHost("5.254.113.102", this, SLOT(lookedUp(QHostInfo)));

void MainWindow::lookedUp(const QHostInfo &host)
{
    if (host.error() != QHostInfo::NoError) {
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }

    qDebug() << "Found hostName:" << host.hostName();
}
```

```
# export to excel file
lass TableToExcle : public QDialog
{
    Q_OBJECT

public:
    TableToExcle(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~TableToExcle();

private:
    Ui::TableToExcleClass ui;
    private slots:
        void addRowSlot();
        void delRowSlot();
        void exportSlot();
};

TableToExcle::TableToExcle(QWidget *parent, Qt::WFlags flags)
    : QDialog(parent, flags)
{
    ui.setupUi(this);
    ui.m_pTable->setColumnCount(4);
     QTableWidgetItem * item = new QTableWidgetItem("0");
    ui.m_pTable->setHorizontalHeaderItem ( 0, item );
    item = new QTableWidgetItem("1");
    ui.m_pTable->setHorizontalHeaderItem ( 1, item );
    item = new QTableWidgetItem("2");
    ui.m_pTable->setHorizontalHeaderItem ( 2, item );
    item = new QTableWidgetItem("3");
     ui.m_pTable->setHorizontalHeaderItem ( 3, item );
    ui.m_pTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui.m_pAddBtn,SIGNAL(clicked()),this,SLOT(addRowSlot()));
    connect(ui.m_pDelBtn,SIGNAL(clicked()),this,SLOT(delRowSlot()));
    connect(ui.m_pExportBtn,SIGNAL(clicked()),this,SLOT(exportSlot()));
}

TableToExcle::~TableToExcle()
{

}

void TableToExcle::addRowSlot()
{
   ui.m_pTable->insertRow(ui.m_pTable->rowCount());

}

void TableToExcle::delRowSlot()
{
   int index = ui.m_pTable->currentRow ();
   if (index > -1)
   {
       ui.m_pTable->removeRow(index);
   }
}

void TableToExcle::exportSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File")," ",tr("file (*.csv)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        bool ret = file.open( QIODevice::Truncate | QIODevice::WriteOnly);
        if(!ret)
            return;

        QTextStream stream(&file);
        QString conTents;
        QHeaderView * header = ui.m_pTable->horizontalHeader() ;
        if (header)
        {
            for ( int i = 0; i < header->count(); i++ )
            {
                QTableWidgetItem *item = ui.m_pTable->horizontalHeaderItem(i);
                if (!item)
                {
                    continue;
                }
                conTents += item->text() + ",";
            }
            conTents += "\n";
        }

        for ( int i = 0 ; i < ui.m_pTable->rowCount(); i++ )
        {
            for ( int j = 0; j < ui.m_pTable->columnCount(); j++ )
            {

                QTableWidgetItem* item = ui.m_pTable->item(i, j);
                if ( !item )
                    continue;
                QString str = item->text();
                str.replace(","," ");
                conTents += str + ",";
            }
            conTents += "\n";
        }
        stream << conTents;
        file.close();
    }
    if( QMessageBox::Yes == QMessageBox::information(0,QObject::tr("文件导出"),QString("文件导出成功,是否打开该文件？"),QMessageBox::Yes,QMessageBox::No) )
    {

        QSettings settings("HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Office",QSettings::NativeFormat);
        QString szDefault, szPath;
        bool bSuccess;
        szPath = settings.value("12.0/Excel/InstallRoot/Path").toString();
        if (szPath.isEmpty())
            szPath = settings.value("11.0/Excel/InstallRoot/Path").toString();
        if (szPath.isEmpty())
            szPath = settings.value("10.0/Excel/InstallRoot/Path").toString();
        if (szPath.isEmpty())
            szPath = settings.value("9.0/Excel/InstallRoot/Path").toString();
        if (szPath.isEmpty())
            szPath = settings.value("14.0/Excel/InstallRoot/Path").toString();

        if (szPath.isEmpty())
        {
            QMessageBox::information(0, "提示", "系统没有安装Office, 不能查看故障报告,请您先安装Microsoft Office.");
            return;
        }

        QProcess * proce = new QProcess;
        QString szExcelexe = szPath + "excel.exe";
        QString szopen = "/safe";
        QString szDoc = fileName;
        QStringList list;
        list<<szDoc;
        if( proce )
        {
            proce->start(szExcelexe,list);
             proce->waitForStarted(5000);        //需要等待完成启动
        }<pre name="code" class="cpp">               delete proce;

```
