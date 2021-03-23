#ifndef GETNETWORKINFO_H
#define GETNETWORKINFO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>


QT_BEGIN_NAMESPACE
namespace Ui { class getNetworkInfo; }
QT_END_NAMESPACE

class getNetworkInfo : public QWidget
{
    Q_OBJECT

public:
    getNetworkInfo(QWidget *parent = nullptr);
    ~getNetworkInfo();

    void getHostInfo();

public slots:
    void slotDetails();

private:
    Ui::getNetworkInfo *ui;

    QLabel *labelHost;
    QLineEdit *lineEditHostName;
    QLabel *labelIp;
    QLineEdit *lineEditAddr;
    QPushButton *btnDetail;
    QGridLayout *theLayout;
};
#endif // GETNETWORKINFO_H
