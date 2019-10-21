#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

namespace Ui {
class createAccount;
}

class createAccount : public QDialog
{
    Q_OBJECT

public:
    explicit createAccount(QDialog *parent = nullptr);
    ~createAccount();

private slots:
    void on_completeRegButton_clicked();

    void on_backButton_clicked();

private:
    Ui::createAccount *ui;
    DbManager dbManager = DbManager("C:\\SQLite3\\customerDB.db");
};

#endif // CREATEACCOUNT_H
