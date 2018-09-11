#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QObject>


class NetworkManager: public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent=nullptr);

    void sendPostRequest(QString request);
    QNetworkReply* getResponse();
signals:
    void receivedResponse(QNetworkReply* reply);
private slots:
    void recivedReply(QNetworkReply* reply);
private:
    QString url;
    QNetworkAccessManager* nam;
    QNetworkReply *response;
};

#endif // NETWORKMANAGER_H
