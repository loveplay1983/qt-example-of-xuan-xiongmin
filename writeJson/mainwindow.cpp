#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /******************* writeJson program code ********************/
    this->setWindowTitle(tr("Test for QInputDialog"));

    connect(ui->config, SIGNAL(triggered()),
            this, SLOT(testSlot()));
}

void MainWindow::testSlot()
{
    bool ok;
    QString textIp = QInputDialog::getText(this, tr("配置"),
                                           tr("输入服务器地址"), QLineEdit::Normal,
                                           tr("192.10.x.y"), &ok);
    if(ok && !textIp.isEmpty())
    {
        // write textIp to local json file
        QFile jsonFile(QDir::currentPath()+"/serverip.json");
        if(!jsonFile.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this, tr("注意"),
                                     tr("读写配置出错"));
        }
        else
        {
            // Insert a key-value pair using the QJsonObject object.
            QJsonObject jsonObj;
            jsonObj.insert("ip", textIp);

            // Set the json object using QJsonDocument
            QJsonDocument jsonDoc;
            jsonDoc.setObject(jsonObj);

            jsonFile.write(jsonDoc.toJson());
            jsonFile.close();
            QMessageBox::information(this, tr("注意"),
                                     tr("配置已保存"));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

