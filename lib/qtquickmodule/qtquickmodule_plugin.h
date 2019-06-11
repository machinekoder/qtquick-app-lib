#ifndef QTQUICKMODULE_PLUGIN_H
#define QTQUICKMODULE_PLUGIN_H

#include <QQmlExtensionPlugin>

class ComMachinekoderDeclarativeModule : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QTQUICKMODULE_PLUGIN_H

