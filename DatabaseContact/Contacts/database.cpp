#include "database.h"

Database::Database()
{

}

void Database::connectionToDataBase(QSqlDatabase *db, QString filePath)
{
    *db = QSqlDatabase::addDatabase("SQLITE");
    if(db->lastError().isValid())
    {
        qCritical() << "addDatabase" << db->lastError().text();
    }

    // Setup de db file name and open it
    QString dbPath = filePath + "/testdb.db";
//    qDebug() << "dbPath" << dbPath;
    if(!db->open())
    {
        qCritical() << "unuable to open db" << db->lastError().text() << dbPath;
    }

    // create a table
    QString tblContactsCreate = "CREATE TABLE IF NOT EXISTS contacts ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT," // transform to string...
                                  "GUID STRING"
                                  "firstname STRING"
                                  "lastname STRING"
                                  "email STRING"
                                  "tel STRING"
                                  "category STRING"
                                  "city STRING"
                                  "birth_day STRING"
                                  "country STRING"
                                  "list STRING "
                                  "company STRING";
    QSqlQuery querry;
    querry.exec(tblContactsCreate);

    if(querry.lastError().isValid())
    {
        qWarning() << "CREATE TABLE" << querry.lastError().text();
    }



}
