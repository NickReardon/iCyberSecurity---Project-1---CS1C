#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

/**
 * \class createAccount
 *
 * \brief createAccount is used for creating the account
 * for a user.
 *
 * createAccount sets up the UI for the creating
 * an account.
 */
namespace Ui {
class createAccount;
}

class createAccount : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the user account
     * @param *parent which points to the account after it is made
     */
    explicit createAccount(QDialog *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Close createAccount UI
     */
    ~createAccount();

private slots:
    /**
     * @brief complete button for completing making an account
     * @return nothing
     */
    void on_completeRegButton_clicked();

    /**
     * @brief back button for completing making an account
     * @return nothing
     */
    void on_backButton_clicked();

private:
    Ui::createAccount *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // CREATEACCOUNT_H
