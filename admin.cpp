#include "admin.h"
#include "ui_admin.h"
#include "yesno.h"

Admin::Admin(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    updateNameTableView();
    updateTestimonialTableView();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM Customers ORDER BY name ASC");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}

void Admin::on_pushButton_3_clicked()
{
    createAccount window2;
    window2.setModal(true);
    window2.exec();

    dbManager.reOpen();

    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM Customers");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}

void Admin::updateNameTableView()
{

    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT name FROM customers WHERE admin = 0");

    qry->exec();
    model->setQuery(*qry);

    ui->nameTableView->setModel(model);
    ui->nameTableView->setColumnWidth(0, 195);
}

void Admin::on_nameTableView_clicked(const QModelIndex &index)
{
    QVariant value=index.sibling(index.row(),index.column()).data();
    QString name = QVariant(value).toString();


    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM customers WHERE (name) = (:name)");
    checkQuery.bindValue(":name", name);

    QString username;

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            username = checkQuery.value("username").toString();
            qDebug() << username;
        }
    }
    else
    {
        qDebug() << "username exists failed: " << checkQuery.lastError();
    }

    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT total, tier1, tier2, tier3, datetime FROM purchases WHERE username = (:username) ORDER BY datetime DESC");
    qry->bindValue(":username", username);

    if (!qry->exec())
    {
        qDebug() << "username exists failed: " << checkQuery.lastError();
    }

    model->setQuery(*qry);

    ui->namePurchaseTableView->setModel(model);
    ui->namePurchaseTableView->setColumnWidth(0, 60);
    ui->namePurchaseTableView->setColumnWidth(1, 30);
    ui->namePurchaseTableView->setColumnWidth(2, 30);
    ui->namePurchaseTableView->setColumnWidth(3, 30);
    ui->namePurchaseTableView->setColumnWidth(4, 140);
}

void Admin::updateTestimonialTableView()
{

    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT name, date, approved, testimonial, id FROM testimonials");

    qry->exec();
    model->setQuery(*qry);

    ui->nameTableView->setModel(model);
    ui->testimonialTableView->setModel(model);
    ui->testimonialTableView->setColumnWidth(0, 140);
    ui->testimonialTableView->setColumnWidth(1, 70);
    ui->testimonialTableView->setColumnWidth(2, 60);
    ui->testimonialTableView->hideColumn(3);
    ui->testimonialTableView->hideColumn(4);

    ui->approvedComboBox->setEnabled(false);
    ui->deleteTestimonialButton->setEnabled(true);
    ui->updateTestimonialButton->setEnabled(false);
    ui->updateTestimonialButton->setEnabled(true);
    ui->editTestimonialButton->setEnabled(true);
    ui->editTestimonialButton_2->setEnabled(false);

}

void Admin::on_deleteTestimonialButton_released()
{
    YesNo yesno;
    bool confirm = false;

    yesno.setModal(true);
    yesno.exec();
    confirm=yesno.getData();

    if(confirm)
    {
        dbManager.removeTestimonial(tempId);

        updateTestimonialTableView();
        ui->testimonialsLabel->setText("Deleted");
    }
}

void Admin::on_updateTestimonialButton_released()
{
    YesNo yesno;
    bool confirm = false;

    yesno.setModal(true);
    yesno.exec();
    confirm=yesno.getData();

    if(confirm)
    {
        dbManager.updateTestimonial(ui->testimonialTextEdit->toPlainText(),
                                    ui->approvedComboBox->currentIndex(),
                                    tempId);

        updateTestimonialTableView();
        ui->testimonialsLabel->setText("Updated");
    }
}

void Admin::on_testimonialTableView_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString text = index.sibling(row, 3).data().toString();
    tempText = text;

    bool approved = index.sibling(row, 2).data().toBool();
    tempApproved = approved;

    tempId = index.sibling(row, 4).data().toInt();

    ui->approvedComboBox->setCurrentIndex(approved);
    ui->testimonialTextEdit->setText(text);

}

void Admin::on_editTestimonialButton_released()
{
    ui->testimonialTextEdit->setReadOnly(false);

    ui->testimonialsLabel->setText("Edit Mode");


    ui->approvedComboBox->setEnabled(true);
    ui->deleteTestimonialButton->setEnabled(true);
    ui->updateTestimonialButton->setEnabled(true);
    ui->editTestimonialButton_2->setEnabled(true);
    ui->editTestimonialButton->setEnabled(false);
}

void Admin::on_editTestimonialButton_2_released()
{
    ui->testimonialTextEdit->setText(tempText);
    ui->testimonialTextEdit->setReadOnly(true);

    ui->approvedComboBox->setCurrentIndex(tempApproved);

    ui->testimonialsLabel->setText("Reset");

    ui->approvedComboBox->setEnabled(false);
    ui->deleteTestimonialButton->setEnabled(true);
    ui->updateTestimonialButton->setEnabled(false);
    ui->editTestimonialButton_2->setEnabled(false);
    ui->editTestimonialButton->setEnabled(true);

}

void Admin::on_pushButton_4_clicked()
{
    updateAccount window;

    window.setModal(true);
    window.exec();

    dbManager.reOpen();

    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM Customers");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}

void Admin::on_removeCustomer_clicked()
{
    YesNo yesno;
    bool confirm = false;

    if (dbManager.usernameExists(ui->uBox3->text()))
    {
        yesno.setModal(true);
        yesno.exec();
        confirm=yesno.getData();

        if(confirm)
        {
            dbManager.removeCustomer(ui->uBox3->text());
            ui->uBox3->setText("");
        }
    }
    else
    {
        ui->uBox3->setText("");
        ui->uBox3->setPlaceholderText("Username Doesn't EXIST!");
    }


    dbManager.reOpen();

    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM Customers");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}

void Admin::on_pushButton_2_clicked()
{
    QSqlQueryModel* modal=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM customers WHERE value = 'key'");

    if (qry->exec())
    {
        qDebug() << "WORKS!";
    }
    else
    {
        qDebug() << "FAILED!";
    }

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}
