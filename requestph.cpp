#include "requestph.h"
#include "ui_requestph.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the requestPh page
 * @param *parent which points to which email submitted by the user for requesting a pamphlet
 */
requestPh::requestPh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::requestPh)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor
 *
 * Closes requestPh UI
 */
requestPh::~requestPh()
{
    delete ui;
}

/**
 * @brief cancel button for requesting pamphlet
 * @return nothing
 */
void requestPh::on_cancelButton_clicked()
{
    hide();
}

/**
 * @brief request button for requesting pamphlet
 * @return nothing
 */
void requestPh::on_requestPButton_clicked()
{
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
        }
        else
        {
            dbManager.insertEmailR(ui->emailEdit->text());
            hide();
        }
    }

}
