#ifndef REQUESTCONVERTER_H
#define REQUESTCONVERTER_H
#include <QString>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
class RequestConverter
{
public:
    RequestConverter();

    QString toString(QString langFrom, QString langTo, QString sourceText);
    QString translatedFromReply(QNetworkReply* reply);

};

#endif // REQUESTCONVERTER_H
