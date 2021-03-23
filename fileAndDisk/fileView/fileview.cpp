#include "fileview.h"
#include "ui_fileview.h"
#include <QStringList>
#include <QIcon>

fileView::fileView(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
    , ui(new Ui::fileView)
{
    ui->setupUi(this);

    setWindowTitle(tr("File View"));
    fileLineEdit = new QLineEdit;
    fileLineEdit->setPlaceholderText(tr("Please input the directory path."));
    fileListWidget = new QListWidget; // call default constructor
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);
    connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
    connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotDirShow(QListWidgetItem*)));


    // the root directory
    QString root = "/";
    QDir rootDir(root);

    // get all the content of the current root dir
    QStringList string;
    string << "*";
    QFileInfoList list = rootDir.entryInfoList(string);

    // show the current dir file info
    showFileInfoList(list);
}


// slowshow slot
void fileView::slotShow(QDir dir)
{
    QStringList string;
    string << "*";
    QFileInfoList list = dir.entryInfoList(string, QDir::AllEntries, QDir::DirsFirst);
    showFileInfoList(list);
}

void fileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();
    for(int i = 0;
        //        i < static_cast<unsigned int>(list.count());
        i < list.count(); i++)
        // clear filelistwidget and loop through each position
    {
        QFileInfo tempFileInfo = list.at(i);
        // for each QFileInfoList itme check whether it is a dir or file
        if(tempFileInfo.isDir())
        {
            QString fileName = tempFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            fileListWidget->addItem(tmp);
        }
        else if(tempFileInfo.isFile())
        {
            QString fileName = tempFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            fileListWidget->addItem(tmp);
        }
    }
}


void fileView::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();
    QDir dir;
    dir.setPath(fileLineEdit->text()); // set QDir object to current path
    dir.cd(str);   // set QDir object to the sub-path
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);
}


fileView::~fileView()
{
    delete ui;
}
