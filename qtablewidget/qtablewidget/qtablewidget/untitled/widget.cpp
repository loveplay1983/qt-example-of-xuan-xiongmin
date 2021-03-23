#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->add, SIGNAL(clicked()), this, SLOT(setUpTable()));
    //    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clearContent()));

    this->autoclear();
}


void Widget::setUpTable()
{
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->verticalHeader()->setVisible(false);
    QFont font = ui->tableWidget->horizontalHeader()->font(); //先获取字体
    font.setBold(true); //字体设置为粗体
    ui->tableWidget->horizontalHeader()->setFont(font); //设置每一列的标题字体为粗体
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Age" << "Occupation");

    int row  = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->field1->text()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->field2->text()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ui->field3->text()));
}


void Widget::autoclear()
{
    timer = new QTimer;
    timer->setInterval(10000);
    connect(timer, SIGNAL(timeout()), this, SLOT(clearContent()));
    timer->start();
}


void Widget::clearContent()
{
    ui->tableWidget->setRowCount(0);
}

Widget::~Widget()
{
    delete ui;
}
