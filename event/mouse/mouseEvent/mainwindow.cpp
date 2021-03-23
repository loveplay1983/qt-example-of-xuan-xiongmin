#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Mouse Event"));
    status = new QLabel;
    status->setText(tr("Current Pos -> "));
    status->setFixedWidth(100);
    mousePos = new QLabel;
    mousePos->setText(tr(""));
    mousePos->setFixedWidth(100);
    statusBar()->addPermanentWidget(status);
    statusBar()->addPermanentWidget(mousePos);
    this->setMouseTracking(true);   // track mouse coordinate

    resize(400, 300);
}


void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mousePos->setText("(" + QString::number(e->x()) + ", " +
                      QString::number(e->y()) + ")");
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString str= "(" + QString::number(event->x()) + ", " +
            QString::number(event->y()) + ")";

    if(event->button() == Qt::LeftButton)
    {
        statusBar()->showMessage(tr("Left Button: ") + str);
    }
    else if(event->button() == Qt::RightButton)
    {
        statusBar()->showMessage(tr("Right Button: ") + str);
    }
    else if(event->button() == Qt::MiddleButton)
    {
        statusBar()->showMessage(tr("Middle Button: ") + str);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString str= "(" + QString::number(e->x()) + ", " +
            QString::number(e->y()) + ")";
    statusBar()->showMessage(tr("Released at: ") + str, 3000);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    QString str= "(" + QString::number(e->x()) + ", " +
            QString::number(e->y()) + ")";
    QMessageBox::information(this, tr("Tip"),
                             tr("You have double-clicked at the pos of ") + str);
}


MainWindow::~MainWindow()
{
}

