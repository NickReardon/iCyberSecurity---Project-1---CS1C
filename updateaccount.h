#ifndef UPDATEACCOUNT_H
#define UPDATEACCOUNT_H

#include <QDialog>
#include "dbmanager.h"

/**
 * \class updateAccount
 *
 * \brief updateAccount class
 *
 * UpdateAccount Class sets up the UI for
 * allowing the admin to update the account
 * of the user. This can include any information
 * that needs to be updated for the specific customer.
 */
namespace Ui {
class updateAccount;
}

class updateAccount : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the YesNo page
     * @param *parent which points to which field is going to change within the account
     */
    explicit updateAccount(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Closes UpdateAccount UI
     */
    ~updateAccount();

    /**
     * @brief Overloaded Constructor - updates the account with the information that is inputted by the admin
     * @param *parent used for iterating through the fields, username, password, admin name, name, address, city, value, email, and interest level of the customer
     */
    updateAccount(QWidget *parent, QString username, QString password, QString admin, QString name, QString address, QString city, QString value, QString email, QString interest);
private slots:

    /**
     * @brief back button for updating the account
     * @return nothing
     */
    void on_backButton_clicked();

    /**
     * @brief update button for updating the account
     * @return nothing
     */
    void on_updateRegButton_clicked();

private:
    Ui::updateAccount *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
    QString username;
    QString password;
    int admin;
    QString name;
    QString address;
    QString city;
    int value;
    QString email;
    QString interest;
    int columId;
};


#endif // UPDATEACCOUNT_H
