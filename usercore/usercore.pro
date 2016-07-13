# Set project properties
QT          +=  gui xml sql widgets opengl network
CONFIG      +=  c++11
TEMPLATE    =   lib
VERSION     +=  0.1
DEFINES     +=  API_VERSION=\\\"$$VERSION\\\" #Version of the Public api (equal to lib version^^)
                CORE_BUILD=1 #used for CORE_EXPORT macro switch in appcore.h

SOURCE_VERSION = $$system(git describe --always --tags) #Source Code version
DEFINES     += SOURCE_VERSION=\\\"$$SOURCE_VERSION\\\"

QMAKE_CXXFLAGS +=  -fvisibility=hidden  #to enforce usage of CORE_EXPORT

SOURCES     +=  \
                src/number/number.cpp \
                src/displaywidget/displaywidget.cpp

HEADERS     +=  \
                include/number/number.h \
                include/displaywidget/displaywidget.h

FORMS       += \
                src/displaywidget/displaywidget.ui

RESOURCES   +=  resources.qrc

#DISTFILES   +=  src/res/livedoc_items.html \
#                src/res/livedoc_func.css

INCLUDEPATH +=  \
                $$PWD/../itemframework/core/include \
                $$PWD/../itemframework/core/src \
                $$PWD/include \         #public api
                $$PWD/src \             #private stuff
#                $$PWD/../privatecore \  #privatecore stuff
                $$PWD/ui_header

win32 {
    INCLUDEPATH +=c:/ginac/include
    LIBS+= -Lc:/ginac/lib
}

LIBS+= -lcln

UI_DIR       =  $$PWD/ui_header/
OBJECTS_DIR  =  $$PWD/obj/
MOC_DIR      =  $$PWD/moc/

# Set build destination folder for user core
# Linux:
PROJ_DIR = $$PWD/../
unix:CONFIG(debug, debug|release):          DESTDIR = $$PROJ_DIR/build/linux/debug/
else:unix:CONFIG(release, debug|release):   DESTDIR = $$PROJ_DIR/build/linux/release/
# Windows:
win32:CONFIG(debug, debug|release):         DESTDIR = $$PROJ_DIR/build/win/debug/
else:win32:CONFIG(release, debug|release):  DESTDIR = $$PROJ_DIR/build/win/release/

# NOTE: see privatecore.pro for usage
LIBS += -L$$DESTDIR
#-lprivatecore
