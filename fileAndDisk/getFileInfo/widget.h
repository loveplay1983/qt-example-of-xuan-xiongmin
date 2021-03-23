#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, Qt::WindowFlags f=0);
    ~Widget();

public slots:
    void slotFile();
    void slotGet();

private:
    QLabel *fileNameLabel;
    QLineEdit *fileNameLineEdit;
    QPushButton *fileBtn;
    QLabel *sizeLabel;
    QLineEdit *sizeLineEdit;
    QLabel *createTimeLabel;
    QLineEdit *createTimeLineEdit;
    QLabel *lastModifiedLabel;
    QLineEdit *lastModifiedLineEdit;
    QLabel *lastReadLabel;
    QLineEdit *lastReadLineEdit;
    QLabel *propertyLabel;
    QCheckBox *isDirCheckBox;
    QCheckBox *isFileCheckBox;
    QCheckBox *isSymLinkCheckBox;
    QCheckBox *isHiddenCheckBox;
    QCheckBox *isReadableCheckBox;
    QCheckBox *isWritableCheckBox;
    QCheckBox *isExecutableCheckBox;
    QPushButton *getBtn;
};
#endif // WIDGET_H
