#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "httprequesthandler.h"

#include <QObject>

using namespace stefanfrings;

class Controller
{
public:
    Controller();

    void setRequestResponse(HttpRequest& request, HttpResponse& response);

     ~Controller(){}

protected:
    HttpRequest * request;
    HttpResponse * response;

};

#endif // CONTROLLER_H
