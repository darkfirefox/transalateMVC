#include "listelementhistory.h"

ListElementhistory::ListElementhistory()
{

}

ElementHistory ListElementhistory::getAt(const int i) const
{
    return list.at(i);
}

int ListElementhistory::size() const
{
    return list.size();
}

void ListElementhistory::deleteAt(const int i)
{
    list.removeAt(i);
}

void ListElementhistory::add(ElementHistory element)
{
    list.append(element);
}
