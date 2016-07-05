#include "mysingleton/mysingleton.h"
#include "helper/startup_helper.h"

MySingleton::MySingleton()
{
    qDebug() << "MySingleton::MySingleton()";
}

STARTUP_ADD_SINGLETON(MySingleton)
