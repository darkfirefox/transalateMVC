#include "servicehttp.h"

ServiceHTTP* ServiceHTTP::service=0;
ServiceHTTPDestroyer ServiceHTTP::destroyer;

ServiceHTTP::ServiceHTTP(QObject *parent) : QObject(parent)
{
    network=new NetworkManager();
    connect(network,SIGNAL(receivedResponse(QNetworkReply*)),this,SLOT(receiveReply(QNetworkReply*)));
}

ServiceHTTP &ServiceHTTP::Instance()
{
    if(!service){
        service=new ServiceHTTP();
        destroyer.init(service);
    }
    return *service;
}

void ServiceHTTP::sendRequest(QString langFrom, QString langTo, QString sourceText)
{
    network->sendPostRequest(requestConverter.toString(langFrom,langTo,sourceText));
}

QString ServiceHTTP::getResponse()
{
    return response;
}

void ServiceHTTP::receiveReply(QNetworkReply *reply)
{
    response=requestConverter.translatedFromReply(reply);
    emit receiveResponse(response);
}

ServiceHTTPDestroyer::~ServiceHTTPDestroyer()
{
    delete instance;
}

void ServiceHTTPDestroyer::init(ServiceHTTP *service)
{
    instance=service;
}
