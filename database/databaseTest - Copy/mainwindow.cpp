#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
    this->updateCurrentInput();
    this->keepTrackInput();

    // show scan entry
    connect(ui->receiveSample, SIGNAL(triggered()), this, SLOT(showScanEntry()));

    // search label
    connect(ui->searchLabel, SIGNAL(triggered()), this, SLOT(searchLabel()));

    // quit app
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(quitApp()));

    // help menu
    connect(ui->help, SIGNAL(triggered()), this, SLOT(aboutApp()));

    // clean temp input
    connect(ui->cleanTempInput, SIGNAL(clicked()), this, SLOT(cleanTempInput()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bg()
{
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/img/bg/bg/lab.png")));
    this->setPalette(palette);
}

void MainWindow::init()
{    
    // bg color
//    this->bg();

    // Display Chinese symbol
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    // hide scan entry
    ui->scanEntry->setHidden(true);

    this->setWindowTitle(tr("化验标签扫描记录"));
    this->setWindowState(Qt::WindowMaximized);

    // configure input entry size and color
    ui->scanLabel->setStyleSheet("color:red");
    ui->inputEntry->setMaximumHeight(55);
    ui->labelWarn->setStyleSheet("color:blue");

    // adding database
    labelDb = QSqlDatabase::addDatabase("QSQLITE");
    labelDb.setDatabaseName("labelRec.db3");

    //    rowCount = 0;          // init row count for QTableWidget

}

void MainWindow::showScanEntry()
{
    this->statusBar()->showMessage(tr("样本扫描入口"));
    // Display scanEntry
    ui->scanEntry->setHidden(false);
}

void MainWindow::keyPressEvent(QKeyEvent *keyValue)
{
    if(!(keyValue->key() == 16777220))  // if not enter key
    {
        ui->inputEntry->text() += keyValue->text();
    }
    else
    {
        // store label data to sqlite3 db
        //        idIndex = 0;
        label = ui->inputEntry->text();

        //        QMessageBox::information(this, "label test", label);
        labelOperator = "江东送血";   // operator
        currentDateTime = QDateTime::currentDateTime();
        inputTime = currentDateTime.toString("yyyy-MM-dd HH:mm::ss");

        if(!labelDb.open())
        {
            QMessageBox::information(this, "提示", "数据库连接失败!");
        }
        else
        {
            // sql query insert data
            QSqlQuery query;
            query.prepare("INSERT INTO lablabel (label, operator, time)"
                          "VALUES(:label, :operator, :time)");
            //            query.bindValue(":id", idIndex+1);
            query.bindValue(":label", label);
            query.bindValue(":operator", labelOperator);
            query.bindValue(":time", inputTime);

            if (!query.exec())
            {
//                QMessageBox::information(this, "提示", "增加条目出错\n" + query.lastError().text());
//                QMessageBox::information(this, "提示", "增加条目出错\n不允许插入重复值!!!");
                ui->inputEntry->clear();
            }
            else
            {
                this->displayCurrentInput(/*rowCount*/);
                ui->inputEntry->clear();
//                this->updateCurrentInput();
//                rowCount++;
            }
        }
    }
}

void MainWindow::displayCurrentInput(/*int rowCount*/)
{
    // configure heade construct
    ui->currentInputTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->currentInputTable->setColumnCount(3);
    ui->currentInputTable->horizontalHeader()->setDefaultSectionSize(150);
    ui->currentInputTable->horizontalHeader()->setSectionsClickable(false);

    // set up header content
    QStringList header;  // table header stored in QStringList object
    header << tr("标签号码") << tr("操作人员") << tr("记录时间");
    ui->currentInputTable->setHorizontalHeaderLabels(header);

    // set up header font
    QFont font = ui->currentInputTable->horizontalHeader()->font();
    font.setBold(true);
    ui->currentInputTable->horizontalHeader()->setFont(font);
    ui->currentInputTable->horizontalHeader()->setStretchLastSection(true);

//    // QTableWidgetItems
//    labelItem = new QTableWidgetItem();
//    operatorItem = new QTableWidgetItem();
//    inputTimeItem = new QTableWidgetItem();

//    labelItem->setText("a");
//    operatorItem->setText("b");
//    inputTimeItem->setText("c");

    // insert label, operator and inputtime to QTableWidget
    int row = ui->currentInputTable->rowCount();
    ui->currentInputTable->insertRow(row);

    ui->currentInputTable->setItem(row, 0, new QTableWidgetItem(this->label));
    ui->currentInputTable->setItem(row, 1, new QTableWidgetItem(this->labelOperator));
    ui->currentInputTable->setItem(row, 2, new QTableWidgetItem(this->inputTime));
    /*********************************************/
    ui->currentInputTable->scrollToBottom();
    ui->currentInputTable->selectRow(row);
    /***************************************/
}

void MainWindow::updateCurrentInput()
{
    timerTrackTempTable = new QTimer;   // set up timer for current label display
    timerTrackTempTable->setInterval(180000);
    timerTrackTempTable->start();
    connect(this->timerTrackTempTable, SIGNAL(timeout()), this, SLOT(clearCurrentInputList()));
}

void MainWindow::clearCurrentInputList()
{
//    ui->currentInputTable->clearContents();
    ui->currentInputTable->setRowCount(0);
}

void MainWindow::cleanTempInput()
{
    ui->currentInputTable->setRowCount(0);
}

void MainWindow::keepTrackInput()
{
    timerTrackInput = new QTimer();    // set up timer for tracking the current input cursor
    timerTrackInput->setInterval(1000);
    timerTrackInput->start();
    connect(this->timerTrackInput, SIGNAL(timeout()), this, SLOT(trackInput()));
}

void MainWindow::trackInput()
{
    ui->inputEntry->setEnabled(true);
    ui->inputEntry->setFocus();
}

void MainWindow::searchLabel()
{
    //    ui->scanEntry->setHidden(true);
    //    this->statusBar()->showMessage(tr("检查已扫描样本条目"));
    //    QMessageBox::information(this, "test", "test message");

    // TO-DO call the searchfrom class for searching label data

    if(!labelDb.open())
    {
        QMessageBox::information(this, "提示", "数据库连接失败!");
    }
    else
    {
        search = new SearchForm();
        //        search->setParent(this);
        search->show();
    }
}

void MainWindow::quitApp()
{
    QApplication::exit();
}

void MainWindow::aboutApp()
{
    //    ui->scanEntry->setHidden(true);
    this->statusBar()->showMessage(tr("帮助信息"));
    QMessageBox::information(this, "关于此程序", "1、选择样本接收；\n2、点击扫描入口；\n3、扫描标签；\n4、点击查找可查看已扫描样本");
}


/***************************** Code test ****************************
 *
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
QMessageBox::information(this, "database info", "sqlite3 driver connected");
db.setDatabaseName("test.db3");

if(!db.open())
{
    QMessageBox::information(this, "db output", "Open database failed!");
}
else
{
    QMessageBox::information(this, "db output", "Database opened!");
    // Create table
    QSqlQuery query;
    query.prepare("CREATE TABLE lablabel"
                  "(id INT PRIMARY KEY NOT NULL AUTOINCREMENT,"
                  "label UNSIGNED BIG INT NOT NULL,"
                  "operator VARCHAR(10),"
                  "time TEXT)");
    if (!query.exec())
    {
        QMessageBox::information(this, "table output", "Create table failed!");
    }
    else
    {
        QMessageBox::information(this, "table output", "Table has been created!");
    }
}
 *******************************************************************************
*/

