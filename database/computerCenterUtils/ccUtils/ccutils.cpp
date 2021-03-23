#include "ccutils.h"
#include "ui_ccutils.h"

CCUtils::CCUtils(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CCUtils)
{
    ui->setupUi(this);



    this->init();
    this->sqls();
}

CCUtils::~CCUtils()
{
    delete ui;
}



void CCUtils::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    // start menu
    connect(ui->start_exit, SIGNAL(triggered()), this, SLOT(exitApp()));
    connect(ui->start_about, SIGNAL(triggered()), this, SLOT(aboutApp()));

    // database configuration
    conHisString = this->dbConfig(tr("DRIVER={SQL Server};Server=EAHIS;Database=zjyy;Uid=ssa;Pwd=20130111"));

    // connect to the database
    // EAHIS
    this->conHisDatabase(tr("QODBC3"), conHisString, tr("eahis"));

}

void CCUtils::sqls()
{
    // computer center
    // TO-DO

    // clinic
    // TO-DO

    // ward
    connect(ui->ward_cancel_bed, SIGNAL(triggered()), this, SLOT(cancelBed()));
    connect(ui->ward_cancel_smile, SIGNAL(triggered()), this, SLOT(cancelSmile()));

    // charge
    // TO-DO

    // others
    // TO-DO


}


// init method
void CCUtils::exitApp()
{
    QApplication::exit();
}

void CCUtils::aboutApp()
{
    QMessageBox::information(this, tr("关于"), tr("就是玩玩的^_^"));
}

// db configuration references
QString CCUtils::dbConfig(QString dbConf)
{
    return dbConf;
}

void CCUtils::conHisDatabase(QString dbType, QString conString, QString conAlias)
{
    dbObject = QSqlDatabase::addDatabase(dbType, conAlias);
    dbObject.setDatabaseName(conString);
}

// uitls
void CCUtils::cancelBed()
{
    cancelBedNum = new CancelBed();
    cancelBedNum->show();
}

void CCUtils::cancelSmile()
{
    cancelPzzxSmile = new CancelPzzxSmile();
    cancelPzzxSmile->show();
}







