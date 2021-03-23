#include "dialog.h"
#include "ui_dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMatrix>   // transorm the 2d image

Dialog::Dialog(QWidget *parent, Qt::WindowFlags flag)
    : QDialog(parent, flag)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("event filter test"));

    left = new QLabel;
    leftImg.load(":/flys/img/fly_0.png");
    left->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    left->setPixmap(QPixmap::fromImage(leftImg));

    middle = new QLabel;
    MiddleImg.load(":/flys/img/fly_1.png");
    middle->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    middle->setPixmap(QPixmap::fromImage(MiddleImg));

    right = new QLabel;
    RightImg.load(":/flys/img/fly_bee.png");
    right->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    right->setPixmap(QPixmap::fromImage(RightImg));

    // state
    state = new QLabel(tr("Check the image by pressing your mouse buttons"));
    state->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    // put comps to layout
    QHBoxLayout *layoutH = new QHBoxLayout;
    layoutH->addWidget(left);
    layoutH->addWidget(middle);
    layoutH->addWidget(right);
    QVBoxLayout *layoutV = new QVBoxLayout(this);
    layoutV->addLayout(layoutH);
    layoutV->addWidget(state);

    // eventfilter
    left->installEventFilter(this);
    middle->installEventFilter(this);
    right->installEventFilter(this);
}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == left)  // if the watched component is label left
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            // convert event to mouse click event
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                state->setText(tr("Left image is pressed; Mouse left is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::MiddleButton)
            {
                state->setText(tr("Middle image is pressed; Mouse middle is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::RightButton)
            {
                state->setText(tr("Right image is pressed; Mouse right is pressed"));
            }
            QMatrix matrix;
            matrix.scale(5, 5);
            QImage tmpImg = leftImg.transformed(matrix);
            left->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease)
        {
            state->setText(tr("Release left image"));
            left->setPixmap(QPixmap::fromImage(leftImg));
        }
    }
    else if(watched == middle)  // if the watched component is label middle
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            // convert event to mouse click event
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                state->setText(tr("Left image is pressed; Mouse left is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::MiddleButton)
            {
                state->setText(tr("Middle image is pressed; Mouse middle is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::RightButton)
            {
                state->setText(tr("Right image is pressed; Mouse right is pressed"));
            }
            QMatrix matrix;
            matrix.scale(5, 5);
            QImage tmpImg = MiddleImg.transformed(matrix);
            middle->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease)
        {
            state->setText(tr("Release left image"));
            middle->setPixmap(QPixmap::fromImage(MiddleImg));
        }
    }
    else if(watched == right)  // if the watched component is label right
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            // convert event to mouse click event
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                state->setText(tr("Left image is pressed; Mouse left is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::MiddleButton)
            {
                state->setText(tr("Middle image is pressed; Mouse middle is pressed"));
            }
            else if(mouseEvent->buttons() & Qt::RightButton)
            {
                state->setText(tr("Right image is pressed; Mouse right is pressed"));
            }
            QMatrix matrix;
            matrix.scale(5, 5);
            QImage tmpImg = RightImg.transformed(matrix);
            right->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease)
        {
            state->setText(tr("Release left image"));
            right->setPixmap(QPixmap::fromImage(RightImg));
        }
    }
    // return control back to QDialog
    return QDialog::eventFilter(watched, event);
}

Dialog::~Dialog()
{
    delete ui;
}

