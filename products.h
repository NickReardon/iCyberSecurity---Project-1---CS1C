#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QDebug>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
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

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Products *ui;
    QString currentUser;
};

#endif // PRODUCTS_H
