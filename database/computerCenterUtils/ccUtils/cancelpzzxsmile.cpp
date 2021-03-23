#include "cancelpzzxsmile.h"
#include "ui_cancelpzzxsmile.h"

CancelPzzxSmile::CancelPzzxSmile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CancelPzzxSmile)
{
    ui->setupUi(this);

    this->init();
}

CancelPzzxSmile::~CancelPzzxSmile()
{
    delete ui;
}


void CancelPzzxSmile::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    this->openDb();

    // execute the cancelation for pzzx Big Smile
    connect(ui->cancelSmileYes, SIGNAL(clicked()), this, SLOT(cancelIt()));
    connect(ui->cancelSmileNo, SIGNAL(clicked()), this, SLOT(exitDlg()));
}


// init methodsd
void CancelPzzxSmile::openDb()
{
    db = QSqlDatabase::database("eahis");
    db.open();
}

void CancelPzzxSmile::cancelIt()
{
    QString wardNum = "";
    if(ui->cancelSmileWardCombo->currentText() == "五楼全科") { wardNum = "359"; }
    else if(ui->cancelSmileWardCombo->currentText() == "六楼风湿老年") { wardNum = "355"; }
    else if(ui->cancelSmileWardCombo->currentText() == "七楼神三") { wardNum = "336"; }
    else { wardNum = "340"; }

    QSqlQuery query(db);
    query.prepare(" UPDATE dbo.asy SET pzzx_tzbz='' WHERE bmh = :deptNum AND zyh = :patientId; ");
    query.bindValue(":deptNum", wardNum);
    query.bindValue(":patientId", ui->cancelSmileNumInput->text());

    if(!query.exec())
    {
        QMessageBox::information(this, "提示", "修改条目出错");
    }
    else
    {
        QMessageBox::information(this, "提示", "笑脸已取消");
    }
    ui->cancelSmileNumInput->clear();
}

void CancelPzzxSmile::exitDlg()
{
    this->close();
}














