#include "../Contacts/contacts.h"
#include "../Contacts/database.h"
#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class MyTestsContacts : public QObject
{
    Q_OBJECT

    // Contacts declarations
    Contacts contacts;
    QStringList list;

    // Database declarations
    Database database;
    QSqlDatabase db;

public:
    MyTestsContacts();
    ~MyTestsContacts();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
//    void test_case2();
//    void test_case3();
};

MyTestsContacts::MyTestsContacts()
{

}

MyTestsContacts::~MyTestsContacts()
{

}

void MyTestsContacts::initTestCase()
{
    QDir csvDir = contacts.pathAccess();
    list = contacts.readAllContactsFiles(&csvDir);
}

void MyTestsContacts::cleanupTestCase()
{

}

void MyTestsContacts::test_case1()
{
    // Test des enregistrements de 1M de contact dans une liste
    QCOMPARE(list.count(), 1000000);

    // Test de la connection a la base de donnees
    QCOMPARE(database.connectionToDataBase(&db), true);

    // Test de l'insertion des 1M de contact insere dans la DB
    QCOMPARE(database.insertAllContactsInDataBase(list), 1000000);

    // Test de l'update des contact Ynov
    QCOMPARE(database.updateFields(), 1); // A confirmer (Tester)

    // Test de la suppresion des contacts Facebook
    QCOMPARE(database.deleteFields(), 1); // A confirmer (Tester)

}

QTEST_MAIN(MyTestsContacts)

#include "tst_mytestscontacts.moc"
