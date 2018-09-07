#include "databaseparser.h"

DatabaseParser::DatabaseParser()
{

}

ElementHistory DatabaseParser::fromRecord(const QSqlRecord &rec)
{
    ElementHistory element;
    element.setId(rec.value(0).toInt());
    element.setLangF(rec.value(1).toString());
    element.setLangT(rec.value(2).toString());
    element.setTextF(rec.value(3).toString());
    element.setTextT(rec.value(4).toString());
    return element;
}

