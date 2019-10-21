#include "mainwindow.h"
#include "products.h"
#include "ui_products.h"
#include "dbmanager.h"

static const QString path = "C://Data//products.db";


Products::Products(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);
}

Products::Products(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);
    currentUser = username;
    ui->nameDisplayLabel->setText(currentUser);

}

Products::~Products()
{
    delete ui;
}


void Products::on_pushButton_clicked()
{
    DbManager db(path);

    db.addPerson("Common", 111);
}

void Products::on_pushButton_2_clicked()
{
    DbManager db(path);

    db.addPerson("Premium", 222);
}

void Products::on_pushButton_3_clicked()
{
    DbManager db(path);

    db.addPerson("Platinum", 333);
}

void Products::on_pushButton_4_clicked()
{
    DbManager db(path);

    db.removePerson("Common");
}

void Products::on_pushButton_5_clicked()
{
    DbManager db(path);

    db.removePerson("Premium");
}

void Products::on_pushButton_6_clicked()
{
    DbManager db(path);

    db.removePerson("Platinum");
}

void Products::on_pushButton_7_clicked()
{
    DbManager db(path);

    db.removeAllPersons();
}

void Products::on_pushButton_8_clicked()
{
    DbManager db(path);

    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM Products");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

}
