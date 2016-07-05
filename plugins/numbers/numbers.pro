QT              += core gui xml widgets
TEMPLATE        =  lib
CONFIG          += plugin c++11
SOURCES         += \
                   numbers_factory.cpp \
#                   number/number.cpp \
                   number-emitter/number_emitter_item.cpp \
                   number-viewer/number_viewer_item.cpp \
                   number-viewer/number_viewer_widget.cpp \
                   number-filter/number_filter_item.cpp \
                   number-filter/number_filter_widget.cpp \
                   number-filter/number_filter_config.cpp \

HEADERS         += \
                   numbers_factory.h \
#                   number/number.h \
                   number-emitter/number_emitter_item.h \
                   number-viewer/number_viewer_item.h \
                   number-viewer/number_viewer_widget.h \
                   number-filter/number_filter_item.h \
                   number-filter/number_filter_widget.h \
                   number-filter/number_filter_config.h \

FORMS           += \
                   number-viewer/number_viewer_widget.ui \
                   number-filter/number_filter_widget.ui \

RESOURCES       += numbers.qrc
    
INCLUDEPATH     +=  $$PWD/../../itemframework/core/include \  #public api
#                    $$PWD/../../privatecore \
                    $$PWD/../../usercore/include \
                    $$PWD/ui_header

UI_DIR          =  $$PWD/ui_header/
OBJECTS_DIR     =  $$PWD/obj/
MOC_DIR         =  $$PWD/moc/

OTHER_FILES     += numbers.json

QMAKE_LFLAGS    += -Wl,--unresolved-symbols=report-all


########################
# TODO: move to .pri
########################

# Platform dependent stuff
unix: {
CONFIG(release, debug|release):   TRAVIZ_BUILDDIR  = $$PWD/../../itemframework/build/linux/release
CONFIG(debug, debug|release):     TRAVIZ_BUILDDIR  = $$PWD/../../itemframework/build/linux/debug

CORE_LIB         = core
}
win32: {
CONFIG(release, debug|release):   TRAVIZ_BUILDDIR  = $$PWD/../../itemframework/build/win/release
CONFIG(debug, debug|release):     TRAVIZ_BUILDDIR  = $$PWD/../../itemframework/build/win/debug

CORE_LIB         = core0
}

USERCORE_BUILDDIR = $$PWD/../../usercore/build/linux/release
USERCORE_LIB      = usercore

DESTDIR          = $$TRAVIZ_BUILDDIR/plugins
#LIBS            += -L$$TRAVIZ_BUILDDIR -lprivatecore -l$$CORE_LIB -L$$USERCORE_BUILDDIR -l$$USERCORE_LIB
LIBS            += -L$$TRAVIZ_BUILDDIR -l$$CORE_LIB
#PRE_TARGETDEPS  += $$TRAVIZ_BUILDDIR/libprivatecore.a
