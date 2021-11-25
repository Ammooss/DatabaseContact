#ifndef CONTACTS_H
#define CONTACTS_H

#include "Contacts_global.h"
#include <QDir>

class CONTACTS_EXPORT Contacts
{
    QDir csvDir(filePath[0]);

public:
    Contacts();
    void ifFileExist();
    void insertContactDb();
};

#endif // CONTACTS_H
