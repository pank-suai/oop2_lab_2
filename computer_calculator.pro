QT += core gui widgets

TARGET = computer_calculator
TEMPLATE = app

CONFIG += c++17

SOURCES += \
    src/qt_main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/mainwindow.h

FORMS += \
    src/mainwindow.ui

QMAKE_CXXFLAGS += -std=c++17
