/********************************************************************************
** Form generated from reading UI file 'ccutils.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCUTILS_H
#define UI_CCUTILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCUtils
{
public:
    QAction *start_about;
    QAction *utils_cc;
    QAction *utils_clinic;
    QAction *utils_charge;
    QAction *utils_others;
    QAction *start_exit;
    QAction *ward_cancel_bed;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_start;
    QMenu *menu_utils;
    QMenu *utils_ward;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CCUtils)
    {
        if (CCUtils->objectName().isEmpty())
            CCUtils->setObjectName(QString::fromUtf8("CCUtils"));
        CCUtils->resize(1010, 675);
        start_about = new QAction(CCUtils);
        start_about->setObjectName(QString::fromUtf8("start_about"));
        utils_cc = new QAction(CCUtils);
        utils_cc->setObjectName(QString::fromUtf8("utils_cc"));
        utils_clinic = new QAction(CCUtils);
        utils_clinic->setObjectName(QString::fromUtf8("utils_clinic"));
        utils_charge = new QAction(CCUtils);
        utils_charge->setObjectName(QString::fromUtf8("utils_charge"));
        utils_others = new QAction(CCUtils);
        utils_others->setObjectName(QString::fromUtf8("utils_others"));
        start_exit = new QAction(CCUtils);
        start_exit->setObjectName(QString::fromUtf8("start_exit"));
        ward_cancel_bed = new QAction(CCUtils);
        ward_cancel_bed->setObjectName(QString::fromUtf8("ward_cancel_bed"));
        centralwidget = new QWidget(CCUtils);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CCUtils->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CCUtils);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1010, 26));
        menu_start = new QMenu(menubar);
        menu_start->setObjectName(QString::fromUtf8("menu_start"));
        menu_utils = new QMenu(menubar);
        menu_utils->setObjectName(QString::fromUtf8("menu_utils"));
        utils_ward = new QMenu(menu_utils);
        utils_ward->setObjectName(QString::fromUtf8("utils_ward"));
        CCUtils->setMenuBar(menubar);
        statusbar = new QStatusBar(CCUtils);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CCUtils->setStatusBar(statusbar);

        menubar->addAction(menu_start->menuAction());
        menubar->addAction(menu_utils->menuAction());
        menu_start->addAction(start_about);
        menu_start->addSeparator();
        menu_start->addAction(start_exit);
        menu_utils->addAction(utils_cc);
        menu_utils->addAction(utils_clinic);
        menu_utils->addAction(utils_ward->menuAction());
        menu_utils->addAction(utils_charge);
        menu_utils->addAction(utils_others);
        utils_ward->addAction(ward_cancel_bed);

        retranslateUi(CCUtils);

        QMetaObject::connectSlotsByName(CCUtils);
    } // setupUi

    void retranslateUi(QMainWindow *CCUtils)
    {
        CCUtils->setWindowTitle(QApplication::translate("CCUtils", "CCUtils", nullptr));
        start_about->setText(QApplication::translate("CCUtils", "\345\205\263\344\272\216", nullptr));
        utils_cc->setText(QApplication::translate("CCUtils", "\350\256\241\347\256\227\346\234\272\344\270\255\345\277\203", nullptr));
        utils_clinic->setText(QApplication::translate("CCUtils", "\350\257\212\351\227\264", nullptr));
        utils_charge->setText(QApplication::translate("CCUtils", "\346\224\266\350\264\271", nullptr));
        utils_others->setText(QApplication::translate("CCUtils", "\350\241\214\346\224\277\345\220\216\345\213\244", nullptr));
        start_exit->setText(QApplication::translate("CCUtils", "\351\200\200\345\207\272", nullptr));
        ward_cancel_bed->setText(QApplication::translate("CCUtils", "\345\217\226\346\266\210\345\267\262\351\242\204\347\272\246\345\272\212\344\275\215", nullptr));
        menu_start->setTitle(QApplication::translate("CCUtils", "\345\274\200\345\247\213", nullptr));
        menu_utils->setTitle(QApplication::translate("CCUtils", "\345\267\245\345\205\267", nullptr));
        utils_ward->setTitle(QApplication::translate("CCUtils", "\347\227\205\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCUtils: public Ui_CCUtils {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCUTILS_H
