QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    Lib/qcustomplot.cpp \
    Model/credit.cc \
    Model/model.cc \
    Model/parser.cc \
    View/mainveiw.cpp \
    main.cpp

HEADERS += \
    Controller/controller.h \
    Lib/qcustomplot.h \
    Model/credit.h \
    Model/SmartCalculator.h \
    Model/model.h \
    Model/parser.h \
    View/custombutton.h \
    View/mainveiw.h \
    View/mycommand.h \
    View/mydialog.h \
    View/xareadialog.h \
    View/yareadialog.h

FORMS += \
    View/mainveiw.ui \
    View/mainveiw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
