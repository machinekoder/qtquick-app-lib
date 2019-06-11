TEMPLATE = app

TARGET = simple-app

QT += qml quick

CONFIG += link_prl

SOURCES += main.cpp

#release: {
#    CONFIG += qtquickcompiler
#}

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creators code model
QML_IMPORT_PATH =

# deactivate installs for applications
INSTALLS =

linux: !android: {
    target.path = /usr/bin

    desktop.path = /usr/share/applications
    desktop.files = misc/$${TARGET}.desktop

    icon.path = /usr/share/pixmaps
    icon.files = icons/pmc-stone.png

    INSTALLS += target desktop icon
}
