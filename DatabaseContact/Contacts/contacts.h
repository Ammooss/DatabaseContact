#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include <QStandardPaths>
#include <QDirIterator>
#include <QDebug>

#include "Contacts_global.h"

class CONTACTS_EXPORT Contacts
{
private:
    // Chemin d'acces aux donnees
    QString appdataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
public:
    Contacts();
    QDir pathAccess();
    QStringList readAllContactsFiles(QDir *csvDir);
    const QString &getAppdataLocation() const;
};

#endif // CONTACTS_H
