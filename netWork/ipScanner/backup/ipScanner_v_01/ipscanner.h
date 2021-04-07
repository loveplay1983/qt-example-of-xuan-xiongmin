#ifndef IPSCANNER_H
#define IPSCANNER_H

#include <QWidget>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include <QString>
#include <QMessageBox>

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

public slots:

    void onIpActivated(const QString &ipAddr);
    void saveOutput();

private:
    Ui::IpScanner *ui;
    // Execute the nbtscan program and pass the output to then save to
    QProcess *runNbtscan;

};
#endif // IPSCANNER_H
