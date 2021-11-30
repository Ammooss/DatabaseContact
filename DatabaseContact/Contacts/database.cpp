#include "database.h"

Database::Database()
{
    _Database = QSqlDatabase::addDatabase("QSQLITE");
    _Database.setDatabaseName(""); //Database path (Appdata folder)
    if (!_Database.open())
     {
        qDebug() << "Error: connection with database failed";
     }
     else
     {
        qDebug() << "Database: connection ok";
     }
}
