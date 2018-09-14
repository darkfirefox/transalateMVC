#ifndef ISERVICEHTTTP_H
#define ISERVICEHTTTP_H
class IServiceHttp
{
public:
   virtual void sendRequest(QString langFrom,QString langTo, QString sourceText)=0;
};
#endif // ISERVICEHTTTP_H
