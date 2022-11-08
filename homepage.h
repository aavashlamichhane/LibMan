#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include "settings.h"
#include "userinfo.h"
#include "entry.h"
namespace Ui {
class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_settings_clicked();

    void on_pushButton_user_clicked();

    void on_pushButton_adminpanel_clicked();

private:
    Ui::HomePage *ui;
    Settings *settings;
    UserInfo *info;
    entry *newbook;
};

#endif // HOMEPAGE_H
