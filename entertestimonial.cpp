#include "entertestimonial.h"
#include "ui_entertestimonial.h"


EnterTestimonial::EnterTestimonial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterTestimonial)
{
    ui->setupUi(this);
}

EnterTestimonial::EnterTestimonial(QWidget *parent, QString &p_username) :
    QDialog(parent),
    ui(new Ui::EnterTestimonial)
{
    ui->setupUi(this);
    username = p_username;
}

EnterTestimonial::~EnterTestimonial()
{
    delete ui;
}

void EnterTestimonial::on_submitButton_released()
{
    QString text = ui->TestimonialTextEdit->toPlainText();
    if(text == "")
    {

    }
    else
    {
        dbManager.submitTestimonials(text, username);
        accept();
    }
}

void EnterTestimonial::on_cancelButton_released()
{
    accept();
}
