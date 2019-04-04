#include "controller.h"
#include "../requestmapper.h"

Controller::Controller(QObject* parent) :  QObject(parent)

{

}

void Controller::setRequestResponse(HttpRequest &request, HttpResponse &response)
{

    this->response = &response;

}



 
