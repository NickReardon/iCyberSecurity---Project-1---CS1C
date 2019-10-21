#include "yesno.h"
#include "ui_yesno.h"
#include "QDebug"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the YesNo page
 * @param *parent which points to the answer that the user chooses
 */
YesNo::YesNo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YesNo)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor
 *
 * Closes YesNo UI
 */
YesNo::~YesNo()
{

}

/**
 * @brief checks to see what the user decides (Yes or No)
 * @return true - will enable any editing or task that was asked, false - will not allow for changes to data
 */
bool YesNo::getData()
{
    qDebug() << "getData()";
    return answer;
}

/**
 * @brief button for clicking yes
 * @return nothing
 */
void YesNo::on_pushButton_released()
{
    answer = true;
    hide();
}

/**
 * @brief button for clicking no
 * @return nothing
 */
void YesNo::on_pushButton_2_released()
{
    answer = false;
    hide();
}
