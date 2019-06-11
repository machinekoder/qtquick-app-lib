#include "qtquickmodule_plugin.h"
#include "vibrator.h"

#include <qqml.h>

void ComMachinekoderDeclarativeModule::registerTypes(const char *uri)
{
    // @uri com.machinekoder
    qmlRegisterType<Vibrator>(uri, 1, 0, "Vibrator");
}
