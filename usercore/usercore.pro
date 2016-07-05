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
                src/number/number.cpp

HEADERS     +=  \
                include/number/number.h

# Normal (not SourceObject related) Forms ahead
#FORMS       +=  

RESOURCES   +=  resources.qrc


DISTFILES   +=  src/res/livedoc_items.html \
                src/res/livedoc_func.css

INCLUDEPATH +=  $$PWD/include \         #public api
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

# Set build destination folder for manager libary
# Linux:
unix:CONFIG(debug, debug|release):          DESTDIR = $$PWD/build/linux/debug/
else:unix:CONFIG(release, debug|release):   DESTDIR = $$PWD/build/linux/release/
# Windows:
win32:CONFIG(debug, debug|release):         DESTDIR = $$PWD/build/win/debug/
else:win32:CONFIG(release, debug|release):  DESTDIR = $$PWD/build/win/release/

# NOTE: see privatecore.pro for usage
LIBS += -L$$DESTDIR
#-lprivatecore
