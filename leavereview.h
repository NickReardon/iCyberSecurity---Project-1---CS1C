#ifndef LEAVEREVIEW_H
#define LEAVEREVIEW_H

#include <QDialog>
#include <QDebug>

/**
 * \class leaveReview
 *
 * \brief leaveReview class
 *
 * leaveReview is a class that makes
 * the UI used for leaving a review once
 * the user had already bought the product.
 */
namespace Ui {
class leaveReview;
}

class leaveReview : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up leaveReview page within the program
     * @param *parent which opens up the leaveReview page within the program
     */
    explicit leaveReview(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Close leaveReview UI
     */
    ~leaveReview();

    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up leaveReview page within the program
     * @param *parent which opens up the leaveReview page within the program, and returns the answer for the review
     */
    leaveReview(QWidget *parent, bool &returnAnswer);

    /**
     * @brief gets data of whether or not the user wants to leave a review or not
     * @return true - will prompt user for review, false - will return them to main login page
     */
     bool getData();
private slots:

     /**
      * @brief yes button for leaving a review
      * @return nothing
      */
    void on_pushButton_clicked();

    /**
     * @brief yes button for leaving a review
     * @return nothing
     */
    void on_pushButton_2_clicked();

private:
    Ui::leaveReview *ui;
    bool answer = false;
};

#endif // LEAVEREVIEW_H
