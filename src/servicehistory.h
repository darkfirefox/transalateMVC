#ifndef SERVICEHISTORY_H
#define SERVICEHISTORY_H
#include "database.h"
#include "elementhistory.h"
#include "listelementhistory.h"
#include "listrecords.h"
#include "databaseparser.h"
#include "iservicehistory.h"
#include "streamdata.h"
class ServiceHistory;
class StreamData;
class ServiceHistoryDestroyer
{
public:
    ~ServiceHistoryDestroyer();
    void init(ServiceHistory* service);
private:
    ServiceHistory* instance;
};

class ServiceHistory:public QObject,public IServiceHistory
{
    Q_OBJECT
public:
    void deleteAll();
    void deleteRow(int id);
    void insertRow(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ListElementhistory readAll();

    static ServiceHistory& Instance();
public slots:
    void storeDataFromStream();
private:
    Database db;
    DatabaseParser parser;
    StreamData* stream;

    static ServiceHistory* service;
    static ServiceHistoryDestroyer destroyer;
protected:
    explicit ServiceHistory(QObject *parent = nullptr);
    friend class ServiceHistoryDestroyer;
    ServiceHistory(const ServiceHistory&);
    ServiceHistory& operator= (ServiceHistory&);
    ~ServiceHistory(){}
};

#endif // SERVICEHISTORY_H
