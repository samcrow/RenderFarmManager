#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T18:19:37
#
#-------------------------------------------------

QT       += core gui network

TARGET = RenderFarmManager
TEMPLATE = app


SOURCES += main.cpp\
		renderfarmmanagerwindow.cpp \
	data/models/hostdatamodel.cpp \
	data/host.cpp \
    net/simplesshconnection.cpp \
    net/sshconnection.cpp

HEADERS  += renderfarmmanagerwindow.hpp \
	data/models/hostdatamodel.hpp \
	data/host.hpp \
    net/simplesshconnection.hpp \
    net/sshconnection.hpp

FORMS    += renderfarmmanagerwindow.ui

RESOURCES += \
	SSHSearch.qrc

macx: LIBS += -L /opt/local/lib -lssh2

INCLUDEPATH += /opt/local/include

