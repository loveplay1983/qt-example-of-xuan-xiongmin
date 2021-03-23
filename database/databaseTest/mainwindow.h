#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QTextCodec>
#include <QKeyEvent>       // Receive input label
#include <QDateTime>       // get current date and time
#include "searchform.h"    // search for scanned label
#include <QTableWidget>
#include <QStringList>
#include <QTimer>          // set timer for current label
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPalette>        // bg color or bg image

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void bg();
    void init();
    void keyPressEvent(QKeyEvent *);
    void displayCurrentInput(/*int*/);   // display the current input labels, will last 30 seconds long
    void updateCurrentInput();           // control how long the current label shows
    void keepTrackInput();               // set up timer for tracking the input entry


public slots:
    void clearCurrentInputList();  // temp table for displaying the current input label
    void trackInput();             // track the cursor for input entry
    void showScanEntry();          // the entire component for label scan
    void searchLabel();            // search form for label record
    void quitApp();
    void aboutApp();
    void cleanTempInput();
    void deleteLine();                   // delete the currrent line of the tempInput tableWidget


private:
    Ui::MainWindow *ui;

//    int idIndex;
    QTimer *timerTrackTempTable;
    QTimer *timerTrackInput;
    QString label;
    QString labelOperator;
    QString inputTime;
    QDateTime currentDateTime;
    QSqlDatabase labelDb;
    QString labelDel;

//    int rowCount;        // QTableWidget index which displays the current input label
//    QTableWidgetItem *labelItem;
//    QTableWidgetItem *operatorItem;
//    QTableWidgetItem *inputTimeItem;

    SearchForm *search;  // search form class

};
#endif // MAINWINDOW_H
