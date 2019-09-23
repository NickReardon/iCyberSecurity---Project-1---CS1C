#include "userlogin.h"
#include "ui_userlogin.h"

userLogin::userLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userLogin)
{
    ui->setupUi(this);
}

userLogin::~userLogin()
{
    delete ui;
}
