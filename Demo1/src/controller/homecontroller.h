#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "../FrameWork/controller.h"

class HomeController : public QObject
{
    Q_OBJECT

public:
    HomeController(Controller * controller);

public slots:
    void index();
    void withParams(QString param);
private :
    Controller * controller;
};

#endif // HOMECONTROLLER_H
