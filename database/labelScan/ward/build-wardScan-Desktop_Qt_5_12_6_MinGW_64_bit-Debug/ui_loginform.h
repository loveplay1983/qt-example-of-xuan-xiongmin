/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loginform
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *editUser;
    QLineEdit *editPasswd;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnLogin;
    QPushButton *btnQuit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Loginform)
    {
        if (Loginform->objectName().isEmpty())
            Loginform->setObjectName(QString::fromUtf8("Loginform"));
        Loginform->resize(477, 365);
        verticalLayout_4 = new QVBoxLayout(Loginform);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(Loginform);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 401, 281));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        editUser = new QLineEdit(layoutWidget);
        editUser->setObjectName(QString::fromUtf8("editUser"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        editUser->setFont(font1);

        verticalLayout->addWidget(editUser);

        editPasswd = new QLineEdit(layoutWidget);
        editPasswd->setObjectName(QString::fromUtf8("editPasswd"));
        editPasswd->setFont(font1);

        verticalLayout->addWidget(editPasswd);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnLogin = new QPushButton(layoutWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setFont(font);

        horizontalLayout_2->addWidget(btnLogin);

        btnQuit = new QPushButton(layoutWidget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setFont(font);

        horizontalLayout_2->addWidget(btnQuit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(groupBox);


        retranslateUi(Loginform);

        QMetaObject::connectSlotsByName(Loginform);
    } // setupUi

    void retranslateUi(QDialog *Loginform)
    {
        Loginform->setWindowTitle(QApplication::translate("Loginform", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Loginform", "\347\224\250\346\210\267", nullptr));
        label_2->setText(QApplication::translate("Loginform", "\345\257\206\347\240\201", nullptr));
        btnLogin->setText(QApplication::translate("Loginform", "\347\231\273\345\205\245", nullptr));
        btnQuit->setText(QApplication::translate("Loginform", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginform: public Ui_Loginform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
