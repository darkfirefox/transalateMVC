#include "services.h"

Services::Services(QObject *parent) : QObject(parent)
{
    serviceHttp=&ServiceHTTP::Instance();
    serviceHistory=&ServiceHistory::Instance();
}

void Services::transalate(QString langFrom, QString langTo, QString sourceText)
{
    serviceHttp->sendRequest(langFrom,langTo,sourceText);
}

void Services::deleteAll()
{
    serviceHistory->deleteAll();
}

void Services::deleteRow(int id)
{
    serviceHistory->deleteRow(id);
}

ListElementhistory Services::readAll()
{
    return serviceHistory->readAll();
}
