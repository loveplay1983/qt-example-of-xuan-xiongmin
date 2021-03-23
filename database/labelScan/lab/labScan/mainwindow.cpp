#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/***************************************** initialization ************************************************/
void MainWindow::init()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());  // codec for chinese

    this->openDb();

    this->setWindowTitle(tr("化验室标签扫描"));                       // window title
    this->setWindowState(Qt::WindowMaximized);                    // the window is maximized when program starts

    ui->label->setStyleSheet("color:red");                        // input entry ui style
    ui->inputEntry->setMaximumHeight(55);

    // refresh the current input table and keep the cursor always in the field of input label
    this->updateCurrentInput();
    this->keepTrackInput();

    // context menu of the current input table
    ui->tempInput->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tempInput, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tempInputMenu()));

    /****************************************************************************************************************/
    openSearchForm = new QShortcut(QKeySequence(tr("Ctrl+O")), this);   // shortcut object  <-> open search form
    /****************************************************************************************************************/

    // shortcut for opening the searchForm
    connect(openSearchForm, SIGNAL(activated()), this, SLOT(labelSearchForm()));

}


/***************************************  Reconnect to the database ******************************************************/
void MainWindow::openDb()
{
    db = QSqlDatabase::database("wardLabelScanDb");
    if(!db.open())
    {
        QMessageBox::information(this, tr("信息"), tr("数据库打开失败!!!"));
        return;
    }
}


/***************************************** label scan action by the keyPressEvent ************************************************/
void MainWindow::keyPressEvent(QKeyEvent *keyValue)
{
    // label scan response
    if(!(keyValue->key() == 16777220))
    {
        ui->inputEntry->text() += keyValue->text();
    }
    else
    {
        /* store data to wardScan*/
        label = ui->inputEntry->text();                    // label id
        currentDateTime = QDateTime::currentDateTime();    // the scanned time
        inputTime = currentDateTime.toString("yyyy-MM-dd HH:mm::ss");
        QString scanMark = "1";                            // the default flag for scanned label

        QSqlQuery userComment(db), insertLabelItem(db);

        /* Get label operator - the login table comment */
        userComment.prepare("SELECT userComment FROM login WHERE userName = :user AND passwd = :pass");
        userComment.bindValue(":user", uName);
        userComment.bindValue(":pass", uPass);
        userComment.exec();
        if(userComment.next())
        {
            wardOperator = userComment.value(0).toString();
        }

        /*  sql query for storing label data */
        insertLabelItem.prepare("INSERT INTO labScan(label, operator, eventTime, scanMark)"
                                "VALUES(:label, :operator, :time, :mark)");
        insertLabelItem.bindValue(":label", label);
        insertLabelItem.bindValue(":operator", wardOperator);
        insertLabelItem.bindValue(":time", inputTime);
        insertLabelItem.bindValue(":mark", scanMark);

        if(!insertLabelItem.exec())
        {
            ui->inputEntry->clear();
        }
        else
        {
            this->displayCurrentInput();
            ui->inputEntry->clear();
        }
    }
}


/********************************** The current input table ************************************************/
void MainWindow::displayCurrentInput()
{

    /* QTableWidget configuration */
    QStringList header;                                                    // set up header
    header << tr("标签号") << tr("操作员") << tr("记录时间") << tr("扫描对比");
    ui->tempInput->setHorizontalHeaderLabels(header);
    ui->tempInput->setSelectionBehavior(QAbstractItemView::SelectRows);    // QTableWidget display behaviors
    ui->tempInput->setColumnCount(header.length());
    ui->tempInput->horizontalHeader()->setDefaultSectionSize(150);
    ui->tempInput->horizontalHeader()->setSectionsClickable(false);

    QFont font = ui->tempInput->horizontalHeader()->font();                // header font
    font.setBold(true);
    ui->tempInput->horizontalHeader()->setFont(font);
    /*This property holds whether the last visible section in the header takes up all the available space*/
    ui->tempInput->horizontalHeader()->setStretchLastSection(true);

    /* Insert data to the QTableWidget */
    int wardMark;
    int labMark;

    QTableWidgetItem *currentScanMark = new QTableWidgetItem();
    currentScanMark->data(Qt::CheckStateRole);
    currentScanMark->setFlags(currentScanMark->flags() & (~Qt::ItemIsUserCheckable) & (~Qt::ItemIsEditable));

    QSqlQuery getWardMark(db);                                                 // customized scanMark
    getWardMark.prepare("SELECT scanMark FROM wardScan WHERE label = :currentLabel");
    getWardMark.bindValue(":currentLabel", this->label);
    getWardMark.exec();
    getWardMark.next();
    wardMark = getWardMark.value(0).toInt();

    QSqlQuery getLabMark(db);
    getLabMark.prepare("SELECT scanMark FROM labScan WHERE label = :currLabel");
    getLabMark.bindValue(":currLabel", this->label);
    getLabMark.exec();
    getLabMark.next();
    labMark = getLabMark.value(0).toInt();

    /* check whether labeMark and wardMark are the same */
    if(wardMark == labMark)
    {
        currentScanMark->setCheckState(Qt::Checked);
    }
    else
    {
        currentScanMark->setCheckState(Qt::Unchecked);
    }

    int tempTableIndex = ui->tempInput->rowCount();                                   // current row cout, a.k.a the next index
    ui->tempInput->insertRow(tempTableIndex);
    ui->tempInput->setItem(tempTableIndex, 0, new QTableWidgetItem(this->label));            // label number
    ui->tempInput->setItem(tempTableIndex, 1, new QTableWidgetItem(this->wardOperator));     // operator
    ui->tempInput->setItem(tempTableIndex, 2, new QTableWidgetItem(this->inputTime));        // input time
    ui->tempInput->setItem(tempTableIndex, 3, currentScanMark);                              // customized scanMark

    ui->tempInput->scrollToBottom();               // Make the latest data always the current line
    ui->tempInput->selectRow(tempTableIndex);      // Select the current line of data
}


/****************************  refresh and clear the temp input table   ***********************************/
void MainWindow::updateCurrentInput()
{
    timerTrackTempTable = new QTimer;
    timerTrackTempTable->setInterval(180000);      // refresh the current input table for each 180000 milliseconds
    timerTrackTempTable->start();
    connect(this->timerTrackTempTable, SIGNAL(timeout()), this, SLOT(clearCurrentList()));   // when timer timeout, start the slot to clean the data
}


void MainWindow::clearCurrentList()
{
    ui->tempInput->setRowCount(0);                 // set the rowcout to ZERO <=> the list of current input label are all cleaned
}


/********************************************* track input ************************************************/
void MainWindow::keepTrackInput()
{
    timerTrackInput = new QTimer;
    timerTrackInput->setInterval(1000);
    timerTrackInput->start();
    connect(this->timerTrackInput, SIGNAL(timeout()), this, SLOT(trackInput()));
}
void MainWindow::trackInput()
{
    ui->inputEntry->setEnabled(true);
    ui->inputEntry->setFocus();
}


/***************************************** temp input table context menu ************************************************/
void MainWindow::tempInputMenu()
{
    QMenu *tempMenu = new QMenu(ui->tempInput);
    QAction *refreshTempTable = new QAction("刷新", ui->tempInput);
    QAction *delItemTempTable = new QAction("删除", ui->tempInput);
    connect(refreshTempTable, SIGNAL(triggered()),this, SLOT(clearCurrentList()));    // clean up and refresh the temp table
    connect(delItemTempTable, SIGNAL(triggered()),this, SLOT(delLineTempTable()));
    tempMenu->addAction(refreshTempTable);
    tempMenu->addAction(delItemTempTable);
    tempMenu->move(cursor().pos());                      // move menu to the cursor position (cursor <-> QCursor)
    tempMenu->show();
    //    int posX = /*cursor().*/pos().x();
    //    int posY = /*cursor().*/pos().y();
    //    QModelIndex index = ui->tempInput->indexAt(QPoint(posX, posY));
    //    int tempTableRow = index.row();
    //    QMessageBox::information(this, tr("index"), QString::number(tempTableRow));
    //    return tempTableRow;
}

void MainWindow::delLineTempTable()
{
    int index = ui->tempInput->currentRow();

    if(index != -1)
    {
        QString labelDel = ui->tempInput->item(index, 0)->text();
        QSqlQuery queryDelLabel(db);
        queryDelLabel.prepare("DELETE FROM labScan WHERE label = :label");
        queryDelLabel.bindValue(":label", labelDel);
        if(!queryDelLabel.exec())
        {
            QMessageBox::information(this, tr("提示"), "删除条目出错" + queryDelLabel.lastError().text());
        }
        else
        {
            QMessageBox::information(this, tr("提示"), "所选条目 " + labelDel + "已删除");
        }
        ui->tempInput->removeRow(index);
        ui->inputEntry->clear();
    }
}


/********************************************* search form ************************************************/
void MainWindow::labelSearchForm()
{
    search = new SearchForm();
    search->show();
}

/*********************************************** form close event ***********************************************/
void MainWindow::closeEvent(QCloseEvent *)
{
    QSqlQuery changeLoginFlag(db);
    changeLoginFlag.prepare("UPDATE login SET loginFlag = 0 WHERE userName = :user AND passwd = :pass");
    changeLoginFlag.bindValue(":user", uName);
    changeLoginFlag.bindValue(":pass", uPass);
    if(changeLoginFlag.exec())
    {
        QMessageBox::information(this, tr("Info"), tr("Login status changed"));
    }
    else
    {
        QMessageBox::information(this, tr("Info"), changeLoginFlag.lastError().text());
    }
}



















