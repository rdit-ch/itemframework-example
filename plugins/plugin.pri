include(../base.pri)

QT              += core gui xml widgets
CONFIG          += plugin c++11
    
INCLUDEPATH     += \
                   $$PROJECT_ROOT/itemframework/core/include \
                   $$PROJECT_ROOT/usercore/include \
                   $$PWD/ui_header

QMAKE_LFLAGS    += -Wl,--unresolved-symbols=report-all

# Platform dependent stuff
BUILDDIR = $$PROJECT_ROOT/build
unix: {
CONFIG(release, debug|release):   PROJ_BUILDDIR  = $$BUILDDIR/linux/release
CONFIG(debug, debug|release):     PROJ_BUILDDIR  = $$BUILDDIR/linux/debug

CORE_LIB         = core
}
win32: {
CONFIG(release, debug|release):   PROJ_BUILDDIR  = $$BUILDDIR/win/release
CONFIG(debug, debug|release):     PROJ_BUILDDIR  = $$BUILDDIR/win/debug

CORE_LIB         = core0
}

USERCORE_BUILDDIR = $$PROJ_BUILDDIR
USERCORE_LIB      = usercore

DESTDIR          = $$PROJ_BUILDDIR/plugins
LIBS            += -L$$PROJ_BUILDDIR -l$$CORE_LIB -L$$USERCORE_BUILDDIR -l$$USERCORE_LIB
