#include "translatemodel.h"

TranslateModel::TranslateModel(QObject *parent) : QObject(parent)
{
    serviceHTTP=&ServiceHTTP::Instance();
    serviceHistory=&ServiceHistory::Instance();
    connect(serviceHTTP,SIGNAL(receiveResponse(QString)),this,SLOT(getResponse(QString)));
    sourceText="Hello,World!";
    langFrom="en";
    langTo="ru";
    combolist1<<"en"<<"ru"<<"fr"<<"de"<<"it";
    combolist2<<"en"<<"ru"<<"fr"<<"de"<<"it";
    cbCount1=0;
    cbCount2=1;
}

QString TranslateModel::getSourceText() const
{
    return sourceText;
}

QString TranslateModel::getTranslatedText() const
{
    return translatedText;
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

QStringList TranslateModel::getCombolist1() const
{
    return combolist1;
}

QStringList TranslateModel::getCombolist2() const
{
    return combolist2;
}

int TranslateModel::getCbCount1() const
{
    return cbCount1;
}

int TranslateModel::getCbCount2() const
{
    return cbCount2;
}

void TranslateModel::setCbCount1(int _cbCount1)
{
    if(cbCount1==_cbCount1) return;
    cbCount1=_cbCount1;
    langFrom=combolist1.at(_cbCount1);
}

void TranslateModel::setCbCount2(int _cbCount2)
{
    if(cbCount2==_cbCount2) return;
    cbCount2=_cbCount2;
    langTo=combolist1.at(_cbCount2);
}

void TranslateModel::translate()
{
    serviceHTTP->sendRequest(langFrom,langTo,sourceText);
}

void TranslateModel::getResponse(QString response)
{
    if(response.isEmpty()) return;
    setTranslatedText(response);
    serviceHistory->insertRow(langFrom,langTo,sourceText,translatedText);
    emit translatedTextChanged();
}
