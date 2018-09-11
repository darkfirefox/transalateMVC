#ifndef REQUESTCONVERTER_H
#define REQUESTCONVERTER_H
#include <QString>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
class RequestConverter
{
public:
    RequestConverter();

    QString toString(QString langFrom, QString langTo, QString sourceText);
    QString translatedFromReply(QNetworkReply* reply);

};

#endif // REQUESTCONVERTER_H
