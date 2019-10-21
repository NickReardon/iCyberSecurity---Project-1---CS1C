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

namespace Ui {
class Products;
}

class Products : public QDialog
{
    Q_OBJECT

public:
    explicit Products(QWidget *parent = nullptr);
    explicit Products(QWidget *parent, QString username);
    ~Products();

    void updateCart();
    void updateTestimonialsList();
private slots:




    void on_item1AddButton_released();

    void on_item1RemoveButton_released();

    void on_item2AddButton_released();

    void on_item2RemoveButton_released();

    void on_item3AddButton_released();

    void on_item3RemoveButton_released();

    void on_emptyCartButton_released();

    void on_checkOutButton_released();

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
