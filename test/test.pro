QT += testlib

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../project


SOURCES += \
    ../project/conto.cpp \
    ../project/persona.cpp \
    ../project/pinmanager.cpp \
    ../project/transazione.cpp \
    ../project/lib/simplecrypt.cpp \
    unitTest.cpp \


HEADERS += \
    ../project/AbstractView.h \
    ../project/conto.h \
    ../project/IdCounter.h \
    ../project/Model.h \
    ../project/persona.h \
    ../project/pinmanager.h \
    ../project/transazione.h \
    ../project/lib/simplecrypt.h \
