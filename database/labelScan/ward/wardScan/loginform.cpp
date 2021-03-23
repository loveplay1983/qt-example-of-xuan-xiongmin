#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>

using namespace std;

QString uName = "";
QString uPass = "";

Loginform::Loginform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loginform)
{
    ui->setupUi(this);

    this->init();
    this->sigSlots();
}

Loginform::~Loginform()
{
    delete ui;
}

void Loginform::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    ui->editUser->setPlaceholderText(tr("请输入用户名"));
    ui->editPasswd->setPlaceholderText(tr("请输入密码"));
    ui->editPasswd->setEchoMode(QLineEdit::Password);   // Hide the passwd when editing

    this->conDb();
}

void Loginform::sigSlots()
{
    connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(login()));
    connect(ui->btnQuit, SIGNAL(clicked()), this, SLOT(quit()));
}

void Loginform::conDb()
{
    dbConnection = QSqlDatabase::addDatabase("QMYSQL", "wardLabelScanDb");
    dbConnection.setHostName("localhost");
    dbConnection.setDatabaseName("labelScan");
    dbConnection.setUserName("root");
    dbConnection.setPassword("pgjdcwn040506");
}

void Loginform::login()
{
    if(!dbConnection.open())
    {
        QMessageBox::information(this, tr("message"), tr("Open db failed!!!"));
        return;
    }

    QString userName = ui->editUser->text();
    QString userPass = ui->editPasswd->text();

    /* pass current login username and password to global variable uName and uPass */
    uName = userName;
    uPass = userPass;

    loginModel = new QSqlTableModel(this, dbConnection);
    loginModel->setTable("login");
    loginModel->setFilter(QString("userName = '%1' AND passwd = '%2' AND loginFlag = '0'").arg(userName).arg(userPass));
    loginModel->select();

    if(!(loginModel->rowCount() == 1))
    {
        QMessageBox::information(this, tr("message"), tr("Check your username and passwd status!!!"));
    }
    else
    {
        accept();

        QString userComment;
        QSqlQuery loginInfo(dbConnection);
        loginInfo.prepare("SELECT userComment FROM login WHERE userName = :user AND passwd = :pass");
        loginInfo.bindValue(":user", userName);
        loginInfo.bindValue(":pass", userPass);
        loginInfo.exec();
        if(loginInfo.next())
        {
            userComment = loginInfo.value(0).toString();
            QMessageBox::information(this, tr("Info"), userComment + "login succeed!!!");
        }

        QSqlQuery loginFlag(dbConnection);
        loginFlag.prepare("UPDATE login SET loginFlag = 1 WHERE userName = :user AND passwd = :pass");
        loginFlag.bindValue(":user", userName);
        loginFlag.bindValue(":pass", userPass);
        if(loginFlag.exec())
        {
            QMessageBox::information(this, tr("Info"), tr("登录状态已改变"));
        }
    }
}

void Loginform::quit()
{
    QApplication::exit();
}
