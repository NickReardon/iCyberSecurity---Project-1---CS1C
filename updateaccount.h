#ifndef UPDATEACCOUNT_H
#define UPDATEACCOUNT_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class updateAccount;
}

class updateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit updateAccount(QWidget *parent = nullptr);
    ~updateAccount();
private slots:
    void on_backButton_clicked();

    void on_updateRegButton_clicked();

private:
    Ui::updateAccount *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // UPDATEACCOUNT_H
