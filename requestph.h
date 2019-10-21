#ifndef REQUESTPH_H
#define REQUESTPH_H

#include <QDialog>
#include "dbmanager.h"

/**
 * \class requestPh
 *
 * \brief requestPh class
 *
 * requestPh is the class used for
 * creating the UI that is seen when a
 * user request a pamphlet.
 */
namespace Ui {
class requestPh;
}

class requestPh : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the requestPh page
     * @param *parent which points to which email submitted by the user for requesting a pamphlet
     */
    explicit requestPh(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Closes requestPh UI
     */
    ~requestPh();

private slots:
    /**
     * @brief cancel button for requesting pamphlet
     * @return nothing
     */
    void on_cancelButton_clicked();

    /**
     * @brief request button for requesting pamphlet
     * @return nothing
     */
    void on_requestPButton_clicked();

private:
    Ui::requestPh *ui;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // REQUESTPH_H
