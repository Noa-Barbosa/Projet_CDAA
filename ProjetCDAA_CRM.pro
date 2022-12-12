QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contactentity.cpp \
    contactform.cpp \
    contactinteractionentity.cpp \
    deletecontactwarning.cpp \
    deleteinteractionwarning.cpp \
    gestionnaireBDD.cpp \
    gestionnairecontact.cpp \
    gestionnaireinteraction.cpp \
    gestionnairetodo.cpp \
    interactionentity.cpp \
    interactiontodoentity.cpp \
    listcontact.cpp \
    listinteraction.cpp \
    main.cpp \
    mainwindow.cpp \
    todoentity.cpp

HEADERS += \
    contactentity.h \
    contactform.h \
    contactinteractionentity.h \
    date.h \
    deletecontactwarning.h \
    deleteinteractionwarning.h \
    gestionnaireBDD.h \
    gestionnairecontact.h \
    gestionnaireinteraction.h \
    gestionnairetodo.h \
    interactionentity.h \
    interactiontodoentity.h \
    listcontact.h \
    listinteraction.h \
    mainwindow.h \
    todoentity.h

FORMS += \
    contactform.ui \
    deletecontactwarning.ui \
    deleteinteractionwarning.ui \
    listcontact.ui \
    listinteraction.ui \
    mainwindow.ui

DEFINES += PROJECT_PATH="\"$$PWD\""

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
