#ifndef SERVICEHTTP_H
#define SERVICEHTTP_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include "requestconverter.h"
#include "networkmanager.h"
#include "elementrequest.h"

class ServiceHTTP;
class ServiceHTTPDestroyer
{
public:
    ~ServiceHTTPDestroyer();
    void init(ServiceHTTP* service);
private:
    ServiceHTTP* instance;
};


class ServiceHTTP : public QObject
{
    Q_OBJECT
public:
    static ServiceHTTP& Instance();

    void sendRequest(QString langFrom,QString langTo, QString sourceText);
    QString getResponse();

private slots:
    void receiveReply(QNetworkReply* reply);
signals:
    void  receiveResponse(QString _response);
private:
    NetworkManager* network;
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
