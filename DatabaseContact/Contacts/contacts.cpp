#include "contacts.h"
#include <QStringList>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QString>
#include <QFile>

Contacts::Contacts()
{

}

void Contacts::ifFileExist()
{
    QStringList filePath = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);

    if (!csvDir.exists())
    {
        qWarning() << "Can't find the folder tests-contacts in AppData/Roaming who contains the csv files";
    }
}

void Contacts::insertContactDb()
{
    QDirIterator it(csvDir, QDirIterator::NoIteratorFlags);
    QString data;
    QFile file(csvDir);

    while (it.hasNext()) {
    data = file.readLine();
    wordList = data.split(',');

    }
}
