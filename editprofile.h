#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>


namespace Ui {
class editProfile;
}

class editProfile : public QDialog
{
    Q_OBJECT

public:
    explicit editProfile(QWidget *parent = nullptr);
    ~editProfile();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::editProfile *ui;
};

#endif // EDITPROFILE_H
