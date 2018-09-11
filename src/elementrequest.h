#ifndef ELEMENTREQUEST_H
#define ELEMENTREQUEST_H
#include <QString>

class ElementRequest
{
public:
    ElementRequest();

    void setCode(QString _code);
    void setLang(QString _lang);
    void setText(QString _text);

    QString getCode() const;
    QString getLang() const;
    QString getText() const;
private:
    QString code;
    QString lang;
    QString text;
};

#endif // ELEMENTREQUEST_H
