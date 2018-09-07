#ifndef LISTRECORDS_H
#define LISTRECORDS_H
#include <QSqlRecord>
#include <QVector>
class ListRecords
{
public:
    ListRecords();
    int size();
    QSqlRecord getAt(const int i);
    void add(QSqlRecord rec);
    void removeAt(const int i);
private:
    QVector<QSqlRecord> list;
};

#endif // LISTRECORDS_H
