QT += testlib core sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_mytestscontacts.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Contacts/release/ -lContacts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Contacts/debug/ -lContacts
else:unix: LIBS += -L$$OUT_PWD/../Contacts/ -lContacts

INCLUDEPATH += $$PWD/../Contacts
DEPENDPATH += $$PWD/../Contacts
