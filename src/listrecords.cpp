#include "listrecords.h"

ListRecords::ListRecords()
{

}

int ListRecords::size()
{
    return list.size();
}

QSqlRecord ListRecords::getAt(const int i)
{
    return list.at(i);
}

void ListRecords::removeAt(const int i)
{
    list.removeAt(i);
}

void ListRecords::add(QSqlRecord rec)
{
    list.append(rec);
}
