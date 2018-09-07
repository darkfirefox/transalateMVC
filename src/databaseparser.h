#ifndef DATABASEPARSER_H
#define DATABASEPARSER_H
#include <QSqlRecord>
#include <QVariant>
#include "elementhistory.h"
class DatabaseParser
{
public:
    DatabaseParser();
    ElementHistory fromRecord(const QSqlRecord &rec);
};

#endif // DATABASEPARSER_H
