#ifndef SERVICEHISTORY_H
#define SERVICEHISTORY_H
#include "database.h"
#include "elementhistory.h"
#include "listelementhistory.h"
#include "listrecords.h"
#include "databaseparser.h"

class ServiceHistory;
class ServiceHistoryDestroyer
{
public:
    ~ServiceHistoryDestroyer();
    void init(ServiceHistory* service);
private:
    ServiceHistory* instance;
};

class ServiceHistory
{
public:
    void deleteAll();
    void deleteRow(int id);
    void insertRow(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ListElementhistory readAll();

    static ServiceHistory& Instance();
private:
    Database db;
    DatabaseParser parser;

    static ServiceHistory* service;
    static ServiceHistoryDestroyer destroyer;
protected:
    ServiceHistory();
    friend class ServiceHistoryDestroyer;
    ServiceHistory(const ServiceHistory&);
    ServiceHistory& operator= (ServiceHistory&);
    ~ServiceHistory(){}
};

#endif // SERVICEHISTORY_H
