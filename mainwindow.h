#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class myTimer;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_redSlider_valueChanged(int value);

    void on_greenSlider_valueChanged(int value);

    void on_blueSlider_valueChanged(int value);

    void on_redScaleDial_valueChanged(int value);

    void on_greenScaleDial_valueChanged(int value);

    void on_blueScaleDial_valueChanged(int value);

private:
    Ui::MainWindow *ui;




};


class myTimer : public QTimer {
public:
    myTimer(MainWindow* mw);
protected:
    void timerEvent(QTimerEvent* e);
private:
    MainWindow* app_;
};

#endif // MAINWINDOW_H
