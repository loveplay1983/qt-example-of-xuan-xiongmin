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
