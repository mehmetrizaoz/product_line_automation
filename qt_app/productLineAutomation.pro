QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    form_customer.cpp \
    form_employee.cpp \
    form_login.cpp \
    form_office.cpp \
    form_order.cpp \
    form_order_detail.cpp \
    form_product.cpp \
    form_productlines.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    database.h \
    form_customer.h \
    form_employee.h \
    form_login.h \
    form_office.h \
    form_order.h \
    form_order_detail.h \
    form_product.h \
    form_productlines.h \
    mainwindow.h

FORMS += \
    form_customer.ui \
    form_employee.ui \
    form_login.ui \
    form_office.ui \
    form_order.ui \
    form_order_detail.ui \
    form_product.ui \
    form_productlines.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    queries.qrc
