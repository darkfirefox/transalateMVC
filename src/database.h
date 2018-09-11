#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "elementhistory.h"
#include "listrecords.h"
#include <QFile>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
class Database
{
public:
    Database();

    void init();
    void insertRow(ElementHistory element);
    void deleteRow(const int id);
    void deleteAll();
    ListRecords readAll();

private:
    QSqlDatabase db;
    QString name ;
    QSqlQuery query;
    QString path;
};

#endif // DATABASE_H
