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
    QSqlDatabase _Database;
public:
public:
    Database();
    void connectionToDataBase(QSqlDatabase *db, QString filePath);
    void insertAllContactsInDataBase(QStringList contactList, QSqlDatabase *db);
    void updateFields(QSqlDatabase *db, QString field);
    void deleteFields(QSqlDatabase *db, QString field);
    void exportToCsvFile(QSqlDatabase *db, QDir *csvFile);

    // Test part preparation
    int coutDataBaseelements(QSqlDatabase *db);
};

#endif // DATABASE_H
