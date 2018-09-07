#ifndef SERVICEHISTORY_H
#define SERVICEHISTORY_H
#include "database.h"
#include "elementhistory.h"
#include "listelementhistory.h"
#include "listrecords.h"
#include "databaseparser.h"
class ServiceHistory
{
public:
    ServiceHistory();

    void deleteAll();
    void deleteRow(int id);
    void insertRow(ElementHistory element);
    ListElementhistory readAll();

private:
    Database db;
    DatabaseParser parser;
};

#endif // SERVICEHISTORY_H
