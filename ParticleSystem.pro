#-------------------------------------------------
#
# Project created by QtCreator 2018-05-22T16:18:01
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = ParticleSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/Classic.cpp \
    Model/Fire.cpp \
    Model/Gravity.cpp \
    Model/Linear.cpp \
    Model/Particle.cpp \
    Model/Water.cpp \
    Model/Wind.cpp \
    renderwidget.cpp \
    System.cpp \
    Model/Smoke.cpp


HEADERS  += mainwindow.h \
    Model/Classic.h \
    Model/Fire.h \
    Model/Force.h \
    Model/Gravity.h \
    Model/Linear.h \
    Model/Particle.h \
    Model/Smoke.h \
    Model/Water.h \
    Model/Wind.h \
    typedef.h \
    renderwidget.h \
    System.h \
    enum.h


FORMS    += mainwindow.ui

RESOURCES += \
    ressources/shaders.qrc

