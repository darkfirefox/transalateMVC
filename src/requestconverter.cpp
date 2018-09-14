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
template <typename T>
QVector<T> toVector(boost::property_tree::ptree const& pt, boost::property_tree::ptree::key_type const& key)
{
    QVector<T> r;
    for (auto& item : pt.get_child(key))
        r.push_back(item.second.get_value<T>());
    return r;
}
QString RequestConverter::translatedFromReply(QNetworkReply *reply)
{
    std::stringstream ss;
    ss << reply->readAll().toStdString();
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(ss, pt);
    QVector<std::string> text=toVector<std::string>(pt,"text");
    return QString::fromStdString(text.at(0));
}
