#include "requestph.h"
#include "ui_requestph.h"

requestPh::requestPh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::requestPh)
{
    ui->setupUi(this);
}

requestPh::~requestPh()
{
    delete ui;
}

void requestPh::on_cancelButton_clicked()
{
    hide();
}

void requestPh::on_requestPButton_clicked()
{
    bool success = false;

    if(ui->emailEdit->text() == "")
    {
        ui->emailEdit->setPlaceholderText("Email address EMPTY!");
    }
    else
    {
        if(dbManager.emailExists(ui->emailEdit->text()))
        {
            dbManager.emailRecieved(ui->emailEdit->text());
            hide();
            success = true;
        }
        else
        {
            dbManager.insertEmailR(ui->emailEdit->text());
            hide();
            success = true;
        }
    }
}
