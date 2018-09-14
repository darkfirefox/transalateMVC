#include "servicehttp.h"

ServiceHTTP* ServiceHTTP::service=0;
ServiceHTTPDestroyer ServiceHTTP::destroyer;

ServiceHTTP::ServiceHTTP(QObject *parent) : QObject(parent)
{
    network=new NetworkManager();
    stream=&StreamData::Instance();
    connect(network,SIGNAL(receivedResponse(QNetworkReply*)),this,SLOT(receiveReply(QNetworkReply*)));
    connect(this,SIGNAL(addedAnswer()),stream,SLOT(lastWasTrasnalate()));
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
    *stream<<langFrom<<langTo<<sourceText;
}

void ServiceHTTP::receiveReply(QNetworkReply *reply)
{
    QString response=requestConverter.translatedFromReply(reply);
    if(response.isEmpty()) stream->clear();
    else{
            *stream<<response;
            emit addedAnswer();
    }
}

ServiceHTTPDestroyer::~ServiceHTTPDestroyer()
{
    delete instance;
}

void ServiceHTTPDestroyer::init(ServiceHTTP *service)
{
    instance=service;
}
