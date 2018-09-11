#ifndef TRANSLATEMODEL_H
#define TRANSLATEMODEL_H

#include <QObject>
#include <QString>
#include "servicehistory.h"
#include "servicehttp.h"

class TranslateModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString langFrom READ getLangFrom WRITE setLangFrom NOTIFY langFromChanged)
    Q_PROPERTY(QString langTo READ getLangTo WRITE setLangTo NOTIFY langToChanged)
    Q_PROPERTY(QString sourceText READ getSourceText WRITE setSourceText NOTIFY sourceTextChanged)
    Q_PROPERTY(QString translatedText READ getTranslatedText WRITE setTranslatedText NOTIFY translatedTextChanged)
public:
    explicit TranslateModel(QObject *parent = nullptr);

    QString getLangFrom() const;
    QString getLangTo() const;
    QString getSourceText() const;
    QString getTranslatedText() const;

    void setLangFrom(QString _langFrom);
    void setLangTo(QString _langTo);
    void setSourceText(QString _sourceText);
    void setTranslatedText(QString _translatedText);

    Q_INVOKABLE void translate();
    Q_INVOKABLE void swap();
signals:
    void translatedTextChanged();
    void langFromChanged();
    void langToChanged();
    void sourceTextChanged();
public slots:
private slots:
    void getResponse(QString response);
private:
    QString langFrom;
    QString langTo;
    QString sourceText;
    QString translatedText;

    ServiceHTTP* serviceHTTP;
    ServiceHistory* serviceHistory;
};

#endif // TRANSLATEMODEL_H
