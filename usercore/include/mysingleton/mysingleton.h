#include "helper/singleton.h"

class MySingleton : public Singleton<MySingleton>
{
    Q_GADGET

public:
    Q_INVOKABLE MySingleton();
    ~MySingleton();
}
