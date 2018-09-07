#ifndef ELEMENTHISTORY_H
#define ELEMENTHISTORY_H
#include <QString>

class ElementHistory
{
public:
    ElementHistory();

    void setId(int _id);
    void setLangF(QString _langF);
    void setLangT(QString _langT);
    void setTextF(QString _textF);
    void setTextT(QString _textT);

    int getId() const;
    QString getLangF() const;
    QString getLangT() const;
    QString getTextF() const;
    QString getTextT() const;

private:
    int id;
    QString langF;
    QString langT;
    QString textF;
    QString textT;
};

#endif // ELEMENTHISTORY_H
