#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>

class Database
{
private:
//  QSqlDatabase _Database;
    int counter;

public:
    Database();
    void connectionToDataBase(QSqlDatabase *db);
    void insertAllContactsInDataBase(QStringList contactList);
    void updateFields(QSqlDatabase *db, QString field);
    void deleteFields(QSqlDatabase *db, QString field);
    void exportToCsvFile(QSqlDatabase *db, QDir *csvFile);

    // Test part preparation
    int coutDataBaseelements(QSqlDatabase *db);
    int getCounter() const;
};

#endif // DATABASE_H
