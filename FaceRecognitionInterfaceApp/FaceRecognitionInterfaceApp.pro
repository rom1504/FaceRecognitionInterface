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
    source/adapteur/identificationsignallistadapter.cpp \
    source/adapteur/photosignallistadapter.cpp \
    source/vue/afficheridentifications.cpp \
    source/vue/afficherphotos.cpp \
    source/vue/identificationeditor.cpp \
    source/vue/progressdialog.cpp \
    source/vue/personsearch.cpp \
    source/adapteur/checkablestringsignallistadapter.cpp

HEADERS  += vue/mainwindow.h \
    controleur/controleur.h \
    vue/afficherpersonnes.h \
    source/modele/photos.h \
    source/modele/identification.h \
    source/modele/cachephotos.h \
    source/modele/photo.h \
    source/modele/personnemap.h \
    source/modele/personnemap.hxx \
    source/adapteur/identificationsignallistadapter.h \
    source/adapteur/photosignallistadapter.h \
    source/vue/afficheridentifications.h \
    source/vue/afficherphotos.h \
    source/vue/personnemapviewer.h \
    source/vue/personnemapviewer.hxx \
    source/vue/identificationeditor.h \
    source/vue/progressdialog.h \
    source/vue/personsearch.h \
    source/adapteur/checkablestringsignallistadapter.h

FORMS    += vue/mainwindow.ui \
    vue/afficherpersonnes.ui \
    source/vue/afficheridentifications.ui \
    source/vue/afficherphotos.ui \
    source/vue/personnemapviewer.ui \
    source/vue/identificationeditor.ui \
    source/vue/progressdialog.ui \
    source/vue/personsearch.ui

OTHER_FILES += \
    .gitignore \
    README.md

QMAKE_CXXFLAGS += -std=c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SignalList/release/ -lSignalList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SignalList/debug/ -lSignalList
else:unix: LIBS += -L$$OUT_PWD/../SignalList/ -lSignalList

INCLUDEPATH += $$PWD/../SignalList/source
DEPENDPATH += $$PWD/../SignalList/source

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SignalList/release/SignalList.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SignalList/debug/SignalList.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../SignalList/libSignalList.a

RESOURCES += \
    ressources.qrc

TRANSLATIONS += translation/FaceRecognitionInterface_en.ts
