#ifndef LEAVEREVIEW_H
#define LEAVEREVIEW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class leaveReview;
}

class leaveReview : public QDialog
{
    Q_OBJECT

public:
    explicit leaveReview(QWidget *parent = nullptr);
    ~leaveReview();

    leaveReview(QWidget *parent, bool &returnAnswer);

     bool getData();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::leaveReview *ui;
    bool answer = false;
};

#endif // LEAVEREVIEW_H
