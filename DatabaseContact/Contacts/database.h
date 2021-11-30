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
    void addRow(const QString& ID, const QString& GUID, const QString& firstname, const QString& lastname,
                const QString& email, const QString& tel, const QString& category, const QString& city,
                const QString& birth_date, const QString& country, const QString& list, const QString& company);
    QStringList getID(QString& ID);
    QStringList getGUID(QString& GUID);
    QStringList getFirstName(QString& firstname);
    QStringList getLastName(QString& lastname);
    QStringList getEmail(QString& email);
    QStringList getTel(QString& tel);
    QStringList getCategory(QString& category);
    QStringList getCity(QString& city);
    QStringList getBirthDate(QString& birth_date);
    QStringList getCountry(QString& country);
    QStringList getList(QString& list);
    QStringList getCompany(QString& company);
};

#endif // DATABASE_H
