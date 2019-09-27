#-------------------------------------------------
#
# Project created by QtCreator 2019-09-24T15:46:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = p1gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        src/cpp/main.cpp \
        src/cpp/mainwindow.cpp \
    src/cpp/myscene.cpp \
    src/cpp/myitem.cpp

HEADERS += \
        src/include/mainwindow.h \
    src/include/myscene.h \
    src/include/myitem.h


FORMS += \
        src/Forms/mainwindow.ui


RESOURCES += \
    src/qrc/recursos.qrc

unix::MOC_DIR = $$PWD/tmp/moc
win32::MOC_DIR = $$PWD/tmp/moc
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::OBJECTS_DIR = $$PWD/tmp/o
win32::OBJECTS_DIR = $$PWD/tmp/o
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::RCC_DIR = $$PWD/tmp/resources
mac::RCC_DIR = $$PWD/tmp/resources
win32::RCC_DIR = $$PWD/tmp/resources


 CONFIG(debug, debug|release) {
     unix: TARGET = $$join(TARGET,,,d)
     win32: TARGET = $$join(TARGET,,,d)
     mac: TARGET = $$join(TARGET,,,d)
 }



INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RMLib/release/ -lRMLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../RMLib/debug/ -lRMLibd
else:unix: LIBS += -L$$OUT_PWD/../RMLib/ -lRMLib

INCLUDEPATH += $$PWD/../RMLib/src/include
DEPENDPATH += $$PWD/../RMLib/src/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RMLib/release/libRMLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RMLib/debug/libRMLibd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RMLib/release/RMLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RMLib/debug/RMLibd.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../RMLib/libRMLib.a
