QT       += core gui sql
QT += widgets
CONFIG += resources_big
QMAKE_CXXFLAGS += -O0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminDialog1.cpp \
    Login.cpp \
    UserDialog1.cpp \
    dashboard.cpp \
    deleteitem.cpp \
    finditem.cpp \
    items.cpp \
    main.cpp \
    updateitem.cpp \
    user.cpp

HEADERS += \
    AdminDialog1.h \
    Login.h \
    Register.h \
    UserDialog1.h \
    dashboard.h \
    deleteitem.h \
    finditem.h \
    items.h \
    updateitem.h \
    user.h

FORMS += \
    AdminDialog1.ui \
    Login.ui \
    UserDialog1.ui \
    dashboard.ui \
    deleteitem.ui \
    finditem.ui \
    updateitem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
