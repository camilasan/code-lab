TEMPLATE = app

QT += qml quick widgets sql

SOURCES += main.cpp \
    log.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    log.h \
    initdb.h

