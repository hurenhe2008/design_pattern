#ifndef _FACTORY_O2_H_
#define _FACTORY_O2_H_

#include "factory.h"

class factoryO2 : public factory
{
public:
    static factory* instance();

    virtual productA* getProductA();

    virtual productB* getProductB();

private:
    static factoryO2 *msp_self;
};

#endif //_FACTORY_O2_H_