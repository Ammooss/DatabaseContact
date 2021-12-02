#include "contacts.h"

Contacts::Contacts()
{

}

const QString &Contacts::getAppdataLocation() const
{
    return appdataLocation;
}

// Recuperation du dossier d'acces aux donnees
QDir Contacts::pathAccess()
{
    QDir csvDir(this->getAppdataLocation());
    return csvDir;
}

QStringList Contacts::readAllContactsFiles(QDir *csvDir)
{
    // Lecture des CSV et ajout des contacts a une liste
        QDirIterator it(*csvDir, QDirIterator::NoIteratorFlags);
        QStringList contactList;
        QString data;

        if(!csvDir->exists())
        {
            // Creation du dossier si inexistant
            QDir().mkdir(this->getAppdataLocation());
            qWarning() << "Can't find the folder tests-contacts in AppData/Roaming that contains the csv files";
        }
        else
        {
            qDebug() << "Found it !";
        }


        // Ajout des contacts dans une liste
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
