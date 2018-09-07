#ifndef LISTELEMENTHISTORY_H
#define LISTELEMENTHISTORY_H
#include <QVector>

#include "elementhistory.h"
class ListElementhistory
{
public:
    ListElementhistory();

    ElementHistory getAt(const int i) const;
    int size() const;
    void deleteAt(const int i);
    void add(ElementHistory element);

private:
    QVector<ElementHistory> list;
};

#endif // LISTELEMENTHISTORY_H
