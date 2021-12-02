#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include <QStandardPaths>
#include <QDirIterator>
#include <QDebug>

#include "Contacts_global.h"

class CONTACTS_EXPORT Contacts
{
public:
    Contacts();
    QDir pathAccess();
    QStringList readAllContactsFiles(QDir *csvDir);
};

#endif // CONTACTS_H
