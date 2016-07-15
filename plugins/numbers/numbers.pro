include(../plugin.pri)

SOURCES         += \
                   numbers_factory.cpp \
                   number-emitter/number_emitter_item.cpp \
                   number-viewer/number_viewer_item.cpp \
                   number-viewer/number_viewer_widget.cpp \

HEADERS         += \
                   numbers_factory.h \
                   number-emitter/number_emitter_item.h \
                   number-viewer/number_viewer_item.h \
                   number-viewer/number_viewer_widget.h \

FORMS           += \
                   number-viewer/number_viewer_widget.ui \

RESOURCES       += numbers.qrc
OTHER_FILES     += numbers.json
