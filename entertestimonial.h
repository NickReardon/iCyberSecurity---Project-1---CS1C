#ifndef ENTERTESTIMONIAL_H
#define ENTERTESTIMONIAL_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class EnterTestimonial;
}

class EnterTestimonial : public QDialog
{
    Q_OBJECT

public:
    explicit EnterTestimonial(QWidget *parent = nullptr);
    ~EnterTestimonial();

    EnterTestimonial(QWidget *parent, QString &username);
private slots:
    void on_submitButton_released();

    void on_cancelButton_released();

private:
    Ui::EnterTestimonial *ui;
    QString username;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // ENTERTESTIMONIAL_H
