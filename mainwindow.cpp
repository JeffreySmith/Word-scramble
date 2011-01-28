#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scrambledword.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    seconds=0;minutes=1;
    timer = new QTimer(this);
    timer->setInterval(1000);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setTime()));
    timer->start();
    word.setWord("Hello");
    points=0;
    ui->inputTextArea->setMaxLength(word.wordLength);
    ui->displayedWord->setText(QString::fromStdString(word.getScrambledWord()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}
void MainWindow::buttonClicked()
{
    if(ui->inputTextArea->text()==QString::fromStdString(word.getWord()))
    {
        points+=1;
    }
    ui->totalPointsLabel->setText(QString::number(points));
}
void MainWindow::setTime()
{

    seconds-=1;
    if(seconds<1)
    {

        if(minutes==0 && seconds==0)
        {
            timer->stop();
        }
        if(minutes>0 && seconds<0)
        {
            minutes-=1;
            seconds=59;
        }


    }
    if(seconds>9)
    {
         ui->timeLabel->setText(QString::number(minutes)+":"+QString::number(seconds));
    }
    else
    {
        ui->timeLabel->setText(QString::number(minutes)+":0"+QString::number(seconds));
    }

}
