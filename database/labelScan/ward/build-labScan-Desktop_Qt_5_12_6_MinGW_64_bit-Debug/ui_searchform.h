/********************************************************************************
** Form generated from reading UI file 'searchform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelSearchFormInput;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditSearchFormInput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *labelSearch;
    QSpacerItem *horizontalSpacer;
    QTableView *tableViewSearchForm;

    void setupUi(QWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QString::fromUtf8("SearchForm"));
        SearchForm->resize(975, 683);
        horizontalLayout = new QHBoxLayout(SearchForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(SearchForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelSearchFormInput = new QLabel(groupBox);
        labelSearchFormInput->setObjectName(QString::fromUtf8("labelSearchFormInput"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSearchFormInput->sizePolicy().hasHeightForWidth());
        labelSearchFormInput->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        labelSearchFormInput->setFont(font);

        horizontalLayout_3->addWidget(labelSearchFormInput);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditSearchFormInput = new QLineEdit(groupBox);
        lineEditSearchFormInput->setObjectName(QString::fromUtf8("lineEditSearchFormInput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditSearchFormInput->setFont(font1);

        verticalLayout->addWidget(lineEditSearchFormInput);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelSearch = new QPushButton(groupBox);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        labelSearch->setFont(font2);

        horizontalLayout_2->addWidget(labelSearch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tableViewSearchForm = new QTableView(groupBox);
        tableViewSearchForm->setObjectName(QString::fromUtf8("tableViewSearchForm"));

        verticalLayout_2->addWidget(tableViewSearchForm);


        horizontalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QApplication::translate("SearchForm", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("SearchForm", "\346\240\267\346\234\254\346\237\245\350\257\242", nullptr));
        labelSearchFormInput->setText(QApplication::translate("SearchForm", "\350\276\223\345\205\245\346\240\207\347\255\276\345\217\267\357\274\232", nullptr));
        labelSearch->setText(QApplication::translate("SearchForm", "\346\237\245\350\257\242\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
