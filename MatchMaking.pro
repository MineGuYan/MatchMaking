QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QT       +=multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bird0.cpp \
    bird1.cpp \
    bird2.cpp \
    bird3.cpp \
    bird4.cpp \
    client.cpp \
    main.cpp \
    mainmenu.cpp \
    network.cpp \
    play.cpp \
    server.cpp

HEADERS += \
    bird0.h \
    bird1.h \
    bird2.h \
    bird3.h \
    bird4.h \
    client.h \
    mainmenu.h \
    network.h \
    play.h \
    server.h

FORMS += \
    client.ui \
    mainmenu.ui \
    network.ui \
    play.ui \
    server.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = rc\icon.ico

RESOURCES += \
    resource.qrc
