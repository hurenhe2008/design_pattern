#ifndef _FACTORY_O1_H_
#define _FACTORY_O1_H_

#include "factory.h"

class factoryO1 : public factory
{
public:
    static factory* instance();

    virtual product* getProduct();

private:
    static factoryO1 *msp_self;
};

// facotryO1 manage productO1

// if need, can manage productO1 series with list or array.

#endif //_FACTORY_O1_H_