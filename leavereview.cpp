#include "leavereview.h"
#include "ui_leavereview.h"

leaveReview::leaveReview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaveReview)
{
    ui->setupUi(this);
}

leaveReview::~leaveReview()
{
    delete ui;
}


bool leaveReview::getData()
{
    qDebug() << "getData()";
    return answer;
}

void leaveReview::on_pushButton_clicked()
{
    answer = true;
    hide();
}

void leaveReview::on_pushButton_2_clicked()
{
    answer = false;
    hide();
}
