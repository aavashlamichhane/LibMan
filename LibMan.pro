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
    booklist.cpp \
    chkreq.cpp \
    editprofile.cpp \
    entry.cpp \
    forgotpass.cpp \
    helpandsupport.cpp \
    homepage.cpp \
    issuerecords.cpp \
    main.cpp \
    mainwindow.cpp \
    mybooklist.cpp \
    privacyandsecurity.cpp \
    promote.cpp \
    removebook.cpp \
    request.cpp \
    resetpass.cpp \
    returnbook.cpp \
    settings.cpp \
    signup.cpp \
    studenthomepage.cpp \
    updatebook.cpp \
    userinfo.cpp

HEADERS += \
    about.h \
    adminpannel.h \
    bookissue.h \
    booklist.h \
    chkreq.h \
    editprofile.h \
    entry.h \
    forgotpass.h \
    helpandsupport.h \
    homepage.h \
    issuerecords.h \
    mainwindow.h \
    mybooklist.h \
    privacyandsecurity.h \
    promote.h \
    removebook.h \
    request.h \
    resetpass.h \
    returnbook.h \
    settings.h \
    signup.h \
    studenthomepage.h \
    updatebook.h \
    userinfo.h

FORMS += \
    about.ui \
    adminpannel.ui \
    bookissue.ui \
    booklist.ui \
    chkreq.ui \
    editprofile.ui \
    entry.ui \
    forgotpass.ui \
    helpandsupport.ui \
    homepage.ui \
    issuerecords.ui \
    mainwindow.ui \
    mybooklist.ui \
    privacyandsecurity.ui \
    promote.ui \
    removebook.ui \
    request.ui \
    resetpass.ui \
    returnbook.ui \
    settings.ui \
    signup.ui \
    studenthomepage.ui \
    updatebook.ui \
    userinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

