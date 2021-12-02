#include "database.h"
#include "contacts.h"


Database::Database()
{

}

//int Database::getCounter() const
//{
//    return counter;
//}

bool Database::connectionToDataBase(QSqlDatabase *db)
{
    Contacts contacts;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    if(db->lastError().isValid())
    {
        qCritical() << "addDatabase" << db->lastError().text();

    }

    // Setup de db file name and open it
    QString dbPath = contacts.getAppdataLocation() + "/contacts.db";
    db->setDatabaseName(contacts.getAppdataLocation());

    if(!db->open())
    {
        qCritical() << "Unable to open db" << db->lastError().text() << dbPath;

    }

    // Create a table
    QString tblContactsCreate = "CREATE TABLE IF NOT EXISTS contacts ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT," // transform to string...
                                  "GUID STRING,"
                                  "firstname STRING,"
                                  "lastname STRING,"
                                  "email STRING,"
                                  "tel INT," //STRING
                                  "category STRING,"
                                  "city STRING,"
                                  "birth_day DATE," //STRING
                                  "country STRING,"
                                  "list STRING,"
                                  "company STRING"
                                  ")";
    QSqlQuery querry;
    querry.exec(tblContactsCreate);

    if(querry.lastError().isValid())
    {
        qWarning() << "CREATE TABLE" << querry.lastError().text();
        return false;
    }
    else
    {
        return true;
    }
}

int Database::insertAllContactsInDataBase(QStringList contactList)
{
    QSqlQuery query;
    QStringList oneLineSplit;
    this->counter = 0;

    query.exec("pragma temp_store = memory");
    query.exec("PRAGMA synchronous = normal");
    query.exec("pragma mmap_size = 30000000000");
    query.exec("PRAGMA journal_mode = wal");

    QString sqlInsert = "INSERT INTO contacts (GUID, firstname, lastname, email, tel, category, city, birth_day,"
                        " country, list, company) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    for (int i = 0; i < contactList.size(); i++) {
        oneLineSplit = contactList[i].split(",");
        for (int j = 1; j < oneLineSplit.size(); j++) {
            query.bindValue(j, oneLineSplit[j]);
        }
        this->counter++;
    }

    query.exec(sqlInsert);

    if (query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
    }

    return this->counter;
}
