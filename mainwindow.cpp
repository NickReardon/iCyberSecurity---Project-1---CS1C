#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createaccount.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonLogin_released()
{
    ui->invalidLabel->setText("");
        QString password;

        QString usernameInput = ui->usernameLineEdit->text();
        QString passwordInput = ui->passwordLineEdit->text();

        password = dbManager.GetPassword(usernameInput);
        if(passwordInput == password)
        {
            if(!dbManager.CheckAdmin(usernameInput))
            {
                ui->invalidLabel->setText("");

                hide();

                Products products(this, usernameInput);
                products.setModal(true);
                products.exec();

                show();
            }
            else
            {
                ui->invalidLabel->setText("");

                hide();

                Admin admin;
                admin.setModal(true);
                admin.exec();

                show();
            }
        }
        else
        {
            ui->invalidLabel->setText("Invalid username or password");
        }

}

void MainWindow::on_buttonClear_released()
{
    ui->passwordLineEdit->clear();
    ui->usernameLineEdit->clear();
}

void MainWindow::on_buttonCreate_clicked()
{
    createAccount window;

    window.setModal(true);
    window.exec();

    dbManager.reOpen();
}
