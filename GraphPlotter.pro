#-------------------------------------------------
#
# Project created by QtCreator 2017-11-18T14:10:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphPlotter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    edge.cpp \
    graph.cpp \
    vertex.cpp \
    point.cpp \
    container.cpp \
    line.cpp \
    directedgraph.cpp

HEADERS += \
        mainwindow.h \
    edge.h \
    graph.h \
    vertex.h \
    point.h \
    container.h \
    list.h \
    node.h \
    listvertex.h \
    listedge.h \
    listpoint.h \
    line.h \
    directedgraph.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc