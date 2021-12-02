#include "contacts.h"

Contacts::Contacts()
{

}

const QString &Contacts::getAppdataLocation() const
{
    return appdataLocation;
}

// File operations
QDir Contacts::pathAccess()
{
    QDir csvDir(this->getAppdataLocation());
    return csvDir;
}

QStringList Contacts::readAllContactsFiles(QDir *csvDir)
{
    // Read csv files add contacs to a list
        QDirIterator it(*csvDir, QDirIterator::NoIteratorFlags);
        QStringList contactList;
        QString data;

        if(!csvDir->exists())
        {
            QDir().mkdir("tests-contacts"); // KC
            qDebug() << "Can't find the folder tests-contacts in AppData/Roaming that contains the csv files";
        }
        else
        {
            qDebug() << "Found it !";
        }

        while (it.hasNext())
        {
            QFile file(it.next());
            file.open(QIODevice::ReadOnly);
            file.readLine(0);
            while (!file.atEnd())
            {
                data = file.readLine();
                contactList.append(data);
            }
            file.close();
        }

        return contactList;

}
