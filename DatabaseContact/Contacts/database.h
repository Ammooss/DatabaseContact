#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QSqlDatabase>

#include "contacts.h"
#include "Contacts_global.h"

class CONTACTS_EXPORT Database
{
private:
    int counter;
    Contacts contacts;

public:
    Database();
    bool connectionToDataBase(QSqlDatabase *db);
    int insertAllContactsInDataBase(QStringList contactList);
    int updateFields(); // QSqlDatabase *db, QString field
    int deleteFields(); // QSqlDatabase *db, QString field
    void exportToCsvFile(); // QSqlDatabase *db, QDir *csvFile
};

#endif // DATABASE_H
