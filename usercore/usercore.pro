include(../itemframework/pri/usercore.pri)

SOURCES     +=  \
                src/usercore.cpp \
                src/number/number_transporter.cpp \
                src/number/number.cpp \
                src/displaywidget/displaywidget.cpp

HEADERS     +=  \
                include/usercore.h \
                include/number/number_transporter.h \
                include/number/number.h \
                include/displaywidget/displaywidget.h

FORMS       += \
                src/displaywidget/displaywidget.ui

RESOURCES   +=  resources.qrc
