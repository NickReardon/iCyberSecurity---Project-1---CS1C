#include "mainwindow.h"
#include "products.h"
#include "ui_products.h"
#include "dbmanager.h"
#include <math.h>
#include "yesno.h"
#include "entertestimonial.h"
#include "leavereview.h"

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the products page
 * @param *parent which points to the product(s) that is chose
 */
Products::Products(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);
}

/**
 * @brief Overloaded Constructor
 *
 * Constructor sets up the products page
 * @param *parent which points to the products after they have selected it, and username of the user
 */
Products::Products(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::Products)
{
    ui->setupUi(this);
    currentUser = username;
    ui->nameDisplayLabel->setText(currentUser);
    updateCart();
    updateTestimonialsList();
}

/**
 * @brief Destructor
 *
 * Closes Products UI
 */
Products::~Products()
{
    delete ui;
}

/**
 * @brief updates the cart with selected products
 * @return nothing
 */
void Products::updateCart()
{
    double item1Total = item1Cost * item1Count;
    double item2Total = item2Cost * item2Count;
    double item3Total = item3Cost * item3Count;
    int size;

    if(item1Count > 0)
    {
        ui->item1RemoveButton->setEnabled(true);
    }
    else
    {
        ui->item1RemoveButton->setEnabled(false);
    }

    if(item2Count > 0)
    {
        ui->item2RemoveButton->setEnabled(true);
    }
    else
    {
        ui->item2RemoveButton->setEnabled(false);
    }

    if(item3Count > 0)
    {
        ui->item3RemoveButton->setEnabled(true);
    }
    else
    {
        ui->item3RemoveButton->setEnabled(false);
    }


    QString out;
    out = QString("<br><b>Cart</b></br>"
                  "<br>-------------------------------------------</br>"
                  );
    if((item1Count + item2Count + item3Count) > 0)
    {
        ui->emptyCartButton->setEnabled(true);
        ui->checkOutButton->setEnabled(true);
        out += QString("<br>""Product &nbsp; &ensp;" "&nbsp;| &nbsp;"
                       "Qty." "&nbsp;&nbsp;| &nbsp;&nbsp;"
                       "Cost" "&nbsp;&nbsp;| &nbsp;&nbsp;"
                       "Total" "&nbsp;&nbsp;&nbsp;|"
                       "</br>"
                       "<br>-------------------------------------------</br>"
                       );
    }
    else
    {
        ui->emptyCartButton->setEnabled(false);
        ui->checkOutButton->setEnabled(false);
    }
    //Item 1
    {
        if(item1Count > 0)
        {
            //Product
            out += QString("<br>Common &nbsp; &nbsp;" "&nbsp;| &nbsp;&nbsp;");

            size = log10(item1Count) + 1;

            //Quantity
            if(size > 1)
            {
                out += QString::number(item1Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }
            else
            {
                out += QString("&nbsp;") + QString::number(item1Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }

            //Cost
            size = log10(item1Cost) + 1;
            if(size > 2)
            {
                out += "$&nbsp;" + QString::number(item1Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }
            else
            {
                out += "$&nbsp;&nbsp;" + QString::number(item1Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }

            //Total
            size = log10(item1Total) + 1;
            if(size > 2)
            {
                if(size > 3)
                {
                    out += "$&nbsp;" + QString::number(item1Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
                else
                {

                    out += "$&nbsp;&nbsp;" + QString::number(item1Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
            }
            else
            {
                out += "$&nbsp;&nbsp;&nbsp;" + QString::number(item1Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");

            }


        }
    }//End Item 1


    //Item 2
    {
        if(item2Count > 0)
        {
            //Product
            out += QString("<br>Premium &nbsp;&ensp;" "&nbsp;| &nbsp;&nbsp;");

            int size = log10(item2Count) + 1;

            //Quantity
            if(size > 1)
            {
                out += QString::number(item2Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }
            else
            {
                out += QString("&nbsp;") + QString::number(item2Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }

            //Cost
            size = log10(item2Cost) + 1;
            if(size > 2)
            {
                out += "$&nbsp;" + QString::number(item2Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }
            else
            {
                out += "$&nbsp;&nbsp;" + QString::number(item2Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }

            //Total
            size = log10(item2Total) + 1;
            if(size > 2)
            {
                if(size > 3)
                {
                    out += "$&nbsp;" + QString::number(item2Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
                else
                {

                    out += "$&nbsp;&nbsp;" + QString::number(item2Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
            }
            else
            {
                out += "$&nbsp;&nbsp;&nbsp;" + QString::number(item2Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");

            }

        }
    }//End Item 2


    //Item 3
    {
        if(item3Count > 0)
        {
            //Product
            out += QString("<br>Platinum&nbsp;&ensp;" "&nbsp;| &nbsp;&nbsp;");

            int size = log10(item3Count) + 1;

            //Quantity
            if(size > 1)
            {
                out += QString::number(item3Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }
            else
            {
                out += QString("&nbsp;") + QString::number(item3Count) + QString("&nbsp;&nbsp;&nbsp;| &ensp;");
            }

            //Cost
            size = log10(item2Cost) + 1;
            if(size > 2)
            {
                out += "$&nbsp;" + QString::number(item3Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }
            else
            {
                out += "$&nbsp;&nbsp;" + QString::number(item3Cost) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
            }

            //Total
            size = log10(item3Total) + 1;
            if(size > 2)
            {
                if(size > 3)
                {
                    out += "$&nbsp;" + QString::number(item3Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
                else
                {

                    out += "$&nbsp;&nbsp;" + QString::number(item3Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");
                }
            }
            else
            {
                out += "$&nbsp;&nbsp;&nbsp;" + QString::number(item3Total) + QString("&nbsp;&nbsp;&nbsp;| &nbsp;");

            }

        }
    }//End Item 3




    if((item1Count + item2Count + item3Count) > 0)
    {
        out += QString("<br>-------------------------------------------</br>"
                       "<br>Subtotal: ");

        double subtotal = item1Total + item2Total + item3Total;
        size = log10(subtotal) + 1;
        switch(size)
        {
            case 2: out += QString("$&nbsp;&nbsp;&nbsp;&nbsp;");
            break;

            case 3: out += QString("$&nbsp;&nbsp;&nbsp;");
            break;

            case 4: out += QString("$&nbsp;&nbsp;");
            break;

            case 5: out += QString("$&nbsp;");
            break;
        }
        out += QString::number(subtotal, 'f', 2) + QString("</br>");


        out += QString("<br>Tax: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
        double tax = QString::number(subtotal * .0775, 'f', 2).toDouble();
        size = log10(tax) + 1;
        switch(size)
        {
            case 1: out += QString("$&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
            break;

            case 2: out += QString("$&nbsp;&nbsp;&nbsp;&nbsp;");
            break;

            case 3: out += QString("$&nbsp;&nbsp;&nbsp;");
            break;

            case 4: out += QString("$&nbsp;&nbsp;");
            break;

            case 5: out += QString("$&nbsp;");
            break;

            case 6: out += QString("$");
            break;
        }
        out += QString::number(tax, 'f', 2) + QString("</br>");

        out += QString("<br>Total: &nbsp;&nbsp;&nbsp;");
        cartTotal = QString::number(subtotal + tax, 'f', 2).toDouble();
        size = log10(cartTotal) + 1;
        switch(size)
        {
            case 1: out += QString("$&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
            break;

            case 2: out += QString("$&nbsp;&nbsp;&nbsp;&nbsp;");
            break;

            case 3: out += QString("$&nbsp;&nbsp;&nbsp;");
            break;

            case 4: out += QString("$&nbsp;&nbsp;");
            break;

            case 5: out += QString("$&nbsp;");
            break;

            case 6: out += QString("$");
            break;
        }
        out += QString::number(cartTotal, 'f', 2) + QString("</br>");

    }

    if((item1Count + item2Count + item3Count) > 0)
    {
        ui->planPriceLabel->setText(QString("New customers recieve a one month free trial."
                       " After that, subscription costs $15/mo."));
    }
    else
    {
        ui->planPriceLabel->setText("");
    }

    ui->CartTextBrowser->setHtml(out);
}

/**
 * @brief button for adding common product
 * @return nothing
 */
void Products::on_item1AddButton_released()
{
    if(item1Count >= 0) item1Count++;
    updateCart();
}

/**
 * @brief button for removing common product
 * @return nothing
 */
void Products::on_item1RemoveButton_released()
{
    if(item1Count > 0) item1Count--;
    updateCart();
}

/**
 * @brief button for adding premium product
 * @return nothing
 */
void Products::on_item2AddButton_released()
{
    if(item2Count >= 0) item2Count++;
    updateCart();
}

/**
 * @brief button for removing premium product
 * @return nothing
 */
void Products::on_item2RemoveButton_released()
{
    if(item2Count > 0) item2Count--;
    updateCart();
}

/**
 * @brief button for adding platinum product
 * @return nothing
 */
void Products::on_item3AddButton_released()
{
    if(item3Count >= 0) item3Count++;
    updateCart();
}

/**
 * @brief button for removing platinum product
 * @return nothing
 */
void Products::on_item3RemoveButton_released()
{
    if(item3Count > 0) item3Count--;
    updateCart();
}

/**
 * @brief button for emptying cart
 * @return nothing
 */
void Products::on_emptyCartButton_released()
{
    item1Count = 0;
    item2Count = 0;
    item3Count = 0;
    updateCart();
}

/**
 * @brief button checking out cart
 * @return nothing
 */
void Products::on_checkOutButton_released()
{
    YesNo yesno;
    bool confirm = false;

    yesno.setModal(true);
    yesno.exec();
    confirm=yesno.getData();

    if(confirm)
    {
        dbManager.makePurchase(currentUser, item1Count, item2Count, item3Count, cartTotal);

        hide();

        leaveReview yesno2;
        bool confirm2 = false;

        yesno2.setModal(true);
        yesno2.exec();
        confirm2 = yesno2.getData();
        qDebug() << confirm2;
        if(confirm2)
        {

            EnterTestimonial testimonials(this, currentUser);
            testimonials.setModal(true);
            testimonials.exec();

            show();
        }
    }

}

/**
 * @brief updates the current list of testimonials
 * @return nothing
 */
void Products::updateTestimonialsList()
{
    QString text;
    QString name;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT testimonial, name FROM testimonials WHERE (approved) = (1)");

    if (checkQuery.exec())
    {
        while (checkQuery.next())
        {
            text = checkQuery.value("testimonial").toString();
            name = checkQuery.value("name").toString();
            ui->testimonialListWidget->addItem(QString("\n\"" + text + "\"\n\n - " + name + "\n"));
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }


}

void Products::on_pushButton_clicked()
{
    hide();
}
