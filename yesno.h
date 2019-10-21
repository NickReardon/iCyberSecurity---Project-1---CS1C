#ifndef YESNO_H
#define YESNO_H

#include <QDialog>

namespace Ui {
class YesNo;
}

class YesNo : public QDialog
{
    Q_OBJECT

public:
    explicit YesNo(QWidget *parent = nullptr);
    ~YesNo();

    YesNo(QWidget *parent, bool &returnAnswer);
    bool getData();
private slots:
    void on_pushButton_2_released();

    void on_pushButton_released();

private:
    Ui::YesNo *ui;
    bool answer = false;
};

#endif // YESNO_H
