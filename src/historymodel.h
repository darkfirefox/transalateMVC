#ifndef HISTORYMODEL_H
#define HISTORYMODEL_H
#include <QAbstractListModel>
#include <QObject>
#include "listelementhistory.h"
#include "services.h"

class HistoryModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum HistoryRole{
        id,
        langF,
        langT,
        textF,
        textT
    };
    explicit HistoryModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void deleteRow(const int i);
    Q_INVOKABLE void clearAll();
private:
    ListElementhistory backing;
    Services services;
};

#endif // HISTORYMODEL_H
