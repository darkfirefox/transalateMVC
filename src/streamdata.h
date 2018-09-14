#ifndef STREAMDATA_H
#define STREAMDATA_H

#include <QObject>
#include <QMutex>
class StreamData;
class StreamDataDestroyer
{
public:
   ~StreamDataDestroyer();
    void init(StreamData* streamData);
private:
    StreamData* instance;
};
class StreamData : public QObject
{
    Q_OBJECT
public:
    static StreamData &Instance();

    void writeString(QString str);
    QStringList readAll();
    void clear();
    StreamData &operator <<(QString& s);
signals:
    void responseReceived(QString data);
    void readyToStore();
public slots:
    void lastWasTrasnalate();
private:
    void addElement(QString el);
    QStringList stack;
    QMutex mutex;

    static StreamData* stream;
    static StreamDataDestroyer destroyer;
protected:
    explicit StreamData(QObject *parent = nullptr);
    friend class StreamDataDestroyer;
    StreamData(const StreamData&);
    StreamData& operator =(StreamData&);
    ~StreamData(){}
};

#endif // STREAMDATA_H
