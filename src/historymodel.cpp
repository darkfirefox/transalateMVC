#include "historymodel.h"

HistoryModel::HistoryModel(QObject *parent)
{
    backing = serviceHistory.readAll();
}

int HistoryModel::rowCount(const QModelIndex &parent) const
{
    return backing.size();
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) {
        return QVariant();
    }
    switch (role) {
    case langF:
        return QVariant(backing.getAt(index.row()).getLangF());
    case langT:
        return QVariant(backing.getAt(index.row()).getLangT());
    case textF:
        return QVariant(backing.getAt(index.row()).getTextF());
    case textT:
        return QVariant(backing.getAt(index.row()).getTextT());
    }
    return QVariant();
}

QHash<int, QByteArray> HistoryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[langF] = "langF";
    roles[langT] = "langT";
    roles[textF] = "textF";
    roles[textT] = "textT";
    return roles;
}

void HistoryModel::deleteRow(const int i)
{
    if(i < 0 || i >= backing.size()) {
        return;
    }
    beginRemoveRows(QModelIndex(), i, i);
        backing.deleteAt(i);
    endRemoveRows();
    serviceHistory.deleteRow(i);
}

void HistoryModel::clearAll()
{
    beginRemoveRows(QModelIndex(), 0, backing.size()-1);
    for (int i=0; i < backing.size(); ++i) {
             backing.deleteAt(i);
         }
    endRemoveRows();
    serviceHistory.deleteAll();
}
