SOURCES += \
    Main.cpp \
    mainwindow.cpp \
    gamewindow.cpp \
    howtodialog.cpp \
    database.cpp \
    settings.cpp \
    connection.cpp
QT += sql
QT += network
FORMS += \
    mainwindow.ui \
    gamewindow.ui \
    howtodialog.ui \
    connection.ui
HEADERS += \
    mainwindow.h \
    gamewindow.h \
    howtodialog.h \
    database.h \
    settings.h \
    connection.h
RESOURCES += \
    resources.qrc

OTHER_FILES += \
    cellGen.js

