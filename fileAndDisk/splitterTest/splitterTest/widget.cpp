#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /************* left splitter *****************/
    QSplitter *splitMain = new QSplitter(Qt::Horizontal, nullptr);
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"), splitMain);
    textLeft->setAlignment(Qt::AlignCenter);

    /***** right splitter ****************/
    // Top Widget
    QSplitter *splitRight = new QSplitter(Qt::Vertical, splitMain);
    splitRight->setOpaqueResize(false);   // the widget is not opaque when resizing it with QSplitter
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitRight);
    textUp->setAlignment(Qt::AlignCenter);
    // Bottom Widget
    QTextEdit *textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitRight);
    textBottom->setAlignment(Qt::AlignCenter);

    // configure splitter
    splitMain->setStretchFactor(1, 1);  // setStretchFactor controls how the widget can be adaptive




}

Widget::~Widget()
{
}

