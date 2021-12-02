#include "../Contacts/contacts.h"
#include "../Contacts/database.h"
#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class MyTestsContacts : public QObject
{
    Q_OBJECT
    Contacts contacts;
    QStringList list;

    // database part
    Database database;
    QSqlDatabase db;

public:
    MyTestsContacts();
    ~MyTestsContacts();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
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
    QCOMPARE(list.count(), 1000000);
}

void MyTestsContacts::test_case2()
{
    QCOMPARE(database.connectionToDataBase(&db), true);
    QCOMPARE(database.insertAllContactsInDataBase(list), 1000000);
}

QTEST_MAIN(MyTestsContacts)

#include "tst_mytestscontacts.moc"
