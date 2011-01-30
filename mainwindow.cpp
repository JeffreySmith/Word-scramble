#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scrambledword.h"
#include "admindialog.h"
#include "loadfiles.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkStatus=new AdminDialog();
    game=true;

    //word.setWord(loadedFiles.parsedText[0]);
    word.setWord(loadedFiles.parsedText[index]);
    setFixedSize(400,274);
    timer = new QTimer(this);
    timer->setInterval(1000);
    //This tells the timer to run setTime every 1000 milliseconds
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setTime()));
    //This opens the admin password dialogue
    QObject::connect(ui->adminModeAction,SIGNAL(triggered()),this,SLOT(openDialogue()));
    //This gets whether or not the password was entered correctly, and acts accordingly
    QObject::connect(checkStatus,SIGNAL(accepted()),this,SLOT(checkAdminStatus()));

    //This will eventually be decided dynamicly..
    //word.setWord("Hello");

    points=0;seconds=0;minutes=1;
    //Sets the text input area's max number of characters to the length of the word
    ui->inputTextArea->setMaxLength(word.wordLength);
    ui->displayedWord->setText(QString::fromStdString(word.getScrambledWord()));
    ui->categoryLabel->setText(QString::fromStdString(word.getCategory()));
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
        if(game)
            points+=1;
        if(index+2<loadedFiles.parsedText.size())
        {

            index+=2;

            word.setWord(loadedFiles.parsedText[index]);
            word.setCategory(loadedFiles.parsedText[index+1]);


            ui->displayedWord->setText(QString::fromStdString(word.getScrambledWord()));
            ui->categoryLabel->setText(QString::fromStdString(word.getCategory()));

            ui->inputTextArea->setMaxLength(word.getScrambledWord().length());
        }
        else
        {
            game=false;
            ui->displayedWord->setText("Finished!");
        }

    }
    ui->totalPointsLabel->setText(QString::number(points));
}
void MainWindow::setTime()
{

    seconds-=1;
    if(!game)
    {
        minutes=0;seconds=0;
    }
    if(seconds<1)
    {

        if(minutes==0 && seconds==0)
        {
            timer->stop();
            game=false;
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
void MainWindow::openDialogue()
{
    checkStatus->exec();

}
void MainWindow::checkAdminStatus()
{
    if(checkStatus->admin)
    {
        //create admin config textfile here
    }

}


