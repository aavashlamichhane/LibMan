QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editprofile.cpp \
    entry.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    mybooklist.cpp \
    request.cpp \
    settings.cpp \
    signup.cpp \
    studenthomepage.cpp \
    userinfo.cpp

HEADERS += \
    editprofile.h \
    entry.h \
    homepage.h \
    mainwindow.h \
    mybooklist.h \
    request.h \
    settings.h \
    signup.h \
    studenthomepage.h \
    userinfo.h

FORMS += \
    editprofile.ui \
    entry.ui \
    homepage.ui \
    mainwindow.ui \
    mybooklist.ui \
    request.ui \
    settings.ui \
    signup.ui \
    studenthomepage.ui \
    userinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

SUBDIRS += \
    ../../../../Users/Aavash/Downloads/Libman-20221102T061658Z-001/Libman/Libman.pro
