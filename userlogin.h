#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>

namespace Ui {
class userLogin;
}

class userLogin : public QDialog
{
    Q_OBJECT

public:
    explicit userLogin(QWidget *parent = nullptr);
    ~userLogin();

private:
    Ui::userLogin *ui;
};

#endif // USERLOGIN_H