#ifndef BOOKISSUE_H
#define BOOKISSUE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class bookissue;
}

class bookissue : public QDialog
{
    Q_OBJECT

public:
    explicit bookissue(QWidget *parent = nullptr);
    ~bookissue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::bookissue *ui;
    QSqlDatabase dabook;
};

#endif // BOOKISSUE_H
