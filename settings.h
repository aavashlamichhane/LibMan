#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "about.h"
#include "privacyandsecurity.h"
#include "helpandsupport.h"


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_pushButton_logout_clicked();

    void on_pushButton_home_clicked();

    void on_pushButton_privacy_clicked();

    void on_pushButton_help_clicked();

    void on_pushButton_about_clicked();

private:
    Ui::Settings *ui;
    about *abt;
    privacyandsecurity *pvs;
    helpandsupport *hlps;

};

#endif // SETTINGS_H
