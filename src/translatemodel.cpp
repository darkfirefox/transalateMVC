#include "translatemodel.h"

TranslateModel::TranslateModel(QObject *parent) : QObject(parent)
{
    serviceHTTP=&ServiceHTTP::Instance();
    serviceHistory=&ServiceHistory::Instance();
    connect(serviceHTTP,SIGNAL(receiveResponse(QString)),this,SLOT(getResponse(QString)));
    sourceText="Hello,World!";
    langFrom="en";
    langTo="ru";
}

QString TranslateModel::getLangFrom() const
{
    return langFrom;
}

QString TranslateModel::getLangTo() const
{
    return langTo;
}

QString TranslateModel::getSourceText() const
{
    return sourceText;
}

QString TranslateModel::getTranslatedText() const
{
    return translatedText;
}

void TranslateModel::setLangFrom(QString _langFrom)
{
    langFrom=_langFrom;
    emit langFromChanged();
}

void TranslateModel::setLangTo(QString _langTo)
{
    langTo=_langTo;
    emit langToChanged();
}

void TranslateModel::setSourceText(QString _sourceText)
{

    sourceText=_sourceText;
}

void TranslateModel::setTranslatedText(QString _translatedText)
{
    if(translatedText==_translatedText) return;
    translatedText=_translatedText;
    emit translatedTextChanged();
}

void TranslateModel::translate()
{
    serviceHTTP->sendRequest(langFrom,langTo,sourceText);
}

void TranslateModel::swap()
{
    QString temp=langFrom;
    setLangFrom(langTo);
    setLangTo(temp);
}

void TranslateModel::getResponse(QString response)
{
    if(response.isEmpty()) return;
    setTranslatedText(response);
    qDebug()<<translatedText;
    serviceHistory->insertRow(langFrom,langTo,sourceText,translatedText);
    emit translatedTextChanged();
}
