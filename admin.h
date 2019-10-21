#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "dbmanager.h"
#include <QDebug>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QDialog *parent = nullptr);
    ~Admin();

private slots:
    void on_tableView_2_viewportEntered();

    void on_pushButton_4_clicked();

private:
    Ui::Admin *ui;
    DbManager dbManager = DbManager("C:\\SQLite3\\customerDB.db");
};

#endif // ADMIN_H
