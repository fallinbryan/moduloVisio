#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <QWidget>

class DrawingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingWindow(QWidget *parent = 0);
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);
    void setRedScale(int red);
    void setGreenScale(int green);
    void setBlueScale(int blue);
    int getRed();
    int getGreen();
    int getBlue();
signals:

public slots:

protected:
    void paintEvent(QPaintEvent*);

private:
    unsigned int rgb;
    int scaleRedBy;
    int scaleGreenBy;
    int scaleBlueBy;
};

#endif // DRAWINGWINDOW_H
