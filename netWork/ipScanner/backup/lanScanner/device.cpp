#include "device.h"

Device::Device(QObject *parent) : QObject(parent) {
}

QString Device::ip() {
    return _ip;
}

QString Device::sn() {
    return _sn;
}

QString Device::model() {
    return _model;
}

QString Device::version() {
    return _version;
}


QString Device::hostName() {
    return _hostName;
}

void Device::setIp(QString ip) {
    _ip = ip;
}

void Device::setSn(QString sn) {
    _sn = sn;
}

void Device::setModel(QString model) {
    _model = model;
}

void Device::setVersion(QString version) {
    _version = version;
}

void Device::setName(QString hostName) {
    _hostName = hostName;
}
