QT       += core gui widgets

TARGET = TP_IN55
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/mainwidget.cpp \
    src/geometryengine.cpp \
    src/cube.cpp

HEADERS += \
    src/mainwidget.h \
    src/geometryengine.h \
    src/cube.h

RESOURCES += \
    ressources/shaders.qrc \
