#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "../FrameWork/controller.h"

class HomeController: public Controller
{
    Q_OBJECT

public:
    HomeController(QObject* parent=0);
    void index();
};

#endif // HOMECONTROLLER_H
