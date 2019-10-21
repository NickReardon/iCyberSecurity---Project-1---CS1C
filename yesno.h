#ifndef YESNO_H
#define YESNO_H

#include <QDialog>


/**
 * \class YesNo
 *
 * \brief YesNo class
 *
 * YesNo Class sets up the UI for
 * the "Are You Sure" box that is enabled
 * after doing certain tasks. This is enabled when
 * there is changes done to customer data or submitting
 * testimonials
 */
namespace Ui {
class YesNo;
}

class YesNo : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the YesNo page
     * @param *parent which points to the answer that the user chooses
     */
    explicit YesNo(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Closes YesNo UI
     */
    ~YesNo();

    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the products page
     * @param *parent which points to the answer that the user chooses, returnAnswer which is the answer clicked on by the user
     */
    YesNo(QWidget *parent, bool &returnAnswer);

    /**
     * @brief checks to see what the user decides (Yes or No)
     * @return true - will enable any editing or task that was asked, false - will not allow for changes to data
     */
    bool getData();
private slots:

    /**
     * @brief button for clicking no
     * @return nothing
     */
    void on_pushButton_2_released();

    /**
     * @brief button for clicking yes
     * @return nothing
     */
    void on_pushButton_released();

private:
    Ui::YesNo *ui;
    bool answer = false;
};

#endif // YESNO_H
