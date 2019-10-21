#include "entertestimonial.h"
#include "ui_entertestimonial.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the testimonial
 * @param *parent which points to the testimonial after it is made
 */
EnterTestimonial::EnterTestimonial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterTestimonial)
{
    ui->setupUi(this);
}

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the testimonial
 * @param *parent which points to the testimonial after it is made, and username of the user previously entered
 */
EnterTestimonial::EnterTestimonial(QWidget *parent, QString &p_username) :
    QDialog(parent),
    ui(new Ui::EnterTestimonial)
{
    ui->setupUi(this);
    username = p_username;
}

/**
 * @brief Destructor
 *
 * Close EnterTestimonial UI
 */
EnterTestimonial::~EnterTestimonial()
{
    delete ui;
}

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the testimonial
 * @param *parent which points to the testimonial after it is made, and username of the user previously entered
 */
void EnterTestimonial::on_submitButton_released()
{
    QString text = ui->TestimonialTextEdit->toPlainText();
    if(text != "")
    {
        dbManager.submitTestimonials(text, username);
        accept();
    }
}

/**
 * @brief cancels testimonial
 * @return nothing
 */
void EnterTestimonial::on_cancelButton_released()
{
    accept();
}
