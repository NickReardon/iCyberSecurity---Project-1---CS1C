#include "updateaccount.h"
#include "ui_updateaccount.h"
#include <QDebug>

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the YesNo page
 * @param *parent which points to which field is going to change within the account
 */
updateAccount::updateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateAccount)
{
    ui->setupUi(this);
}

/**
 * @brief Overloaded Constructor - updates the account with the information that is inputted by the admin
 * @param *parent used for iterating through the fields, username, password, admin name, name, address, city, value, email, and interest level of the customer
 */
updateAccount::updateAccount(QWidget *parent, QString username2, QString password2, QString admin2, QString name2, QString address2, QString city2, QString value2, QString email2, QString interest2) : QDialog(parent),
    ui(new Ui::updateAccount)
{
    ui->setupUi(this);
    username = username2;
    password = password2;
    admin = admin2.toInt();
    name = name2;
    address = address2;
    city = city2;
    if(value2 == "key")
    {
        value = 1;
    }
    else
    {
        value = 0;
    }
    email = email2;
    interest = interest2;

    if(interest == "very interested")
    {
        columId = 0;
    }
    else if(interest == "somewhat interested")
    {
        columId = 1;
    }
    else if(interest == "not interested")
    {
        columId = 2;
    }
    else if(interest == "never call again")
    {
        columId = 3;
    }
    else
    {
        columId = 2;
    }

    qDebug() << columId << interest;

    ui->interestBox->setCurrentIndex(columId);
    ui->adminBox->setChecked(admin);
    ui->keyBox->setChecked(value);
    ui->usernameBrowser->setText(username);
    ui->pBox2->setText(password);
    ui->eBox2->setText(email);
    ui->fBox2->setText(address);
    ui->nBox2->setText(name);
    ui->mBox2->setText(city);
}

/**
 * @brief Destructor
 *
 * Closes UpdateAccount UI
 */
updateAccount::~updateAccount()
{
    delete ui;
}

/**
 * @brief back button for updating the account
 * @return nothing
 */
void updateAccount::on_backButton_clicked()
{
    hide();
}

/**
 * @brief update button for updating the account
 * @return nothing
 */
void updateAccount::on_updateRegButton_clicked()
{
    bool success2 = false;
    int value3 = 0;
    QString value4;

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

    if(email == ui->eBox2->text())
    {

    }
    else if(dbManager.emailExists(ui->eBox2->text()))
    {
        ui->eBox2->setText("");
        ui->eBox2->setPlaceholderText("Email already EXIST!");
        success2 = true;
    }

    if(name == ui->nBox2->text())
    {

    }
    else if(dbManager.nameExists(ui->nBox2->text()))
    {
        ui->nBox2->setText("");
        ui->nBox2->setPlaceholderText("Name already EXIST!");
        success2 = true;
    }


    if(!success2)
    {
        //const QString& username, const QString& password, const QString& name, const QString& address, const QString& city, const QString &email

        if(ui->keyBox->isChecked())
        {
            value4 = "key";
        }
        else
        {
            value4 = "nice to have";
        }

        if(ui->adminBox->isChecked())
        {
            value3 = 1;
        }
        else
        {
            value3 = 0;
        }

        switch(ui->interestBox->currentIndex())
        {
            case 0 : interest = "very intersted";
            break;

            case 1 : interest = "somewhat interested";
            break;

            case 2 : interest = "not interested";
            break;

            case 3 : interest = "nerver call again";
            break;
        }

        dbManager.updateAccount(username, ui->pBox2->text(), ui->nBox2->text(), ui->fBox2->text(), ui->mBox2->text(), ui->eBox2->text(), value4, value3, interest);
        qDebug() << username;
        hide();
    }


}
