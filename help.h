#ifndef HELP_H
#define HELP_H

#include <QDialog>

/**
 * \class Help
 *
 * \brief Help class
 *
 * Help is the class used for
 * creating the UI that is used when clicking
 * the "Help" option on the program.
 */
namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Overloaded Constructor
     *
     * Constructor sets up "Help" page within the program
     * @param *parent which opens up the "Help" option with text that will guide the user through the program
     */
    explicit Help(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     *
     * Close Help UI
     */
    ~Help();

private:
    Ui::Help *ui;
};

#endif // HELP_H
