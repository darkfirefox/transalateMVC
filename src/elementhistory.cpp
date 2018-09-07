#include "elementhistory.h"

ElementHistory::ElementHistory()
{

}

void ElementHistory::setId(int _id)
{
    id=_id;
}

void ElementHistory::setLangF(QString _langF)
{
    langF=_langF;
}

void ElementHistory::setLangT(QString _langT)
{
    langT=_langT;
}

void ElementHistory::setTextF(QString _textF)
{
    textF=_textF;
}

void ElementHistory::setTextT(QString _textT)
{
    textT=_textT;
}

int ElementHistory::getId() const
{
    return id;
}

QString ElementHistory::getLangF() const
{
    return langF;
}

QString ElementHistory::getLangT() const
{
    return langT;
}

QString ElementHistory::getTextF() const
{
    return textF;
}

QString ElementHistory::getTextT() const
{
    return textT;
}
