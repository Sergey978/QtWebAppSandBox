/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include "requestmapper.h"
#include "filelogger.h"
#include "staticfilecontroller.h"
#include "controller/dumpcontroller.h"
#include "controller/templatecontroller.h"
#include "controller/formcontroller.h"
#include "controller/fileuploadcontroller.h"
#include "controller/sessioncontroller.h"

#include "controller/homecontroller.h"

/** Redirects log messages to a file */
extern FileLogger* logger;

/** Controller for static files */
extern StaticFileController* staticFileController;

RequestMapper::RequestMapper(QObject* parent)
    :HttpRequestHandler(parent)
{

    //registration Controllers
        //  example: matcher.regController("GET;home/about", [&](){});
        //  example: matcher.regController("GET;home/(method:str)", [&](){});
        //  example: matcher.regController("GET|POST;user/edit/(id:num)",
        //  fnptr<void(UrlParams)>[&](UrlParams p){UserController.edit(p.Num("id"))});

        //    matcher.regController("GET;admin/user/(id:num)",
        //             fnptr<void(UrlParams)>([&](UrlParams p){adminController.user(p.Num("id"));}));




    matcher.regController("GET|POST;home/",
                          fnptr<void(UrlParams)>([&](UrlParams )
    {
                              QMetaObject::invokeMethod(homeController, "index",  Qt::DirectConnection);

                          }));

    matcher.regController("GET|POST;home/(param:str)",
                          fnptr<void(UrlParams p)>([&](UrlParams p)
    {
                              QMetaObject::invokeMethod(homeController, "withParams",
                              Qt::DirectConnection, Q_ARG(QString, p.Str("param")));

                          }));



    qDebug("RequestMapper: created");
}


RequestMapper::~RequestMapper()
{
    delete controller;

    qDebug("RequestMapper: deleted");
}


void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    // For the following pathes, each request gets its own new instance of the related controller.


    controller->setRequestResponse(request, response);

    Route * route = matcher.match(request.getMethod(), request.getPath().toStdString());

    if (route != nullptr)
    {
        matcher.execRoute(route);

    }
    else
    {
        staticFileController->service(request, response);
    }




    qDebug("RequestMapper: finished request");

    // Clear the log buffer
    if (logger)
    {
        logger->clear();
    }
}
