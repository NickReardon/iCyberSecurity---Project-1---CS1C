#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QDebug>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <sstream>
#include <string>
#include "dbmanager.h"

/**
 * \class Products
 *
 * \brief Products class
 *
 * Products is the class used for
 * creating the UI that is seen on the
 * products page after an account is made
 * and logged into. This page will enable them
 * to choose from three different products and
 * allows the user to choose the quantity in which
 * they want for each product.
 */
namespace Ui {
class Products;
}

class Products : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the products page
     * @param *parent which points to the product(s) that is chose
     */
    explicit Products(QWidget *parent = nullptr);

    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the products page
     * @param *parent which points to the products after they have selected it, and username of the user
     */
    explicit Products(QWidget *parent, QString username);

    /**
     * @brief Destructor
     *
     * Closes Products UI
     */
    ~Products();

    /**
     * @brief updates the cart with selected products
     * @return nothing
     */
    void updateCart();

    /**
     * @brief updates the current list of testimonials
     * @return nothing
     */
    void updateTestimonialsList();
private slots:

    /**
     * @brief button for adding common product
     * @return nothing
     */
    void on_item1AddButton_released();

    /**
     * @brief button for removing common product
     * @return nothing
     */
    void on_item1RemoveButton_released();

    /**
     * @brief button for adding premium product
     * @return nothing
     */
    void on_item2AddButton_released();

    /**
     * @brief button for removing premium product
     * @return nothing
     */
    void on_item2RemoveButton_released();

    /**
     * @brief button for adding platinum product
     * @return nothing
     */
    void on_item3AddButton_released();

    /**
     * @brief button for removing platinum product
     * @return nothing
     */
    void on_item3RemoveButton_released();

    /**
     * @brief button for emptying cart
     * @return nothing
     */
    void on_emptyCartButton_released();

    /**
     * @brief button checking out cart
     * @return nothing
     */
    void on_checkOutButton_released();

    void on_pushButton_clicked();

private:
    Ui::Products *ui;
    QString currentUser;
    int item1Count = 0;
    int item2Count = 0;
    int item3Count = 0;

    double item1Cost = 50.0;
    double item2Cost = 100.0;
    double item3Cost = 150.0;

    double cartTotal;

    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // PRODUCTS_H
