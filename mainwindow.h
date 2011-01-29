#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scrambledword.h"
#include "admindialog.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    scrambledWord word;
    int seconds,minutes;
public slots:
    void buttonClicked();
    void setTime();
private:
    Ui::MainWindow *ui;
    int points;
    QTimer *timer;
    AdminDialog *checkStatus;
};

#endif // MAINWINDOW_H
