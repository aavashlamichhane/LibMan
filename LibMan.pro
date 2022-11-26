QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    adminpannel.cpp \
    bookissue.cpp \
    editprofile.cpp \
    entry.cpp \
    helpandsupport.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    mybooklist.cpp \
    privacyandsecurity.cpp \
    promote.cpp \
    request.cpp \
    returnbook.cpp \
    settings.cpp \
    signup.cpp \
    studenthomepage.cpp \
    userinfo.cpp

HEADERS += \
    about.h \
    adminpannel.h \
    bookissue.h \
    editprofile.h \
    entry.h \
    helpandsupport.h \
    homepage.h \
    mainwindow.h \
    mybooklist.h \
    privacyandsecurity.h \
    promote.h \
    request.h \
    returnbook.h \
    settings.h \
    signup.h \
    studenthomepage.h \
    userinfo.h

FORMS += \
    about.ui \
    adminpannel.ui \
    bookissue.ui \
    editprofile.ui \
    entry.ui \
    helpandsupport.ui \
    homepage.ui \
    mainwindow.ui \
    mybooklist.ui \
    privacyandsecurity.ui \
    promote.ui \
    request.ui \
    returnbook.ui \
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

