#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QMovie>
#include <QHostInfo>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QHeaderView>
#include <QSettings>

#include "shellprocess.h"
#include "device.h"

//#define THREAD_SIZE 15
#define THREAD_SIZE 1


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ShellProcess *shellProcess;

public slots:
    void onCommandSuccess(QString ip);
    void onCommandFailed(QString ip);
    //update the ip scan progress
    void update_scanProgress(QString ip);


protected:
    //

protected slots:
//    void lookupHostName(const QHostInfo &host, int index);

private:
    Ui::MainWindow *ui;
    QProcess *myProcess;
    QMovie *loadingImage;


    QString get_localmachine_ip();
    QStringList generateRangeIP(QString ip1, QString ip2);
    QStringList scanHosts;
    QStringList to_scanHosts;
    QStringList onlineHosts;

    QString currentHost;
    QVector<Device*> _onlineDevices;

    int onlineCount;

    double currentScanNum;//progress of scanning
    double totalScanNum;// total nums of ip addr

private slots:

    void startScan(); // Execute when 'scan' button clicked.
    //    void resetList(); // Clear the scanned list
    void on_showOnlineDevicesButton_clicked();
    void on_testSSH_Button_clicked();
//    void sortColumn(int column);

    void exportExcel();

};

#endif // MAINWINDOW_H
