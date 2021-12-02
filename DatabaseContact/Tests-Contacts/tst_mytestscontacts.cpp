#include "../Contacts/contacts.h"
#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class MyTestsContacts : public QObject
{
    Q_OBJECT
    Contacts contacts;
    QStringList list;

public:
    MyTestsContacts();
    ~MyTestsContacts() override;

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

    list.at(1);
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

}

QTEST_MAIN(MyTestsContacts)

#include "tst_mytestscontacts.moc"
