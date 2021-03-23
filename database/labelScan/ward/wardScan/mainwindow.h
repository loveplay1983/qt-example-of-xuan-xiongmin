#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginform.h"
#include "searchform.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    void openDb();
    void keyPressEvent(QKeyEvent *);   // keypress event for input data when scanning the label: if "Enter" store the data, else keep going on
    void closeEvent(QCloseEvent *);    // close event for mainwindow which will deal with the loginFlag
    void displayCurrentInput();        // display the current input label
    void updateCurrentInput();         // update current input label table
    void keepTrackInput();             // keep tracking the input cursor


public slots:
    void labelSearchForm();            // instantiate search form for stored label data
    void clearCurrentList();           // refresh the current input table
    void trackInput();                 // focus the input field
    void tempInputMenu();               // open context menu for temp input table
    void delLineTempTable();


private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QTimer *timerTrackTempTable;       // timer for tracking and updating the current input label
    QTimer *timerTrackInput;           // timer for tracking the input cursor making the cursor is always in the field of input data
    QString label;                     // num of label
    QString wardOperator;              // scanner of ward
    QString inputTime;                 // the label record time
    QDateTime currentDateTime;         // get the current data time
    QShortcut *openSearchForm;         // shortcut key of search form for scanned labels
    int tempTableRow;                  // index for the temp table
    SearchForm *search;
};


#endif // MAINWINDOW_H
