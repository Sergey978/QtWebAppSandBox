#include "homecontroller.h"
#include "../FrameWork/controller.h"

HomeController::HomeController()
{

}

void HomeController::index()
{

    response->write("<html><body>");
    response->write("<h1> Hello Home controller!!</h1>");

    response->write("</body></html>",true);


}
