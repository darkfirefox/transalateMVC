#include "elementrequest.h"

ElementRequest::ElementRequest()
{

}

void ElementRequest::setCode(QString _code)
{
    code=_code;
}

void ElementRequest::setLang(QString _lang)
{
    lang=_lang;
}

void ElementRequest::setText(QString _text)
{
    text=_text;
}

QString ElementRequest::getCode() const
{
    return code;
}

QString ElementRequest::getLang() const
{
    return lang;
}

QString ElementRequest::getText() const
{
    return text;
}
