#ifndef _FACTORY_O1_H_
#define _FACTORY_O1_H_

#include "factory.h"

class factoryO1 : public factory
{
public:
    static factory* instance();

    virtual productA* getProductA();

    virtual productB* getProductB();

private:
    static factoryO1 *msp_self;
};

#endif //_FACTORY_O1_H_