/********************************************************************************
** Form generated from reading UI file 'cancelbed.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCELBED_H
#define UI_CANCELBED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cancelBed
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cancelBedWardCombo;
    QLineEdit *cancelBedNumInput;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelBedYes;
    QPushButton *cancelBedNo;

    void setupUi(QWidget *cancelBed)
    {
        if (cancelBed->objectName().isEmpty())
            cancelBed->setObjectName(QString::fromUtf8("cancelBed"));
        cancelBed->resize(400, 300);
        horizontalLayout = new QHBoxLayout(cancelBed);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(cancelBed);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 70, 274, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cancelBedWardCombo = new QComboBox(widget);
        cancelBedWardCombo->addItem(QString());
        cancelBedWardCombo->addItem(QString());
        cancelBedWardCombo->addItem(QString());
        cancelBedWardCombo->addItem(QString());
        cancelBedWardCombo->setObjectName(QString::fromUtf8("cancelBedWardCombo"));

        verticalLayout->addWidget(cancelBedWardCombo);

        cancelBedNumInput = new QLineEdit(widget);
        cancelBedNumInput->setObjectName(QString::fromUtf8("cancelBedNumInput"));

        verticalLayout->addWidget(cancelBedNumInput);


        horizontalLayout_2->addLayout(verticalLayout);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(90, 150, 195, 30));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cancelBedYes = new QPushButton(widget1);
        cancelBedYes->setObjectName(QString::fromUtf8("cancelBedYes"));

        horizontalLayout_3->addWidget(cancelBedYes);

        cancelBedNo = new QPushButton(widget1);
        cancelBedNo->setObjectName(QString::fromUtf8("cancelBedNo"));

        horizontalLayout_3->addWidget(cancelBedNo);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(cancelBed);

        QMetaObject::connectSlotsByName(cancelBed);
    } // setupUi

    void retranslateUi(QWidget *cancelBed)
    {
        cancelBed->setWindowTitle(QApplication::translate("cancelBed", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("cancelBed", "\345\217\226\346\266\210\347\227\205\345\272\212\345\215\240\344\275\215", nullptr));
        label->setText(QApplication::translate("cancelBed", "\350\257\267\351\200\211\346\213\251\347\227\205\345\214\272", nullptr));
        label_2->setText(QApplication::translate("cancelBed", "\350\257\267\350\276\223\345\205\245\345\272\212\345\217\267", nullptr));
        cancelBedWardCombo->setItemText(0, QApplication::translate("cancelBed", "\344\272\224\346\245\274\345\205\250\347\247\221", nullptr));
        cancelBedWardCombo->setItemText(1, QApplication::translate("cancelBed", "\345\205\255\346\245\274\351\243\216\346\271\277\350\200\201\345\271\264", nullptr));
        cancelBedWardCombo->setItemText(2, QApplication::translate("cancelBed", "\344\270\203\346\245\274\347\245\236\344\270\211", nullptr));
        cancelBedWardCombo->setItemText(3, QApplication::translate("cancelBed", "\345\205\253\346\245\274\345\221\274\344\270\211", nullptr));

        cancelBedYes->setText(QApplication::translate("cancelBed", "\344\277\256\346\224\271", nullptr));
        cancelBedNo->setText(QApplication::translate("cancelBed", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CancelBed: public Ui_cancelBed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCELBED_H
