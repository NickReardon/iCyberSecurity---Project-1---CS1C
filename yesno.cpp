#include "yesno.h"
#include "ui_yesno.h"
#include "QDebug"

YesNo::YesNo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YesNo)
{
    ui->setupUi(this);
}


YesNo::~YesNo()
{

}

bool YesNo::getData()
{
    qDebug() << "getData()";
    return answer;
}

void YesNo::on_pushButton_released()
{
    answer = true;
    hide();
}

void YesNo::on_pushButton_2_released()
{
    answer = false;
    hide();
}
