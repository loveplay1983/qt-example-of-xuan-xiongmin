#ifndef IPSCANNER_H
#define IPSCANNER_H

#include <QWidget>
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include <QString>
#include <QHostInfo>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class IpScanner; }
QT_END_NAMESPACE

class IpScanner : public QWidget
{
    Q_OBJECT

public:
    IpScanner(QWidget *parent = nullptr);
    ~IpScanner();

    // Initialization
    void init();
    int static rowNum;

public slots:
    void lookupHostInfo(const QHostInfo &host);
    void saveOutput();
    void resetOutput();

private:
    Ui::IpScanner *ui;

    // tableItem to display ip and hostname
    QTableWidgetItem *ipItem;
    QTableWidgetItem *hostName;

private slots:
    void onNetAddrEntered();
};



#endif // IPSCANNER_H
