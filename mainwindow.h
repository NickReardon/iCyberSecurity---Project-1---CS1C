#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "admin.h"
#include "products.h"
#include "createaccount.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonLogin_released();

    void on_buttonClear_released();

    void on_buttonCreate_clicked();

private:
    Ui::MainWindow *ui;
    DbManager dbManager = DbManager("C:\\SQLite3\\customerDB.db");

};

#endif // MAINWINDOW_H
