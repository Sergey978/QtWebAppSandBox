#include "homecontroller.h"


HomeController::HomeController(QObject* parent) : Controller  (parent)
{

}

void HomeController::index()
{

     qDebug("response");

    response->write("Hello World",false);


}
