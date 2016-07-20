# Set project properties
QT          +=  gui xml sql widgets opengl network
CONFIG      +=  c++11
TEMPLATE    =   lib
VERSION     +=  0.1
DEFINES     +=  USERCORE_BUILD=1 #used for USERCORE_EXPORT macro switch in usercore.h

QMAKE_CXXFLAGS +=  -fvisibility=hidden  #to enforce usage of USERCORE_EXPORT

SOURCES     +=  \
                src/helper/linker_helper.cpp \
                src/number/number_transporter.cpp \
                src/number/number.cpp \
                src/displaywidget/displaywidget.cpp

HEADERS     +=  \
                include/helper/linker_helper.h \
                include/number/number_transporter.h \
                include/number/number.h \
                include/displaywidget/displaywidget.h

FORMS       += \
                src/displaywidget/displaywidget.ui

RESOURCES   +=  resources.qrc

INCLUDEPATH +=  \
                $$PWD/../itemframework/core/include \
                $$PWD/../itemframework/core/src \
                $$PWD/include \
                $$PWD/src \
                $$PWD/ui_header

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

LIBS += -L$$DESTDIR
