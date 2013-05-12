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
    modele/photo.cpp \
    modele/modeleafficherpersonne.cpp \
    vue/afficherpersonnes.cpp \
    modele/modelevaliderphotos.cpp \
    vue/validerphotos.cpp \
    vue/afficherphotos.cpp \
    modele/modeleafficherphotos.cpp \
    modele/photosAValider.cpp \
    modele/photos.cpp

HEADERS  += vue/mainwindow.h \
    controleur/controleur.h \
    modele/photo.h \
    modele/modeleafficherpersonne.h \
    vue/afficherpersonnes.h \
    modele/modelevaliderphotos.h \
    vue/validerphotos.h \
    vue/afficherphotos.h \
    modele/modeleafficherphotos.h \
    modele/photosAValider.h \
    modele/photos.h

FORMS    += vue/mainwindow.ui \
    vue/afficherpersonnes.ui \
    vue/validerphotos.ui \
    vue/afficherphotos.ui

OTHER_FILES += \
    description.txt \
    .gitignore \
    README.md

QMAKE_CXXFLAGS += -std=c++11
