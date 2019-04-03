#include "controller.h"
#include "../requestmapper.h"

Controller::Controller()

{

}

void Controller::setRequestResponse(HttpRequest &request, HttpResponse &response)
{
    this->request = &request;
    this->response = &response;

}



 
