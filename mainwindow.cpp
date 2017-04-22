#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}











myTimer::myTimer(MainWindow *mw)
{
    app_ = mw;
}

void myTimer::timerEvent(QTimerEvent *e)
{

}

void MainWindow::on_redSlider_valueChanged(int value)
{
    ui->redSliderLabel->setText(QString::number(value));
    ui->viewScreen->setRed(value);
    ui->viewScreen->update();

}

void MainWindow::on_greenSlider_valueChanged(int value)
{
    ui->greenSliderLabel->setText(QString::number(value));
    ui->viewScreen->setGreen(value);
    ui->viewScreen->update();
}


void MainWindow::on_blueSlider_valueChanged(int value)
{
    ui->blueSliderLabel->setText(QString::number(value));
    ui->viewScreen->setBlue(value);
    ui->viewScreen->update();
}

void MainWindow::on_redScaleDial_valueChanged(int value)
{
    ui->redDialLabel->setText(QString::number(value));
    ui->viewScreen->setRedScale(value);
    ui->viewScreen->update();
}

void MainWindow::on_greenScaleDial_valueChanged(int value)
{
    ui->greenDialLabel->setText(QString::number(value));
    ui->viewScreen->setGreenScale(value);
    ui->viewScreen->update();
}

void MainWindow::on_blueScaleDial_valueChanged(int value)
{
    ui->blueDialLabel->setText(QString::number(value));
    ui->viewScreen->setBlueScale(value);
    ui->viewScreen->update();
}
