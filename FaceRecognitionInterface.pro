#-------------------------------------------------
#
# Project created by QtCreator 2013-05-09T10:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceRecognitionInterface
TEMPLATE = app


SOURCES += main.cpp \
    vue/mainwindow.cpp \
    controleur/controleur.cpp \
    modele/photo.cpp \
    modele/photos.cpp \
    modele/modeleafficherphotos.cpp \
    modele/modeleafficherpersonne.cpp

HEADERS  += vue/mainwindow.h \
    controleur/controleur.h \
    modele/photo.h \
    modele/photos.h \
    modele/modeleafficherphotos.h \
    modele/modeleafficherpersonne.h

FORMS    += vue/mainwindow.ui

OTHER_FILES += \
    description.txt \
    .gitignore \
    README.md

QMAKE_CXXFLAGS += -std=c++11
