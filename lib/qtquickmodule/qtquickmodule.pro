TEMPLATE = lib
uri = com.machinekoder
QT += qml quick
android: QT += androidextras
CONFIG += qt plugin c++11 create_prl
CONFIG -= android_install
TARGET = $$qtLibraryTarget($$lower($$replace(uri, \\., ))plugin)
QMAKE_MOC_OPTIONS += -Muri=$$uri

uri = com.machinekoder

#include(./pmcs/pmcs.pri)

# Input
SOURCES += \
    qtquickmodule_plugin.cpp \
    vibrator.cpp

HEADERS += \
    qtquickmodule_plugin.h \
    vibrator.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

TARGETPATH = $$replace(uri, \\., /)
qmldir.files = qmldir
installPath = $$[QT_INSTALL_QML]/$$TARGETPATH
qmldir.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir
