#ifndef SERVICES_H
#define SERVICES_H

#include <QObject>
#include "servicehistory.h"
#include "servicehttp.h"
class Services : public QObject
{
    Q_OBJECT
public:
    explicit Services(QObject *parent = nullptr);


    void transalate(QString langFrom,QString langTo,QString sourceText);
    void deleteAll();
    void deleteRow(int id);
    ListElementhistory readAll();
signals:

public slots:
private:
    IServiceHttp* serviceHttp;
    IServiceHistory* serviceHistory;
};

#endif // SERVICES_H
