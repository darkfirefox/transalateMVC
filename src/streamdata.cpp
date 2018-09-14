#include "streamdata.h"
StreamData* StreamData::stream=0;
StreamDataDestroyer StreamData::destroyer;

StreamData &StreamData::Instance()
{
    if(!stream){
        stream=new StreamData();
        destroyer.init(stream);
    }
    return *stream;
}

void StreamData::writeString(QString str)
{
    mutex.lock();
    stack<<str;
    mutex.unlock();
}

QStringList StreamData::readAll()
{
    mutex.lock();
    QStringList all(stack);
    stack.clear();
    mutex.unlock();
    return all;
}

void StreamData::clear()
{
    mutex.lock();
    stack.clear();
    mutex.unlock();
}

StreamData &StreamData::operator <<(QString &s)
{
    mutex.lock();
    addElement(s);
    mutex.unlock();
    return *this;
}

void StreamData::lastWasTrasnalate()
{
    mutex.lock();
    QString translate=QString(stack.last());
    mutex.unlock();
    emit responseReceived(translate);
    emit readyToStore();
}

void StreamData::addElement(QString el)
{
   stack.push_back(el);
}

StreamData::StreamData(QObject *parent) : QObject(parent)
{
    mutex.lock();
    stack.reserve(4);
    mutex.unlock();
}

StreamDataDestroyer::~StreamDataDestroyer()
{
    delete instance;
}

void StreamDataDestroyer::init(StreamData *streamData)
{
    instance=streamData;
}
