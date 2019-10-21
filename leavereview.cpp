#include "leavereview.h"
#include "ui_leavereview.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up leaveReview page within the program
 * @param *parent which opens up the leaveReview page within the program
 */
leaveReview::leaveReview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaveReview)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor
 *
 * Close leaveReview UI
 */
leaveReview::~leaveReview()
{
    delete ui;
}

/**
 * @brief gets data of whether or not the user wants to leave a review or not
 * @return true - will prompt user for review, false - will return them to main login page
 */
bool leaveReview::getData()
{
    qDebug() << "getData()";
    return answer;
}

/**
 * @brief yes button for leaving a review
 * @return nothing
 */
void leaveReview::on_pushButton_clicked()
{
    answer = true;
    hide();
}

/**
 * @brief yes button for leaving a review
 * @return nothing
 */
void leaveReview::on_pushButton_2_clicked()
{
    answer = false;
    hide();
}
