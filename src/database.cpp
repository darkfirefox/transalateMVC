#include "database.h"

Database::Database()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    path="/usr/share/translate/data/HistoryDB.sqlite";
}

void Database::init()
{
    if(!db.isOpen()){
        db.setDatabaseName(path);
        db.open();
        query.exec("CREATE TABLE IF NOT EXISTS historyTranslate (fromL text,fromT text,toL text, toT text)");
    }
}

void Database::insertRow(ElementHistory element)
{
    query.prepare("INSERT INTO historyTranslate  VALUES(?, ?, ?, ?)");
    query.addBindValue(element.getLangF());
    query.addBindValue(element.getLangT());
    query.addBindValue(element.getTextF());
    query.addBindValue(element.getTextT());
    query.exec();
}

void Database::deleteRow(const int id)
{
    query.prepare("delete from historyTranslate where rowid = ?");
    query.addBindValue(id);
    query.exec();
}

void Database::deleteAll()
{
    query.exec("delete from historyTranslate");
}

ListRecords Database::readAll()
{
    query.exec("SELECT rowid,fromL,fromT,toL,toT FROM historyTranslate order by rowid desc");
    ListRecords list;
    while(query.next()){
        list.add(query.record());
    }
    return list;
}
