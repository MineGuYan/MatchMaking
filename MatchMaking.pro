QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    main.cpp \
    mainmenu.cpp \
    network.cpp \
    play.cpp \
    server.cpp \
    skill0.cpp \
    skill1.cpp \
    skill2.cpp \
    skill3.cpp \
    skill4.cpp

HEADERS += \
    client.h \
    mainmenu.h \
    network.h \
    play.h \
    server.h \
    skill0.h \
    skill1.h \
    skill2.h \
    skill3.h \
    skill4.h

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
