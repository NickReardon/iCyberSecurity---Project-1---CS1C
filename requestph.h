#ifndef REQUESTPH_H
#define REQUESTPH_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class requestPh;
}

class requestPh : public QDialog
{
    Q_OBJECT

public:
    explicit requestPh(QWidget *parent = nullptr);
    ~requestPh();

private slots:
    void on_cancelButton_clicked();

    void on_requestPButton_clicked();

private:
    Ui::requestPh *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // REQUESTPH_H
