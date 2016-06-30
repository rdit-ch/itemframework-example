# Set project properties
    QT          +=  core xml widgets
    CONFIG      +=  c++11
    TARGET      =   example
    TEMPLATE    =   app
    SOURCES     +=  main.cpp

    INCLUDEPATH += $$PWD/../core/include #public api

# Set LIBS folder
# Linux:
    unix:CONFIG(release, debug|release):    LIBS += -L$$PWD/../build/linux/release/ -lcore
    else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/linux/debug/ -lcore
# Windows:
    win32:CONFIG(release, debug|release):   LIBS += -L$$PWD/../build/win/release/ -lcore0
    else:win32:CONFIG(debug, debug|release):LIBS += -L$$PWD/../build/win/debug/ -lcore0

# Set DESTDIR folder
# Linux:
    unix:CONFIG(release, debug|release):    DESTDIR = $$PWD/../build/linux/release/
    else:unix:CONFIG(debug, debug|release): DESTDIR = $$PWD/../build/linux/debug/

# Windows:
    win32:CONFIG(release, debug|release):   DESTDIR = $$PWD/../build/win/release/
    else:win32:CONFIG(debug, debug|release):DESTDIR = $$PWD/../build/win/debug/

# Set OBJECTS_DIR folder
    OBJECTS_DIR = $$PWD/obj/

# Set MOC_DIR folder
    MOC_DIR = $$PWD/moc/

# Set Libary path to executable programm file ($ORIGIN)
# Link against libsegfault
    unix:!mac{
      QMAKE_LFLAGS  += -Wl,--rpath=\\\$\$ORIGIN
      QMAKE_LFLAGS  += -lSegFault
    }

OTHER_FILES +=
