#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readWriteBinary();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readWriteBinary()
{
    QFile file("binary.dat");
    file.open(QFile::WriteOnly|
              QFile::Truncate);
    QDataStream out(&file);  // write to file
    out << QString(tr("Michaelxuan"));
    out << QDate::fromString("2020/02/02", "yyyy/MM/dd");
    out << (qint32)2020;
    file.close();

    // read data from file
    file.setFileName("binary.dat");
    if(!file.open(QFile::ReadOnly))
    {
        qDebug() << "Error while reading from the file";
        return;
    }
    QDataStream in(&file);  // read from file
    QString name;
    QDate birthday;
    qint32 age;
    in >> name >> birthday >> age;
    qDebug() << name << birthday << age;
    file.close();



}

