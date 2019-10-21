#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_tableView_2_viewportEntered()
{
    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM customers");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_2->setModel(modal);
}

void Admin::on_pushButton_4_clicked()
{
    /*
    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM customers");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_2->setModel(modal);
    */
}
