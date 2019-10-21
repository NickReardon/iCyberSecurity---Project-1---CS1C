#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requestph.h"
#include "help.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the MainWindow UI
 * @param *parent which points to the account after it is made
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor
 *
 * Closes MainWindow UI
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief button for loging in
 * @return nothing
 */
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

        dbManager.reOpen();
}


/**
 * @brief button for clearing fields for logging in
 * @return nothing
 */
void MainWindow::on_buttonClear_released()
{
    ui->passwordLineEdit->clear();
    ui->usernameLineEdit->clear();
}

/**
 * @brief button for creating an account
 * @return nothing
 */
void MainWindow::on_buttonCreate_clicked()
{
    createAccount window;

    window.setModal(true);
    window.exec();

    dbManager.reOpen();
}

/**
 * @brief line edit used for editing username
 * @return nothing
 */
void MainWindow::on_usernameLineEdit_returnPressed()
{
    on_buttonLogin_released();
}

/**
 * @brief line edit used for editing password
 * @return nothing
 */
void MainWindow::on_passwordLineEdit_returnPressed()
{
    on_buttonLogin_released();
}

/**
 * @brief request pamphlet button
 * @return nothing
 */
void MainWindow::on_requestButton_clicked()
{
    requestPh window3;

    window3.setModal(true);
    window3.exec();

    dbManager.reOpen();
}

/**
 * @brief help button
 * @return nothing
 */
void MainWindow::on_helpButton_released()
{
    Help help;

    help.setModal(true);
    help.exec();

    dbManager.reOpen();
}
