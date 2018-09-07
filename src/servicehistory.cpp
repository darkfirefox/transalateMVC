#include "servicehistory.h"

ServiceHistory::ServiceHistory()
{
    db.init();
}

void ServiceHistory::deleteAll()
{
    db.deleteAll();
}

void ServiceHistory::deleteRow(int id)
{
    db.deleteRow(id);
}

void ServiceHistory::insertRow(ElementHistory element)
{
    db.insertRow(element);
}

ListElementhistory ServiceHistory::readAll()
{
    ListRecords recs = db.readAll();
    ListElementhistory list;
    for(int i=0;i<list.size();i++){
        list.add(parser.fromRecord(recs.getAt(i)));
    }
    ElementHistory el1;
    el1.setId(0);
    el1.setLangF("en");
    el1.setLangT("ru");
    el1.setTextF("hi");
    el1.setTextT("привет");
    ElementHistory el2;
    el1.setId(1);
    el2.setLangF("en");
    el2.setLangT("ru");
    el2.setTextF("home");
    el2.setTextT("дом");

    list.add(el1);
    list.add(el1);
    list.add(el2);
    list.add(el2);
    list.add(el1);
    return list;
}
