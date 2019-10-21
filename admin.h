#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include "createaccount.h"
#include "products.h"
#include "updateaccount.h"


/**
 * \class Admin
 *
 * \brief Admin class used for operating admin login
 *
 * Admin sets up the UI for the admin login.
 * The login is going to differ from a normal
 * user login as they will have the ability to
 * edit customer accounts. They will be able to
 * add or remove customers as well as testimonials.
 */
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the Admin account
     * @param *parent which points to the admin account after it is made
     */
    explicit Admin(QDialog *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Close the admin login page
     */
    ~Admin();

    /**
     * @brief updates the name table view with new customer(s)
     * @return nothing
     */
    void updateNameTableView();

    /**
     * @brief updates the testimonial table view with new customer testimonials
     * @return nothing
     */
    void updateTestimonialTableView();
private slots:

    /**
     * @brief view customer button
     * @return nothing
     */
    void on_pushButton_clicked();


    /**
     * @brief add customer button
     * @return nothing
     */
    void on_pushButton_3_clicked();

    /**
     * @brief sees which name is clicked on within the
     * @param index for keeping track of which name is clicked on
     * @return nothing
     */
    void on_nameTableView_clicked(const QModelIndex &index);

    /**
     * @brief sees which testimonial is clicked on within the
     * @param index for keeping track of which testimonial is clicked on
     * @return nothing
     */
    void on_testimonialTableView_clicked(const QModelIndex &index);

    /**
     * @brief deletes testimonial that is clicked on
     * @return nothing
     */
    void on_deleteTestimonialButton_released();

    /**
     * @brief updates testimonial that is clicked on
     * @return nothing
     */
    void on_updateTestimonialButton_released();

    /**
     * @brief edits testimonial that is clicked on
     * @return nothing
     */
    void on_editTestimonialButton_released();

    /**
     * @brief resets testimonial edit that is clicked on
     * @return nothing
     */
    void on_editTestimonialButton_2_released();

    /**
     * @brief edit customer button
     * @return nothing
     */
    void on_pushButton_4_clicked();

    /**
     * @brief remove customer button
     * @return nothing
     */
    void on_removeCustomer_clicked();

    /**
     * @brief show key customer button
     * @return nothing
     */
    void on_pushButton_2_clicked();

    /**
     * @brief shows what is clicked on in the table
     * @return nothing
     */
    void on_tableView_clicked(const QModelIndex &index);

    /**
     * @brief logout button
     * @return nothing
     */
    void on_pushButton_5_clicked();

private:
    Ui::Admin *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
    QString tempText;
    int tempId;
    bool tempApproved;
    QString tempUsername;
    QString tempPassword;
    QString tempAdmin;
    QString tempName;
    QString tempAddress;
    QString tempCity;
    QString tempValue;
    QString tempEmail;
    QString tempInterest;
};

#endif // ADMIN_H
