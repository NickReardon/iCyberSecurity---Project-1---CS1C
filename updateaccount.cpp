#include "updateaccount.h"
#include "ui_updateaccount.h"
#include <QDebug>

updateAccount::updateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateAccount)
{
    ui->setupUi(this);
}

updateAccount::~updateAccount()
{
    delete ui;
}

void updateAccount::on_backButton_clicked()
{
    hide();
}

void updateAccount::on_updateRegButton_clicked()
{
    bool success2 = false;

    if(ui->uBox2->text() == "")
    {
        ui->uBox2->setPlaceholderText("Username EMPTY!");
        success2 = true;
    }

    if(ui->pBox2->text() == "")
    {
        ui->pBox2->setPlaceholderText("Password EMPTY!");
        success2 = true;
    }

    if(ui->eBox2->text() == "")
    {
        ui->eBox2->setPlaceholderText("E-mail EMPTY!");
        success2 = true;
    }

    if(ui->fBox2->text() == "")
    {
        ui->fBox2->setPlaceholderText("Address Name EMPTY!");
        success2 = true;
    }

    if(ui->nBox2->text() == "")
    {
        ui->nBox2->setPlaceholderText("Company/Personal Name EMPTY!");
        success2 = true;
    }

    if(ui->mBox2->text() == "")
    {
        ui->mBox2->setPlaceholderText("State, City, Zip EMPTY!");
        success2 = true;
    }


    if(dbManager.usernameExists(ui->uBox2->text()))
    {
        ui->uBox2->setText("");
        ui->uBox2->setPlaceholderText("Choose a different Username!");
        success2 = true;
    }

    if(dbManager.nameExists(ui->nBox2->text()))
    {
        ui->nBox2->setText("");
        ui->nBox2->setPlaceholderText("Choose a different name!");
        success2 = true;
    }


    if(!success2)
    {
        //const QString& username, const QString& password, const QString& name, const QString& address, const QString& city, const QString &email
        dbManager.updateAccount(ui->uBox2->text(), ui->pBox2->text(), ui->nBox2->text(), ui->fBox2->text(), ui->mBox2->text(), ui->eBox2->text());
        qDebug() << ui->uBox2->text();
        hide();
    }


}
