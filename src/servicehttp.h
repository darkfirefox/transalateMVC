#ifndef SERVICEHTTP_H
#define SERVICEHTTP_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include "requestconverter.h"
#include "networkmanager.h"
#include "iservicehtttp.h"
#include "streamdata.h"
class ServiceHTTP;
class ServiceHTTPDestroyer
{
public:
    ~ServiceHTTPDestroyer();
    void init(ServiceHTTP* service);
private:
    ServiceHTTP* instance;
};


class ServiceHTTP : public QObject,public IServiceHttp
{
    Q_OBJECT
public:
    static ServiceHTTP& Instance();

    void sendRequest(QString langFrom,QString langTo, QString sourceText);
signals:
    void  addedAnswer();
private slots:
    void receiveReply(QNetworkReply* reply);
private:
    NetworkManager* network;
    StreamData* stream;
    QString response;
    RequestConverter requestConverter;

    static ServiceHTTP* service;
    static ServiceHTTPDestroyer destroyer;
protected:
    explicit ServiceHTTP(QObject *parent = nullptr);
    friend class ServiceHTTPDestroyer;
    ServiceHTTP(const ServiceHTTP&);
    ServiceHTTP& operator =(ServiceHTTP&);
    ~ServiceHTTP(){}
};

#endif // SERVICEHTTP_H
