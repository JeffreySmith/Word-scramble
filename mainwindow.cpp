#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scrambledword.h"
#include "admindialog.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkStatus=new AdminDialog();


    timer = new QTimer(this);
    timer->setInterval(1000);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setTime()));





    //This will eventually be decided dynamicly..
    word.setWord("Hello");

    points=0;seconds=0;minutes=1;
    //Sets the text input area's max number of characters to the length of the word
    ui->inputTextArea->setMaxLength(word.wordLength);
    ui->displayedWord->setText(QString::fromStdString(word.getScrambledWord()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete checkStatus;
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
    //These are so the timer looks like xx:xx instead of xx:x when seconds are less than two digits long
    if(seconds>9)
    {
         ui->timeLabel->setText(QString::number(minutes)+":"+QString::number(seconds));
    }
    else
    {
        ui->timeLabel->setText(QString::number(minutes)+":0"+QString::number(seconds));
    }

}
