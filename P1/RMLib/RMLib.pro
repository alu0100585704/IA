#-------------------------------------------------
#
# Project created by QtCreator 2019-09-26T19:39:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = RMLib
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


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


SOURCES += \
        src/cpp/rmlib.cpp \
    src/cpp/ArbolBB_t.cpp \
    src/cpp/nodoBB_t.cpp \
    src/cpp/dll_node_t.cpp \
    src/cpp/dll_t.cpp \
    src/cpp/AVL_t.cpp \
    src/cpp/nodoAVL_t.cpp \
    src/cpp/sll_node_t.cpp \
    src/cpp/sll_t.cpp \
    src/cpp/vector_t.cpp \
    src/cpp/matricula_t.cpp \
    src/cpp/grafo.cpp


HEADERS += \
    src/include/ArbolBB_t.hpp \    
    src/include/rmlib.hpp \
    src/include/nodoBB_t.hpp \
    src/include/varias.hpp \
    src/include/tipos_genericos.hpp \
    src/include/dll_node_t.hpp \
    src/include/dll_t.hpp \
    src/include/AVL_t.hpp \
    src/include/nodoAVL_t.hpp \
    src/include/ordenacion.hpp \
    src/include/sll_node_t.hpp \
    src/include/sll_t.hpp \
    src/include/vector_t.hpp \
    src/include/matricula_t.hpp \
    src/include/grafo.hpp



INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include

#QMAKE_CXXFLAGS  += -pthread
#QMAKE_CXXFLAGS  -= -fno-keep-inline-dllexport
#QMAKE_LFLAGS_RELEASE += -static-libgcc -static-libstdc++
#QMAKE_LFLAGS_RELEASE += -static-cyggcc_s-1.dll -static-cygstdc++-6.dll
#QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads
#QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
#QMAKE_CXXFLAGS += -std=gnu++0x -pthread
#QMAKE_CFLAGS += -std=gnu++0x -pthread
#LIBS += -pthread
