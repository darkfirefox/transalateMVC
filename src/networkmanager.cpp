#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{
    url="https://translate.yandex.net/api/v1.5/tr.json/translate?key=trnsl.1.1.20180820T201359Z.206166e00728c4ef.a8714d01ec570dd4d870cd24910324416cd70eaa&text=";
    nam=new QNetworkAccessManager();
    connect(nam, SIGNAL(finished(QNetworkReply*)), this,SLOT(recivedReply(QNetworkReply*)));
}

void NetworkManager::sendPostRequest(QString request)
{
    nam->get(QNetworkRequest(QUrl(url+request)));
}

QNetworkReply* NetworkManager::getResponse()
{
    return response;
}

void NetworkManager::recivedReply(QNetworkReply *reply)
{
    emit receivedResponse(reply);
}
