#include "createaccount.h"
#include "ui_createaccount.h"

createAccount::createAccount(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);
}

createAccount::~createAccount()
{
    delete ui;
}

void createAccount::on_completeRegButton_clicked()
{

    bool halt = false;

    if(ui->uBox->text() == "")
    {
        ui->uBox->setPlaceholderText("Username EMPTY!");
        halt = true;
    }

    if(ui->pBox->text() == "")
    {
        ui->pBox->setPlaceholderText("Password EMPTY!");
        halt = true;
    }

    if(ui->eBox->text() == "")
    {
        ui->eBox->setPlaceholderText("E-mail EMPTY!");
        halt = true;
    }

    if(ui->fBox->text() == "")
    {
        ui->fBox->setPlaceholderText("Address Name EMPTY!");
        halt = true;
    }

    if(ui->nBox->text() == "")
    {
        ui->nBox->setPlaceholderText("Company/Personal Name EMPTY!");
        halt = true;
    }

    if(ui->mBox->text() == "")
    {
        ui->mBox->setPlaceholderText("State, City, Zip EMPTY!");
        halt = true;
    }

    if(dbManager.usernameExists(ui->uBox->text()))
    {
        ui->uBox->setText("");
        ui->uBox->setPlaceholderText("Choose a different Username!");
        halt = true;
    }

    if(dbManager.nameExists(ui->nBox->text()))
    {
        ui->nBox->setText("");
        ui->nBox->setPlaceholderText("Choose a different name!");
        halt = true;
    }

    if(!halt)
    {
        dbManager.addAccount(ui->uBox->text(), ui->pBox->text(), ui->nBox->text(), ui->fBox->text(), ui->mBox->text(), ui->eBox->text());
        hide();
    }

}

void createAccount::on_backButton_clicked()
{
    hide();
}
