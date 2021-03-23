#ifndef IPSCANNER_H
#define IPSCANNER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class IpScanner; }
QT_END_NAMESPACE

class IpScanner : public QWidget
{
    Q_OBJECT

public:
    IpScanner(QWidget *parent = nullptr);
    ~IpScanner();

private:
    Ui::IpScanner *ui;
};
#endif // IPSCANNER_H
