#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "admin.h"
#include "products.h"
#include "createaccount.h"

/**
 * \class MainWindow
 *
 * \brief MainWindow class
 *
 * MainWindow is the class used for
 * creating the UI that is seen at the main
 * page of thw website. There are many options
 * including those of making an account and also
 * reading the about us and contact us page within
 * the page as well.
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the MainWindow UI
     * @param *parent which points to the account after it is made
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Closes MainWindow UI
     */
    ~MainWindow();

private slots:

    /**
     * @brief button for loging in
     * @return nothing
     */
    void on_buttonLogin_released();

    /**
     * @brief button for clearing fields for logging in
     * @return nothing
     */
    void on_buttonClear_released();

    /**
     * @brief button for creating an account
     * @return nothing
     */
    void on_buttonCreate_clicked();

    /**
     * @brief line edit used for editing username
     * @return nothing
     */
    void on_usernameLineEdit_returnPressed();

    /**
     * @brief line edit used for editing password
     * @return nothing
     */
    void on_passwordLineEdit_returnPressed();

    /**
     * @brief request pamphlet button
     * @return nothing
     */
    void on_requestButton_clicked();

    /**
     * @brief help button
     * @return nothing
     */
    void on_helpButton_released();

private:
    Ui::MainWindow *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // MAINWINDOW_H
