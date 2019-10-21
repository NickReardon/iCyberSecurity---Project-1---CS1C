#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if(query.exec())
    {
        qDebug() << "foreign keys on";
    }
}

bool DbManager::reOpen()
{
    bool answer = false;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C://SQLite3/customerDB.db");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
        answer = true;
    }

    return answer;
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'people': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addPerson(const QString& name, const int& number)
{
    bool success = false;
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO products (name, id) VALUES (:name, :id)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":id", number);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}

bool DbManager::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM products WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void DbManager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM products");
    int idName = query.record().indexOf("name");
    int id = query.record().indexOf("id");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        int idNum = query.value(id).toInt();
        qDebug() << "===" << name << "/" << idNum;
    }
}

bool DbManager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM products WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllPersons()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM products");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}

bool DbManager::usernameExists(const QString& username) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM customers WHERE (username) = (:username)");
    checkQuery.bindValue(":username", username);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
            QString username = checkQuery.value("username").toString();
            qDebug() << username;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::nameExists(const QString &name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM customers WHERE (name) = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
            QString name = checkQuery.value("name").toString();
            qDebug() << name;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::emailExists(const QString &email) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT email FROM customers WHERE (email) = (:email)");
    checkQuery.bindValue(":email", email);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
            QString email = checkQuery.value("email").toString();
            qDebug() << email;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}


bool DbManager::CheckAdmin(const QString& username) const
{
    bool admin = false;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT admin FROM customers WHERE (username) = (:username)");
    checkQuery.bindValue(":username", username);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            admin = checkQuery.value("admin").toBool();
            qDebug() << admin;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }
    if(admin)
    {
        qDebug() << "Admin" << endl;
    }
    return admin;
}


QString DbManager::GetPassword(const QString& username) const
{
    QString password;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT password FROM customers WHERE (username) = (:username)");
    checkQuery.bindValue(":username", username);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            password = checkQuery.value("password").toString();
            qDebug() << password;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return password;
}



bool DbManager::updateAccount(const QString& username, const QString& password, const QString& name, const QString& address, const QString& city, const QString &email)
{
    bool success = false;

    QSqlQuery query;
    query.prepare("UPDATE customers SET (username, password, address, city, email) = (:un, :pw, :ad, :c, :em) WHERE (name) = (:name)");
    query.bindValue(":un", username);
    query.bindValue(":pw", password);
    query.bindValue(":ad", address);
    query.bindValue(":c", city);
    query.bindValue(":em", email);
    query.bindValue(":name", name);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "update customer failed: " << query.lastError();
    }

    return success;
}

bool DbManager::insertEmailR(const QString &email)
{
    bool success = false;

    QSqlQuery query("INSERT INTO customers (email) VALUES (?)");
    query.addBindValue(email);

    if(query.exec())
    {
        QSqlQuery query2;
        query2.prepare("UPDATE customers SET (received) = (:re) WHERE (email) = (:em)");
        query2.bindValue(":re", 1);
        query2.bindValue(":em", email);
        if(query2.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "update customer failed: " << query.lastError();
        }
    }
    else
    {
        qDebug() << "update customer failed: " << query.lastError();
    }

    return success;
}

bool DbManager::emailRecieved(const QString &email)
{
    bool success = false;

    QSqlQuery query;
    query.prepare("UPDATE customers SET (received) = (:re) WHERE (email) = (:em)");
    query.bindValue(":re", 1);
    query.bindValue(":em", email);

    if (query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "update pamphlet recieved failed: " << query.lastError();
    }

    return success;
}


bool DbManager::addAccount(const QString& username, const QString& password, const QString& name, const QString& address, const QString& city, const QString &email)
{
    bool success = false;
    if (!name.isEmpty())
    {

        QSqlQuery query("INSERT INTO Customers (username, password, name, address, city, email) VALUES (?,?,?,?,?,?)");
        query.addBindValue(username);
        query.addBindValue(password);
        query.addBindValue(name);
        query.addBindValue(address);
        query.addBindValue(city);
        query.addBindValue(email);

        if(query.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << query.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}

bool DbManager::removeCustomer(const QString &username)
{
    bool success = false;

    if (usernameExists(username))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM customers WHERE (username) = (:un)");
        queryDelete.bindValue(":un", username);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
        qDebug() << username;
    }

    return success;
}


bool DbManager::makePurchase(const QString &username, const int item1Count, const int item2Count, const int item3Count, const double total)
{

    bool success = false;
    QDateTime purchaseDate = QDateTime::currentDateTime();
    QSqlQuery query("INSERT INTO purchases (username, tier1, tier2, tier3, total, datetime) VALUES (?,?,?,?,?,?)");
    query.addBindValue(username);
    query.addBindValue(item1Count);
    query.addBindValue(item2Count);
    query.addBindValue(item3Count);
    query.addBindValue(total);
    query.addBindValue(purchaseDate);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add purchase failed: " << query.lastError();
    }


    return success;
}

bool DbManager::submitTestimonials(const QString &text, const QString &username)
{

    bool success = false;
    QString name;

    QSqlQuery query;
    query.prepare("SELECT name FROM customers WHERE (username) = (:username)");
    query.bindValue(":username", username);

    if (query.exec())
    {
        if (query.next())
        {
            name = query.value("name").toString();
            qDebug() << name;
        }
    }

    QDate date = QDate::currentDate();
    query.prepare("INSERT INTO testimonials (testimonial, username, name, date) VALUES (?,?,?,?)");
    query.addBindValue(text);
    query.addBindValue(username);
    query.addBindValue(name);
    query.addBindValue(date);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add testimonials: " << query.lastError();
    }


    return success;



}

bool DbManager::updateTestimonial(const QString &text, const bool approved, const int id)
{
    bool success = false;
    QString name;

    QSqlQuery query;
    query.prepare("UPDATE testimonials SET (testimonial, approved) = ( :testimonials , :approved ) WHERE (id) = (:id)");
    query.bindValue(":testimonials", text);
    query.bindValue(":approved", approved);
    query.bindValue(":id", id);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "update testimonials: " << query.lastError();
    }


    return success;
}

void editButton(const QString &username)
{
    bool success = false;

    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM customers WHERE username = (:un)");
    fetch.bindValue(":un", username);
    success = fetch.exec();
    //username, password, name, address, city, email
    if(success)
    {
        int iUsername = fetch.record().indexOf("username");
        int iPass = fetch.record().indexOf("password");
        int iName = fetch.record().indexOf("name");
        int iAddress = fetch.record().indexOf("address");
        int iCity = fetch.record().indexOf("city");
        int iEmail = fetch.record().indexOf("email");

        //ui->uBox->text(), ui->pBox->text(), ui->nBox->text(), ui->fBox->text(), ui->mBox->text(), ui->eBox->text()
    }
}

bool DbManager::removeTestimonial(const int id)
{
    bool success = false;

    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM testimonials WHERE id = (:id)");
    queryDelete.bindValue(":id", id);
    success = queryDelete.exec();

    if(!success)
    {
        qDebug() << "remove testimonial failed: " << queryDelete.lastError();
    }


return success;

}
