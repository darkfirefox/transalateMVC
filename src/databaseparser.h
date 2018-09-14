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
    ElementHistory fromStrings(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ElementHistory fromStringList(QStringList list);
};

#endif // DATABASEPARSER_H
