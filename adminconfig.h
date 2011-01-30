#ifndef ADMINCONFIG_H
#define ADMINCONFIG_H

#include <QDialog>

namespace Ui {
    class adminConfig;
}

class adminConfig : public QDialog
{
    Q_OBJECT

public:
    explicit adminConfig(QWidget *parent = 0);
    ~adminConfig();

private:
    Ui::adminConfig *ui;
};

#endif // ADMINCONFIG_H
