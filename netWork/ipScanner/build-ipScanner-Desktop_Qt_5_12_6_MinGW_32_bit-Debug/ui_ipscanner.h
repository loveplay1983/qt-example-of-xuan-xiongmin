/********************************************************************************
** Form generated from reading UI file 'ipscanner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPSCANNER_H
#define UI_IPSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IpScanner
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_6;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *IpScanner)
    {
        if (IpScanner->objectName().isEmpty())
            IpScanner->setObjectName(QString::fromUtf8("IpScanner"));
        IpScanner->resize(800, 632);
        verticalLayout_3 = new QVBoxLayout(IpScanner);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(IpScanner);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        comboBox = new QComboBox(IpScanner);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 10);
        gridLayout->setColumnStretch(3, 2);

        verticalLayout->addLayout(gridLayout);

        plainTextEdit = new QPlainTextEdit(IpScanner);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(IpScanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(IpScanner);

        QMetaObject::connectSlotsByName(IpScanner);
    } // setupUi

    void retranslateUi(QWidget *IpScanner)
    {
        IpScanner->setWindowTitle(QApplication::translate("IpScanner", "IP\346\211\253\346\217\217\345\267\245\345\205\267", nullptr));
        label->setText(QApplication::translate("IpScanner", "\351\200\211\346\213\251\347\275\221\347\273\234\350\214\203\345\233\264", nullptr));
        comboBox->setItemText(0, QApplication::translate("IpScanner", "192.9.0.0/16", nullptr));
        comboBox->setItemText(1, QApplication::translate("IpScanner", "192.9.6.0/24", nullptr));
        comboBox->setItemText(2, QApplication::translate("IpScanner", "192.9.7.0/24", nullptr));
        comboBox->setItemText(3, QApplication::translate("IpScanner", "192.9.10.0/24", nullptr));
        comboBox->setItemText(4, QApplication::translate("IpScanner", "192.10.0.0/16", nullptr));
        comboBox->setItemText(5, QApplication::translate("IpScanner", "192.168.1.0/24", nullptr));
        comboBox->setItemText(6, QApplication::translate("IpScanner", "192.168.102.0/24", nullptr));

        pushButton->setText(QApplication::translate("IpScanner", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IpScanner: public Ui_IpScanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPSCANNER_H
