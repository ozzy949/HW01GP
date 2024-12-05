QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ellipse.cpp \
    Line.cpp \
    Polygon.cpp \
    Text.cpp \
    circle.cpp \
    drawarea.cpp \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    shape.cpp \
    shapevector.cpp \
    polyline.cpp \
    contactus.cpp

HEADERS += \
    Ellipse.h \
    Line.h \
    Parser.h \
    Polygon.h \
    Text.h \
    circle.h \
    drawarea.h \
    loginwindow.h \
    mainwindow.h \
    rectangle.h \
    shape.h \
    shapevector.h \
    vector.h \
    polyline.h \
    contactus.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Sources/txt/shapes.txt
