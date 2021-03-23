#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);

    this->init();
    connect(ui->labelSearch, SIGNAL(clicked()), this, SLOT(search()));
}

void SearchForm::openDb()
{
    db = QSqlDatabase::database("wardLabelScanDb");
    if(!db.open())
    {
        QMessageBox::information(this, tr("message"), tr("Open db failed!!!"));
        return;
    }
}


void SearchForm::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    this->setWindowTitle("标签查询");
    ui->labelSearchFormInput->setStyleSheet("color:red");                        // input entry ui style
//    ui->labelSearchFormInput->setMaximumHeight(30);
    this->openDb();
    searchModel = new QSqlQueryModel(this);
}

void SearchForm::search()
{
    QSqlQuery searchLabel(db);
    QString labelNum = ui->lineEditSearchFormInput->text();

    QMessageBox::information(this, "labelNum", labelNum);

    searchLabel.prepare("SELECT id, label, operator, eventTime, "
                        "(CASE WHEN scanMark='1' THEN '已扫描' WHEN scanMark='NULL' THEN '未扫描' END)"
                        "FROM wardScan WHERE label = :labelNumber");
//    searchLabel.prepare("SELECT id, label, operator, eventTime, scanMark FROM wardScan WHERE label = :labelNumber");
    searchLabel.bindValue(":labelNumber", labelNum);
    searchLabel.exec();

//    searchLabel.exec("SELECT * FROM wardScan");
    searchModel->setQuery(searchLabel);

    searchModel->setHeaderData(0, Qt::Horizontal, tr("序号"));
    searchModel->setHeaderData(1, Qt::Horizontal, tr("标签号"));
    searchModel->setHeaderData(2, Qt::Horizontal, tr("操作人员"));
    searchModel->setHeaderData(3, Qt::Horizontal, tr("记录时间"));
    searchModel->setHeaderData(4, Qt::Horizontal, tr("扫描标记"));

    ui->tableViewSearchForm->setModel(searchModel);
    ui->tableViewSearchForm->resizeColumnsToContents();
}


SearchForm::~SearchForm()
{
    delete ui;
}
