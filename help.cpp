#include "help.h"
#include "ui_help.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up "Help" page within the program
 * @param *parent which opens up the "Help" option with text that will guide the user through the program
 */
Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor
 *
 * Close Help UI
 */
Help::~Help()
{
    delete ui;
}
