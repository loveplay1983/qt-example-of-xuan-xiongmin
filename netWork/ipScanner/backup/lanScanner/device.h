#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = nullptr);
    void setIp(QString ip);
    void setSn(QString sn);
    void setModel(QString model);
    void setVersion(QString version);
    void setName(QString hostName);

    QString ip();
    QString sn();
    QString model();
    QString version();
    QString hostName();

signals:

public slots:

private:
    QString _ip;
    QString _sn;
    QString _model;
    QString _version;
    QString _hostName;

};

#endif // DEVICE_H
