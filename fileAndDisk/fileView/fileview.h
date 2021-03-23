#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QDialog>
#include <QLineEdit>   // where user can input the target path
#include <QListWidget> // where the result will be showed
#include <QVBoxLayout> // layout
#include <QDir>
#include <QListWidgetItem>
/*
typedef QFileInfoList
Synonym for QList<QFileInfo>.
*/
#include <QFileInfoList>

QT_BEGIN_NAMESPACE
namespace Ui { class fileView; }
QT_END_NAMESPACE

class fileView : public QDialog
{
    Q_OBJECT

public:
    fileView(QWidget *parent = nullptr, Qt::WindowFlags f=0);
    ~fileView();

    void showFileInfoList(QFileInfoList list);

public slots:
    void slotShow(QDir dir);
    void slotDirShow(QListWidgetItem * item);

private:
    Ui::fileView *ui;
    QLineEdit *fileLineEdit;
    QListWidget *fileListWidget;
    QVBoxLayout *mainLayout;
};
#endif // FILEVIEW_H
