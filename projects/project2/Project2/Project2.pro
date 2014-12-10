SOURCES += \
    Main.cpp \
    mainwindow.cpp \
    gamewindow.cpp \
    howtodialog.cpp \
    database.cpp \
    settings.cpp
QT += sql
FORMS += \
    mainwindow.ui \
    gamewindow.ui \
    howtodialog.ui
HEADERS += \
    mainwindow.h \
    gamewindow.h \
    howtodialog.h \
    database.h \
    settings.h
RESOURCES += \
    resources.qrc

OTHER_FILES += \
    cellGen.js

