#include "translatemodel.h"

TranslateModel::TranslateModel(QObject *parent) : QObject(parent)
{
    stream=&StreamData::Instance();
    connect(stream,SIGNAL(responseReceived(QString)),this,SLOT(getResponse(QString)));
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

QString TranslateModel::getPage()
{
    return page;
}

void TranslateModel::translate()
{
    services.transalate(langFrom,langTo,sourceText);
}

void TranslateModel::historyPage()
{
    page="HistoryPage.qml";
    emit pageChanged();
}

void TranslateModel::getResponse(QString response)
{
    if(response.isEmpty()) return;
    translatedText=response;
    emit translatedTextChanged();
}
