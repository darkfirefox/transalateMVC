#include "historymodel.h"

HistoryModel::HistoryModel(QObject *parent)
{
    backing = services.readAll();
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
    case id:
        return QVariant(backing.getAt(index.row()).getId());
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
    roles[id]="id";
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
    int id=backing.getAt(i).getId();
    beginRemoveRows(QModelIndex(), i, i);
    backing.deleteAt(i);
    endRemoveRows();
    services.deleteRow(id);
}

void HistoryModel::clearAll()
{
    beginRemoveRows(QModelIndex(), 0, backing.size()-1);
    for (int i=0; i < backing.size(); ++i) {
             backing.deleteAt(i);
         }
    endRemoveRows();
    services.deleteAll();
}
