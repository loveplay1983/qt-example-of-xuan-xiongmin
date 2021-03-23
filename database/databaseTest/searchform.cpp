#include "searchform.h"
#include "ui_searchform.h"
#include "mainwindow.h"

// test
#include <QMessageBox>
#include <QDebug>
#include <iostream>

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    this->init();

    // search button signal and slot
    connect(ui->advancedSearch, SIGNAL(clicked()), this, SLOT(showDateRnage()));
    connect(ui->simpleSearch, SIGNAL(clicked()), this, SLOT(hideDateRange()));
    connect(ui->search, SIGNAL(clicked()), this, SLOT(query()));

    // width of window
    width = this->size().width() - 100;
}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::hideDateRange()
{
    ui->labelDateRange->setHidden(true);
    ui->labelDateTo->setHidden(true);
    ui->from->setHidden(true);
    ui->to->setHidden(true);
}

void SearchForm::showDateRnage()
{
    ui->labelDateRange->setHidden(false);
    ui->labelDateTo->setHidden(false);
    ui->from->setHidden(false);
    ui->to->setHidden(false);
}

void SearchForm::init()
{
    // Display Chinese symbol
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    this->setWindowTitle(tr("已扫描样本查询"));
    ui->labelDateRange->setHidden(true);
    ui->labelDateTo->setHidden(true);
    ui->from->setHidden(true);
    ui->to->setHidden(true);

    labelRec = new QTableView;
    model = new QSqlQueryModel(this);

    // Configure QDateTimeEdit
    ui->from->setCalendarPopup(true);   // Calendar
    ui->to->setCalendarPopup(true);

    ui->from->setDateTime(QDateTime::currentDateTime());  // datetime range
    ui->from->setMinimumDate(QDate::currentDate().addDays(-365));
    ui->from->setMaximumDate(QDate::currentDate().addDays(+365));
    ui->to->setDateTime((QDateTime::currentDateTime()));
    ui->to->setMinimumDate(QDate::currentDate().addDays(-365));
    ui->to->setMaximumDate(QDate::currentDate().addDays(+365));

    ui->from->setDisplayFormat("yyyy-MM-dd HH::mm::ss");  // display format
    ui->to->setDisplayFormat("yyyy-MM-dd HH::mm::ss");
}


void SearchForm::query()
{
    QString labelNum = ui->labelSearchNum->text();
    QString fromYear = ui->from->sectionText(QDateTimeEdit::YearSection);
    QString fromMonth = ui->from->sectionText(QDateTimeEdit::MonthSection);
    QString fromDay = ui->from->sectionText(QDateTimeEdit::DaySection);

    QString toYear = ui->to->sectionText(QDateTimeEdit::YearSection);
    QString toMonth = ui->to->sectionText(QDateTimeEdit::MonthSection);
    int extraDay = ui->to->sectionText(QDateTimeEdit::DaySection).toInt() + 1;
    QString toDay = QString::number(extraDay);

    QString fromStr = fromYear + "-" + fromMonth + "-" + fromDay;
    QString toStr = toYear + "-" + toMonth + "-" + toDay;

    QSqlQuery checkLabelRecLabelNum;
    QSqlQuery checkLabelRecDateRangeAndLabelNum;

    if(ui->labelDateRange->isHidden())
    {
        checkLabelRecLabelNum.prepare("SELECT * FROM lablabel WHERE label = :label");
        checkLabelRecLabelNum.bindValue(":label", labelNum);
        checkLabelRecLabelNum.exec();

        model->setQuery(checkLabelRecLabelNum);

        model->setHeaderData(0, Qt::Horizontal, tr("序号"));
        model->setHeaderData(1, Qt::Horizontal, tr("标签号码"));
        model->setHeaderData(2, Qt::Horizontal, tr("操作人员"));
        model->setHeaderData(3, Qt::Horizontal, tr("记录时间"));

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();  // configure the columns to auto-adapt the data

        // configure the width of QTableView object
        ui->tableView->setColumnWidth(0, width/4);
        ui->tableView->setColumnWidth(1, width/4);
        ui->tableView->setColumnWidth(2, width/4);
//        ui->tableView->setColumnWidth(3, width/4);
    }
    else
    {
        checkLabelRecDateRangeAndLabelNum.prepare("SELECT * FROM lablabel WHERE label = :label AND time >= :from AND time <= :to");
        checkLabelRecDateRangeAndLabelNum.bindValue(":label", labelNum);
        checkLabelRecDateRangeAndLabelNum.bindValue(":from", fromStr);
        checkLabelRecDateRangeAndLabelNum.bindValue(":to", toStr);
        checkLabelRecDateRangeAndLabelNum.exec();

        model->setQuery(checkLabelRecDateRangeAndLabelNum);

        model->setHeaderData(0, Qt::Horizontal, tr("序号"));
        model->setHeaderData(1, Qt::Horizontal, tr("标签号码"));
        model->setHeaderData(2, Qt::Horizontal, tr("操作人员"));
        model->setHeaderData(3, Qt::Horizontal, tr("记录时间"));

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();  // configure the columns to auto-adapt the data

        // configure the width of QTableView object
        ui->tableView->setColumnWidth(0, width/4);
        ui->tableView->setColumnWidth(1, width/4);
        ui->tableView->setColumnWidth(2, width/4);
        ui->tableView->setColumnWidth(3, width/4);
    }
}
