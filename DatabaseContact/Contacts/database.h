#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>

#include "Contacts_global.h"

class CONTACTS_EXPORT Database
{
private:
//  QSqlDatabase _Database;
    int counter;

public:
    Database();
    bool connectionToDataBase(QSqlDatabase *db);
    int insertAllContactsInDataBase(QStringList contactList);
//    void updateFields(QSqlDatabase *db, QString field);
//    void deleteFields(QSqlDatabase *db, QString field);
//    void exportToCsvFile(QSqlDatabase *db, QDir *csvFile);

//    // Test part preparation
//    int coutDataBaseelements(QSqlDatabase *db);
};

#endif // DATABASE_H
