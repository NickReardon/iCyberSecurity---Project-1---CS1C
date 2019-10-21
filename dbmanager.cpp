#include <DbManager.h>
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
}

bool DbManager::reOpen()
{
    bool answer = false;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\SQLite3\\customerDB.db");

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
    query.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT);");

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



bool DbManager::updateAccount(const QString& username, const QString& password, const QString& name, const QString& address, const QString& city )
{
    bool success = false;
    if (!name.isEmpty())
    {
        QSqlQuery query("UPDATE customers (username, password, name, address, city) VALUES (?,?,?,?,?)");
        query.addBindValue(username);
        query.addBindValue(password);
        query.addBindValue(name);
        query.addBindValue(address);
        query.addBindValue(city);

        if(query.exec())
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
        qDebug() << "update customer failed: name cannot be empty";
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
