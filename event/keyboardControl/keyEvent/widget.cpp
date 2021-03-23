#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Hi Robot!!!"));

    // white background
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::white);
    setPalette(palette);

    // set size
    setMinimumSize(800, 600);
    setMaximumSize(800, 600);

    // size() function is inherited from QWidget class
    width = size().width();
    height = size().height();

    pix = new QPixmap(width, height);
    pix->fill(Qt::white);

    image.load(":role/image/robot.png");
    startX = 100;
    startY = 100;
    step = 20;
    drawPix();   // draw grid
    resize(800, 600);
}


void Widget::drawPix()
{
    pix->fill(Qt::white);   // refresh the background
    QPainter *painter = new QPainter;   // create QPainter object for drawing
    QPen pen(Qt::DotLine);   // QPen object which will be used for drawing grid pixs
    // draw horizontal grid line
    for(int i = step; i < width; i += step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i, 0), QPoint(i, height));
        painter->end();
    }
    // draw vertical grid line
    for(int j = step; j < height; j += step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0, j), QPoint(width, j));
        painter->end();
    }

    /******** QPainter::drawImage overloadded
    inline void QPainter::drawImage(const QPoint &p, const QImage &image)
    {
        drawImage(QPointF(p), image);
    }
    */
    painter->begin(pix);
    painter->drawImage(QPoint(startX, startY), image);
    painter->end();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)  // is Control is pressed
    {
        if(event->key() == Qt::Key_Left)
        {
            // is left margin
            startX = (startX - 1 < 0)? startX : startX - 5;
        }
        if(event->key() == Qt::Key_Right)
        {
            // is right margin
            startX = (startX + 1 + image.width() > width)? startX : startX + 5;
        }
        if(event->key() == Qt::Key_Up)
        {
            startY = (startY - 1 < 0) ? startY : startY - 5;
        }
        if(event->key() == Qt::Key_Down)
        {
            startY = (startY + 1 + image.height() > height) ? startY : startY + 5;
        }
    }

    else
    {
        // move initial x and y to the grid vertex
        startX=startX-startX%step;
        startY=startY-startY%step;
        if(event->key()==Qt::Key_Left)
        {
            startX=(startX-step<0)?startX:startX-step;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX=(startX+step+image.width()>width)?startX:startX+step;
        }
        if(event->key()==Qt::Key_Up)
        {
            startY=(startY-step<0)?startY:startY-step;
        }
        if(event->key()==Qt::Key_Down)
        {
            startY=(startY+step+image.height()>height)?
                        startY:startY+step;
        }
        if(event->key()==Qt::Key_Home)
        {
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_End)
        {
            startX=width-image.width();
            startY=height-image.height();
        }
    }

    drawPix();  // redraw the pix
    update();   // refresh the drawing
}

Widget::~Widget()
{
}

