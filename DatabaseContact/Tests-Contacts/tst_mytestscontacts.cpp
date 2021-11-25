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

}

QTEST_MAIN(MyTestsContacts)

#include "tst_mytestscontacts.moc"
