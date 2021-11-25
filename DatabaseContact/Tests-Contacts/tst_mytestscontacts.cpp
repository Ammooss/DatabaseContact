#include "../Contacts/contacts.h"
#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class MyTestsContacts : public QObject
{
    Q_OBJECT

public:
    MyTestsContacts();
    ~MyTestsContacts();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

MyTestsContacts::MyTestsContacts()
{

}

MyTestsContacts::~MyTestsContacts()
{

}

void MyTestsContacts::initTestCase()
{

}

void MyTestsContacts::cleanupTestCase()
{

}

void MyTestsContacts::test_case1()
{
    //Déclarations des variables
    QStringList filePath = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    QDir csvDir(filePath[0]);

    QDirIterator it(csvDir, QDirIterator::NoIteratorFlags);
    QString data;
    QStringList contactList;

    //Vérifie l'existence du fichier contenant les CSV
    if (!csvDir.exists())
    {
        QDir().mkdir("tests-contacts");
        qWarning() << "Can't find the folder tests-contacts in AppData/Roaming who contains the csv files";
    }

    //Lecture des fichiers CSV
    while (it.hasNext())
    {
        QFile file(it.next());
        file.open(QIODevice::ReadOnly);
        while (!file.atEnd())
        {
            data = file.readLine();
            contactList = data.split(',');
            //Insert DB
            qDebug() << contactList;
        }
        file.close();
    }
}

QTEST_MAIN(MyTestsContacts)

#include "tst_mytestscontacts.moc"
