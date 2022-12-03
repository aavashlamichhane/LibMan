#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow *login;
int countDigits(long long n)
{
   int a=0;
   while(n!=0)
   {
       a++;
       n=n/10;
   }
   return a;
}
bool chkChar(QChar c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool chkEmail(QString email)
{

    if (!chkChar(email[0]))
    {
        return 0;
    }

    int at =-1, dot =-1;

    for (int i = 0;
         i < email.length(); i++) {

        if (email[i] == '@') {

            at = i;
        }

        else if (email[i] == '.') {

            dot = i;
        }
    }

    if (at == -1 || dot == -1)
        return 0;

    if (at > dot)
        return 0;

    return !(dot >= (email.length() - 1));
}
SignUp::SignUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
    database = QSqlDatabase::addDatabase("QMYSQL","SignUp");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("rampyari1234");
    database.setDatabaseName("libman");

    ui->pushbutton_login->setStyleSheet(
                "   QPushButton {"
                "     background:transparent; Text-align:left;font-family:timesnewroman gothic;font-size:12px; color:blue;"
                " }"
                " QPushButton:hover {"
                "     color: rgb(0, 255, 255);font-size:16px;"
                " }");
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushbutton_login_clicked()
{
    close();
    login= new MainWindow();
    login->showMaximized();
}


void SignUp::on_pushButton_clicked()
{
    if(database.open())
    {
        QString fN = ui->lineEdit_fN->text();
        QString mN = ui->lineEdit_mN->text();
        QString lN = ui->lineEdit_lN->text();
        QString user = ui->lineEdit_user->text();
        QString email = ui->lineEdit_email->text();
        long long pNum1=ui->lineEdit_pNum->text().toLongLong();
        QString pNum = ui->lineEdit_pNum->text();
        QString sex = ui->comboBox_sex->currentText();
        QDate dob = ui->dateEdit_dob->date();
        QString password = ui->lineEdit_password->text();
        QString cpassword = ui->lineEdit_cpassword->text();
        QString secques = ui->comboBox_ques1->currentText();
        QString secans = ui->lineEdit_ans1->text();
        QSqlQuery chku(database),chke(database),chkp(database);
        chku.prepare("SELECT * FROM userbase WHERE username=:username");
        chku.bindValue(":username",user);
        chke.prepare("SELECT * FROM userbase WHERE user_email=:user_email");
        chke.bindValue(":user_email",email);
        chkp.prepare("SELECT * FROM userbase WHERE phone_number=:phone_number");
        chkp.bindValue(":phone_number",pNum);
        chku.exec();
        chkp.exec();
        chke.exec();
        if(password!=cpassword)
        {
            QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
        }
        else if(countDigits(pNum1)!=10)
        {
            QMessageBox::warning(this,"Error","Phone number is not correct. Please try again.");

        }
        else if(fN=="\0" || lN=="\0" || user=="\0" || email=="\0" || pNum=="\0")
            QMessageBox::warning(this,"Error","Don't leave fields empty.");
        else if(!dob.isValid())
            QMessageBox::warning(this,"Error","Invalid Date.");
        else if(chku.next())
            QMessageBox::warning(this,"Error","Username already taken.");
        else if(chke.next())
            QMessageBox::warning(this,"Error","Email already used.");
        else if(chkp.next())
            QMessageBox::warning(this,"Error","Phone number already used.");
        else if(!chkEmail(email))
            QMessageBox::warning(this,"Error","Invalid Email.");
        else
        {
            QSqlQuery qry(database);
            qry.prepare("INSERT INTO userbase(username,password,first_name,middle_name,last_name,user_email,date_of_birth,phone_number,sex,security_ques,security_ans)""VALUES(:username,:password,:first_name,:middle_name,:last_name,:user_email,:date_of_birth,:phone_number,:sex,:security_ques,:security_ans)");
            qry.bindValue(":username",user);
            qry.bindValue(":password",password);
            qry.bindValue(":first_name",fN);
            qry.bindValue(":middle_name",mN);
            qry.bindValue(":last_name",lN);
            qry.bindValue(":date_of_birth",dob);
            qry.bindValue(":user_email",email);
            qry.bindValue(":phone_number",pNum);
            qry.bindValue(":sex",sex);
            qry.bindValue(":security_ques",secques);
            qry.bindValue(":security_ans",secans);

            if(qry.exec())
            {
                QMessageBox::information(this,"Sign Up","Signed up successfully.");
                close();
                login= new MainWindow();
                login->showMaximized();
                QSqlDatabase::removeDatabase("QMYSQL");
            }
            else
            {
                QMessageBox::warning(this,"Sign Up","Signed up failed.");
                qDebug() << qry.lastError().text()<<Qt::endl;
                QSqlDatabase::removeDatabase("QMYSQL");
            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
    }
    database.close();
}

void SignUp::on_lineEdit_cpassword_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_lN_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_mN_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_fN_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_user_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_email_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_pNum_returnPressed()
{
    on_pushButton_clicked();
}


void SignUp::on_lineEdit_password_returnPressed()
{
    on_pushButton_clicked();
}

