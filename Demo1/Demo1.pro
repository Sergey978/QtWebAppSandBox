# This project demonstrates how to use QtWebAppLib by including the
# sources into this project.

TARGET = Demo1
TEMPLATE = app
QT = core network
CONFIG += c++14 console

HEADERS += \
           src/requestmapper.h \
           src/controller/dumpcontroller.h \
           src/controller/templatecontroller.h \
           src/controller/formcontroller.h \
           src/controller/fileuploadcontroller.h \
           src/controller/sessioncontroller.h \
			src/FrameWork/Router/fnptr.h \
			src/FrameWork/Router/route.h \
			src/FrameWork/Router/urlmatcher.h \
			src/FrameWork/Router/urlparams.h \
			src/FrameWork/controller.h \
			src/FrameWork/model.h \
    src/controller/homecontroller.h


SOURCES += src/main.cpp \
           src/requestmapper.cpp \
           src/controller/dumpcontroller.cpp \
           src/controller/templatecontroller.cpp \
           src/controller/formcontroller.cpp \
           src/controller/fileuploadcontroller.cpp \
           src/controller/sessioncontroller.cpp \
            src/FrameWork/Router/route.cpp \
            src/FrameWork/Router/urlmatcher.cpp \
            src/FrameWork/Router/urlparams.cpp \
            src/FrameWork/controller.cpp \
    src/controller/homecontroller.cpp
   
   

OTHER_FILES += etc/* etc/docroot/* etc/templates/* etc/ssl/* logs/* ../readme.txt

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../QtWebApp/logging/logging.pri)
include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)
# Not used: include(../QtWebApp/qtservice/qtservice.pri)
