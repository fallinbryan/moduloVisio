#include "drawingwindow.h"
#include <QPainter>
#include <QDebug>

DrawingWindow::DrawingWindow(QWidget *parent) : QWidget(parent)
{
    rgb = 0xff0000;
    scaleRedBy = 1;
    scaleGreenBy = 0;
    scaleBlueBy = 0;

}

void DrawingWindow::setRed(int red)
{

    rgb = (rgb & 0x00ffff) | ((red & 0xff ) << 16);

}

void DrawingWindow::setGreen(int green)
{
   rgb = (rgb & 0xff00ff) | ((green & 0xff ) << 8);
}

void DrawingWindow::setBlue(int blue)
{
    rgb = (rgb & 0xffff00) | ((blue & 0xff ));
}

void DrawingWindow::setRedScale(int red)
{
    scaleRedBy = red;
}

void DrawingWindow::setGreenScale(int green)
{
    scaleGreenBy = green;
}

void DrawingWindow::setBlueScale(int blue)
{
    scaleBlueBy = blue;
}

void DrawingWindow::paintEvent(QPaintEvent *)
{

    int x_max = this->geometry().right();
    int y_max = this->geometry().bottom();

    QPainter paint(this);
    QPen pen(paint.pen());
    unsigned int fadedRgb = rgb;

//    QBrush brush(paint.brush());
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(QColor(rgb));
//    paint.setBrush(brush);
//    paint.drawRect(this->geometry());

    for(int col = 1; col < y_max; col ++) {
        for(int row = 1; row < x_max; row++) {

            if(row%(col+x_max) == 0) {

                fadedRgb = rgb;

                pen.setColor(QColor(fadedRgb));
                paint.setPen(pen);
                paint.drawPoint(row,col);
            } else {
                fadedRgb -= row%col * scaleRedBy    * 0x010000;
                fadedRgb -= row%col * scaleGreenBy  * 0x000100;
                fadedRgb -= row%col * scaleBlueBy   * 0x000001;
                pen.setColor(QColor(fadedRgb));

                paint.setPen(pen);
                paint.drawPoint(row,col);

            }

        }
    }






}

int DrawingWindow::getRed(){
    return ((rgb >> 16) & 0xff )/ 255.0;
}
int DrawingWindow::getGreen(){
    return ((rgb >> 8) & 0xff )/ 255.0;
}
int DrawingWindow::getBlue(){
    return ((rgb) & 0xff )/ 255.0;
}
