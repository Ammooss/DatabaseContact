#include "database.h"
#include "contacts.h"

Database::Database()
{

}

bool Database::connectionToDataBase(QSqlDatabase *db)
{

    // Initialisation de la base de donnees
    *db = QSqlDatabase::addDatabase("QSQLITE");
    if(db->lastError().isValid())
    {
        qCritical() << "addDatabase" << db->lastError().text();

    }

    // Creation du fichier de la base de donnees et ouverture de celui-ci
    QString dbPath = contacts.getAppdataLocation() + "/contacts.db";

    if (!QFile::exists(dbPath))
    {
        db->setDatabaseName(dbPath);
    }
    else
    {
        QFile::remove(dbPath);
        db->setDatabaseName(dbPath);
    }

    if(!db->open())
    {
        qCritical() << "Unable to open db" << db->lastError().text() << dbPath;

    }

    // Creation d'une table dans la base de donnees
    QSqlQuery query;
    QString tblContactsCreate = "CREATE TABLE IF NOT EXISTS contacts ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT," // transform to string...
                                  "GUID STRING,"
                                  "firstname STRING,"
                                  "lastname STRING,"
                                  "email STRING,"
                                  "tel STRING,"
                                  "category STRING,"
                                  "city STRING,"
                                  "birth_day STRING,"
                                  "country STRING,"
                                  "list STRING,"
                                  "company STRING"
                                  ")";
    query.exec(tblContactsCreate);

    if(query.lastError().isValid())
    {
        qWarning() << "CREATE TABLE" << query.lastError().text();
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

    // Requete d'insertion
    query.prepare("INSERT INTO contacts (GUID, firstname, lastname, email, tel, category, city, birth_day,"
                        " country, list, company) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");


    // Preparation des donnes a inserer dans la base de donnees
    for (int i = 0; i < contactList.size(); i++) {
        oneLineSplit = contactList[i].split(",");
        for (int j = 1; j < oneLineSplit.size(); j++) {
            oneLineSplit[11].replace("\r\n", "");
            query.bindValue(j - 1, oneLineSplit[j]);
        }
        // Execution de l'insertion
        query.exec();

        this->counter++;
    }

    if (query.lastError().isValid())
    {
        qWarning() << query.lastError().text();
    }

    return this->counter;
}

int Database::updateFields()
{
    QSqlQuery query;

    // Requete d'update
    query.prepare("UPDATE contacts SET city = 'Toulouse' WHERE company = 'Ynov'");

    // Execution de l'update
    query.exec();

    return true;
}

int Database::deleteFields()
{
    QSqlQuery query;

    // Requete d'update
    query.prepare("DELETE FROM contacts WHERE company = 'Facebook'");

    // Execution de l'update
    query.exec();

    return true;
}

void Database::exportToCsvFile()
{

}
