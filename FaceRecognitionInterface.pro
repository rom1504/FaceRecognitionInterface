#-------------------------------------------------
#
# Project created by QtCreator 2013-05-09T10:45:52
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = bin/FaceRecognitionInterface
TEMPLATE = app
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR

VPATH = source/

INCLUDEPATH = source/


SOURCES += main.cpp \
    vue/mainwindow.cpp \
    controleur/controleur.cpp \
    vue/afficherpersonnes.cpp \
    source/modele/photos.cpp \
    source/modele/identification.cpp \
    source/modele/cachephotos.cpp \
    source/modele/photo.cpp \
    source/modele/personnemap.cpp \
    source/modele/signallist.cpp \
    source/adapteur/qstringsignallistadapter.cpp \
    source/adapteur/identificationsignallistadapter.cpp \
    source/adapteur/photosignallistadapter.cpp \
    source/vue/afficheridentifications.cpp \
    source/vue/afficherphotos.cpp \
    source/vue/identificationeditor.cpp

HEADERS  += vue/mainwindow.h \
    controleur/controleur.h \
    vue/afficherpersonnes.h \
    source/modele/photos.h \
    source/modele/identification.h \
    source/modele/cachephotos.h \
    source/modele/photo.h \
    source/modele/personnemap.h \
    source/modele/signallist.h \
    source/modele/personnemap.hxx \
    source/modele/signallist.hxx \
    source/adapteur/signallistadapter.h \
    source/adapteur/signallistadapter.hxx \
    source/adapteur/qstringsignallistadapter.h \
    source/adapteur/identificationsignallistadapter.h \
    source/adapteur/photosignallistadapter.h \
    source/vue/afficheridentifications.h \
    source/vue/afficherphotos.h \
    source/vue/personnemapviewer.h \
    source/vue/personnemapviewer.hxx \
    source/vue/identificationeditor.h

FORMS    += vue/mainwindow.ui \
    vue/afficherpersonnes.ui \
    source/vue/afficheridentifications.ui \
    source/vue/afficherphotos.ui \
    source/vue/personnemapviewer.ui \
    source/vue/identificationeditor.ui

OTHER_FILES += \
    description.txt \
    .gitignore \
    README.md

QMAKE_CXXFLAGS += -std=c++11
