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


namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QDialog *parent = nullptr);
    ~Admin();

    void updateNameTableView();
    void updateTestimonialTableView();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_nameTableView_clicked(const QModelIndex &index);

    void on_testimonialTableView_clicked(const QModelIndex &index);

    void on_deleteTestimonialButton_released();

    void on_updateTestimonialButton_released();

    void on_editTestimonialButton_released();

    void on_editTestimonialButton_2_released();

    void on_pushButton_4_clicked();

    void on_removeCustomer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Admin *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
    QString tempText;
    int tempId;
    bool tempApproved;
};

#endif // ADMIN_H
