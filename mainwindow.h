#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scrambledword.h"
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
};

#endif // MAINWINDOW_H
