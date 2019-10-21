#ifndef ENTERTESTIMONIAL_H
#define ENTERTESTIMONIAL_H

#include <QDialog>
#include "dbmanager.h"

/**
 * \class EnterTestimonial
 *
 * \brief EnterTestimonial class
 *
 * EnterTestimonial is the class used for
 * creating the UI that is used for customers
 * to be able to leave testimonials based on their
 * experience with the products.
 */
namespace Ui {
class EnterTestimonial;
}

class EnterTestimonial : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the testimonial
     * @param *parent which points to the testimonial after it is made
     */
    explicit EnterTestimonial(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Close EnterTestimonial UI
     */
    ~EnterTestimonial();

    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up the testimonial
     * @param *parent which points to the testimonial after it is made, and username of the user previously entered
     */
    EnterTestimonial(QWidget *parent, QString &username);
private slots:

    /**
     * @brief submits testimonial
     * @return nothing
     */
    void on_submitButton_released();

    /**
     * @brief cancels testimonial
     * @return nothing
     */
    void on_cancelButton_released();

private:
    Ui::EnterTestimonial *ui;
    QString username;
    DbManager dbManager = DbManager("C://SQLite3/customerDB.db");
};

#endif // ENTERTESTIMONIAL_H
