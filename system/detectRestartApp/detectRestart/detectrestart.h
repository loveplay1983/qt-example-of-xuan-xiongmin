#ifndef DETECTRESTART_H
#define DETECTRESTART_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QTimer>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class DetectRestart; }
QT_END_NAMESPACE

class DetectRestart : public QWidget
{
    Q_OBJECT

public:
    DetectRestart(QWidget *parent = nullptr);
    ~DetectRestart();

    void init();
    void createActions();
    void createTrayIcon();
    void createconnection();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::DetectRestart *ui;

    QSystemTrayIcon *trayIcon;  // systemtray

    // qactions and qmenu
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QMenu *iconMenu;

    // message pop up when window closeEvent is triggered
    void showMsg();

    // detect and restart the specified program
    QProcess *processControl;
    QTimer *processTimer;

    // check the process liveness periodically
    void timer();


private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void detector();
};
#endif // DETECTRESTART_H
