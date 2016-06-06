#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T20:32:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = minesweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clock.cpp \
    minesweeper.cpp \
    board.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    clock.h \
    minesweeper.h \
    board.h \
    cell.h

FORMS    += mainwindow.ui \
    minesweeperboard.ui

RESOURCES +=

DISTFILES +=



