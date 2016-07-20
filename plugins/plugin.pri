include(../itemframework/pri/plugin.pri)

INCLUDEPATH     += \
                   $$PROJECT_ROOT/usercore/include \

USERCORE_BUILDDIR = $$PROJ_BUILDDIR
USERCORE_LIB      = usercore

LIBS            += -L$$USERCORE_BUILDDIR -l$$USERCORE_LIB
