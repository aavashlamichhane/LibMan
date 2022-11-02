#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entry.h"
#include "signup.h"
#include "request.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    entry *Entry;
    SignUp *signup;
    Request *request;
};
#endif // MAINWINDOW_H
