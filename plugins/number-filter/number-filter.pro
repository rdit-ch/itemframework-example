include(../plugin.pri)

TEMPLATE        =  lib

UI_DIR          =  $$PWD/ui_header/
OBJECTS_DIR     =  $$PWD/obj/
MOC_DIR         =  $$PWD/moc/

SOURCES         += \
                   number_filter_factory.cpp \
                   number_filter_item.cpp \
                   number_filter_widget.cpp \
                   number_filter_config.cpp \

HEADERS         += \
                   number_filter_factory.h \
                   number_filter_item.h \
                   number_filter_widget.h \
                   number_filter_config.h \

FORMS           += \
                   number_filter_widget.ui \

RESOURCES       += number_filter.qrc
OTHER_FILES     += number_filter.json
