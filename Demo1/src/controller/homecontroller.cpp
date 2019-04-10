#include "homecontroller.h"


HomeController::HomeController(Controller * cont) : controller  (cont)
{

}

void HomeController::index()
{

    qDebug("response");

    controller->getResponse().write("Hello World",false);

}

void HomeController::withParams(QString param)
{
    QByteArray res = "hello world";
    res.append(param);
    controller->getResponse().write(res, true);
}
