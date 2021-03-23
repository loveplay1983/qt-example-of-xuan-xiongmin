/********************************************************************************
** Form generated from reading UI file 'cancelpzzxsmile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCELPZZXSMILE_H
#define UI_CANCELPZZXSMILE_H

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

class Ui_CancelPzzxSmile
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelSmileYes;
    QPushButton *cancelSmileNo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cancelSmileWardCombo;
    QLineEdit *cancelSmileNumInput;

    void setupUi(QWidget *CancelPzzxSmile)
    {
        if (CancelPzzxSmile->objectName().isEmpty())
            CancelPzzxSmile->setObjectName(QString::fromUtf8("CancelPzzxSmile"));
        CancelPzzxSmile->resize(400, 300);
        groupBox = new QGroupBox(CancelPzzxSmile);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 361, 251));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 130, 195, 34));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cancelSmileYes = new QPushButton(layoutWidget);
        cancelSmileYes->setObjectName(QString::fromUtf8("cancelSmileYes"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        cancelSmileYes->setFont(font);

        horizontalLayout_3->addWidget(cancelSmileYes);

        cancelSmileNo = new QPushButton(layoutWidget);
        cancelSmileNo->setObjectName(QString::fromUtf8("cancelSmileNo"));
        cancelSmileNo->setFont(font);

        horizontalLayout_3->addWidget(cancelSmileNo);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(33, 50, 301, 57));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cancelSmileWardCombo = new QComboBox(layoutWidget1);
        cancelSmileWardCombo->addItem(QString());
        cancelSmileWardCombo->addItem(QString());
        cancelSmileWardCombo->addItem(QString());
        cancelSmileWardCombo->addItem(QString());
        cancelSmileWardCombo->setObjectName(QString::fromUtf8("cancelSmileWardCombo"));

        verticalLayout->addWidget(cancelSmileWardCombo);

        cancelSmileNumInput = new QLineEdit(layoutWidget1);
        cancelSmileNumInput->setObjectName(QString::fromUtf8("cancelSmileNumInput"));

        verticalLayout->addWidget(cancelSmileNumInput);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CancelPzzxSmile);

        QMetaObject::connectSlotsByName(CancelPzzxSmile);
    } // setupUi

    void retranslateUi(QWidget *CancelPzzxSmile)
    {
        CancelPzzxSmile->setWindowTitle(QApplication::translate("CancelPzzxSmile", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("CancelPzzxSmile", "\345\217\226\346\266\210\351\205\215\347\275\256\344\270\255\345\277\203\346\240\207\345\277\227", nullptr));
        cancelSmileYes->setText(QApplication::translate("CancelPzzxSmile", "\345\201\234\346\255\242\347\254\221\350\204\270", nullptr));
        cancelSmileNo->setText(QApplication::translate("CancelPzzxSmile", "\347\246\273\345\274\200", nullptr));
        label->setText(QApplication::translate("CancelPzzxSmile", "\350\257\267\351\200\211\346\213\251\347\227\205\345\214\272", nullptr));
        label_2->setText(QApplication::translate("CancelPzzxSmile", "\350\257\267\350\276\223\345\205\245\344\275\217\351\231\242\345\217\267", nullptr));
        cancelSmileWardCombo->setItemText(0, QApplication::translate("CancelPzzxSmile", "\344\272\224\346\245\274\345\205\250\347\247\221", nullptr));
        cancelSmileWardCombo->setItemText(1, QApplication::translate("CancelPzzxSmile", "\345\205\255\346\245\274\351\243\216\346\271\277\350\200\201\345\271\264", nullptr));
        cancelSmileWardCombo->setItemText(2, QApplication::translate("CancelPzzxSmile", "\344\270\203\346\245\274\347\245\236\344\270\211", nullptr));
        cancelSmileWardCombo->setItemText(3, QApplication::translate("CancelPzzxSmile", "\345\205\253\346\245\274\345\221\274\344\270\211", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CancelPzzxSmile: public Ui_CancelPzzxSmile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCELPZZXSMILE_H
