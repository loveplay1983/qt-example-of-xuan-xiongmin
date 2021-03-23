#include "cancelbed.h"
#include "ui_cancelbed.h"

CancelBed::CancelBed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CancelBed)
{
    ui->setupUi(this);

    this->init();
}

CancelBed::~CancelBed()
{
    delete ui;
}


void CancelBed::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    this->openDb();

    // execute the cancelation for bed placeholder
    connect(ui->cancelBedYes, SIGNAL(clicked()), this, SLOT(cancelIt()));
    connect(ui->cancelBedNo, SIGNAL(clicked()), this, SLOT(exitDlg()));


}

// init methods
void CancelBed::openDb()
{
    db = QSqlDatabase::database("eahis");
    db.open();
    //    if(!db.open())
//    {
//        QMessageBox::information(this, tr("提醒"), tr("数据库连接失败啦!!!"));
//    }
//    else
//    {
//        QMessageBox::information(this, "test", "database connection succeed.");
//    }
}
void CancelBed::cancelIt()
{
    QString wardNum = "";
    if(ui->cancelBedWardCombo->currentText() == "五楼全科") { wardNum = "359"; }
    else if(ui->cancelBedWardCombo->currentText() == "六楼风湿老年") { wardNum = "355"; }
    else if(ui->cancelBedWardCombo->currentText() == "七楼神三") { wardNum = "336"; }
    else { wardNum = "340"; }

    // test
//    QMessageBox::information(this, "test", wardNum);
//    QMessageBox::information(this, "test", ui->cancelBedNumInput->text());
    QSqlQuery query(db);
    query.prepare(" UPDATE dbo.zd_cw SET wnyy_rq = NULL WHERE cwh = :bedNum AND bmh = :deptNum; ");
    query.bindValue(":bedNum", ui->cancelBedNumInput->text());
    query.bindValue(":deptNum", wardNum);
//    query.exec();
    if(!query.exec())
    {
         QMessageBox::information(this, "提示", "修改条目出错");
    }
    else
    {
        QMessageBox::information(this, "提示", "床位占位已取消");
    }
    ui->cancelBedNumInput->clear();
}

void CancelBed::exitDlg()
{
    this->close();
}

