#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QString>
#include <QDateTime>

/**
 * \class DbManager
 *
 * \brief SQL Database Manager class
 *
 * DbManager sets up the connection with SQL database
 * and performs some basics queries. The class requires
 * existing SQL database. You can create it with sqlite:
 * 1. $ sqlite3 people.db
 * 2. sqilte> CREATE TABLE people(ids integer primary key, name text);
 * 3. sqlite> .quit
 */
class DbManager
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    DbManager(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~DbManager();

    bool isOpen() const;
    bool reOpen();

    /**
     * @brief Creates a new 'people' table if it doesn't already exist
     * @return true - 'people' table created successfully, false - table not created
     */
    bool createTable();

    /**
     * @brief Add person data to db
     * @param name - name of person to add
     * @return true - person added successfully, false - person not added
     */
    bool addPerson(const QString& name, const int& number);

    /**
     * @brief Remove person data from db
     * @param name - name of person to remove.
     * @return true - person removed successfully, false - person not removed
     */
    bool removePerson(const QString& name);

    /**
     * @brief Check if person of name "name" exists in db
     * @param name - name of person to check.
     * @return true - person exists, false - person does not exist
     */
    bool personExists(const QString& name) const;

    /**
     * @brief Print names of all persons in db
     */
    void printAllPersons() const;

    /**
     * @brief Remove all persons from db
     * @return true - all persons removed successfully, false - not removed
     */
    bool removeAllPersons();

    QString GetPassword(const QString &username) const;

    bool updateAccount(const QString &username, const QString &password, const QString &name, const QString &address, const QString &city, const QString &email);

    bool CheckAdmin(const QString &username) const;

    bool usernameExists(const QString &name) const;

    bool nameExists(const QString &name) const;

    bool emailExists(const QString &email) const;

    bool addAccount(const QString &username, const QString &password, const QString &name, const QString &address, const QString &city, const QString &email);

    bool emailRecieved(const QString &email);

    bool removeCustomer(const QString &username);

    bool insertEmailR(const QString &email);

    bool makePurchase(const QString &username, const int item1Count, const int item2Count, const int item3Count, const double total);

    bool submitTestimonials( const QString &text, const QString &username);

    bool updateTestimonial(const QString &text, const bool approved, const int id);

    void editButton(const QString &username);

    bool removeTestimonial(const int id);


private:
    QSqlDatabase m_db;
};


#endif // DBMANAGER_H
