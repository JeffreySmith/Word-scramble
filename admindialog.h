#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

namespace Ui {
    class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = 0);
    ~AdminDialog();
    bool admin;
public slots:
    void checkUsernamePassword();
private:
    Ui::AdminDialog *ui;
    QString password;
    QString username;

};

#endif // ADMINDIALOG_H
