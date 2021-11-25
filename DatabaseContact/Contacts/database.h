#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>

class Database
{
    QSqlDatabase _Database;
public:
    Database();
    void addRow(const QString& ID, const QString& GUI, const QString& firstname, const QString& lastname,
                const QString& email, const QString& tel, const QString& category, const QString& city,
                const QString& birth_date, const QString& list, const QString& company);
    QStringList getFromName(QString& filename);
    QStringList getFromExt(QString& fileextension);
    QStringList transformQueryToStringList(QSqlQuery query);
};

#endif // DATABASE_H
