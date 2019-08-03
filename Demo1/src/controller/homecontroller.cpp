#include "homecontroller.h"


HomeController::HomeController(Controller * cont)
{

}

HomeController::~HomeController()
{
    qDebug("HomeController: deleted");

}

void HomeController::index()
{

    qDebug("response");


    //controller->getResponse().write("Hello World",false);
    response->write("Hello World");

}

void HomeController::withParams(QString param)
{
    QByteArray res = "hello world";
    res.append(param);
   // controller->getResponse().write(res, true);
    response->write(res, true);
}
