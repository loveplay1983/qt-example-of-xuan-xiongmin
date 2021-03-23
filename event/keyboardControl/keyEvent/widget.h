#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QImage>
#include <QPen>
#include <QPoint>


class Widget : public QWidget
{
    Q_OBJECT

    QPixmap *pix;   // Object for drawing object with double cache
    QImage image;    // The moving object

    // The icon object top left coordinate
//    QPoint start;
    int startX;
    int startY;

    // Window width and height
    int width;
    int height;
    int step;   // grid size

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawPix();
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);

};
#endif // WIDGET_H
