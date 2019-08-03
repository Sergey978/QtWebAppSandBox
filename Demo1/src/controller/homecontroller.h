#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "../FrameWork/controller.h"

class HomeController :  public Controller
{
    Q_OBJECT

public:
    HomeController(Controller * controller);
    ~HomeController();

public slots:
    void index();
    void withParams(QString param);

};

#endif // HOMECONTROLLER_H
