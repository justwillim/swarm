TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../src/client.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../include/client.h

