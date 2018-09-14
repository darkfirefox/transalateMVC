#ifndef TRANSLATEMODEL_H
#define TRANSLATEMODEL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "services.h"

class TranslateModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceText READ getSourceText WRITE setSourceText NOTIFY sourceTextChanged)
    Q_PROPERTY(QString translatedText READ getTranslatedText WRITE setTranslatedText NOTIFY translatedTextChanged)

    Q_PROPERTY(QStringList combolist1 READ getCombolist1 NOTIFY combolist1Changed)
    Q_PROPERTY(QStringList combolist2 READ getCombolist2 NOTIFY combolist2Changed)
    Q_PROPERTY(int cbCount1 READ getCbCount1 WRITE setCbCount1 NOTIFY cbCount1Changed)
    Q_PROPERTY(int cbCount2 READ getCbCount2 WRITE setCbCount2 NOTIFY cbCount2Changed)

    Q_PROPERTY(QString page READ getPage NOTIFY pageChanged)
public:
    explicit TranslateModel(QObject *parent = nullptr);

    QString getSourceText() const;
    QString getTranslatedText() const;

    void setSourceText(QString _sourceText);
    void setTranslatedText(QString _translatedText);


    QStringList getCombolist1() const;
    QStringList getCombolist2() const;
    int getCbCount1() const;
    int getCbCount2() const;

    void setCbCount1(int _cbCount1);
    void setCbCount2(int _cbCount2);

    QString getPage();

    Q_INVOKABLE void translate();
    Q_INVOKABLE void historyPage();
signals:
    void translatedTextChanged();
    void langFromChanged();
    void langToChanged();
    void sourceTextChanged();
    void combolist1Changed();
    void combolist2Changed();
    void cbCount1Changed();
    void cbCount2Changed();
    void pageChanged();
public slots:
private slots:
    void getResponse(QString response);
private:
    QString langFrom;
    QString langTo;
    QString sourceText;
    QString translatedText;

    QString page;
    StreamData* stream;
    Services services;

    QStringList combolist1;
    QStringList combolist2;
    int cbCount1;
    int cbCount2;
};

#endif // TRANSLATEMODEL_H
