#include "requestconverter.h"

RequestConverter::RequestConverter()
{

}

QString RequestConverter::toString(QString langFrom, QString langTo, QString sourceText)
{
    QString str;
    str.append(sourceText);
    str.append("&lang=");
    str.append(langFrom);
    str.append("-");
    str.append(langTo);
    return str;
}

QString RequestConverter::translatedFromReply(QNetworkReply *reply)
{
    QJsonDocument document=QJsonDocument::fromJson(reply->readAll());
    QJsonObject root=document.object();
    QJsonValue value=root.value("text");
    QString result;
    if(value.isArray()){
        QJsonArray ja=value.toArray();
        result=ja.at(0).toString();
    }
    return result;
}
