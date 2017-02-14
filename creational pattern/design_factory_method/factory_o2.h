#ifndef _FACTORY_O2_H_
#define _FACTORY_O2_H_

#include "factory.h"

class factoryO2 : public factory
{
public:
    static factory* instance();

    virtual product* getProduct();

private:
    static factoryO2 *msp_self;
};

// facotryO1 manage productO1

// if need, can manage productO2 series with list or array.

#endif //_FACTORY_O2_H_