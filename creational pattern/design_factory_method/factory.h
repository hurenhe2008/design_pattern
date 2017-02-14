#ifndef _FACTORY_H_
#define _FACTORY_H_

class product;

class factory
{
public:
    virtual product* getProduct() = 0;
};

#endif //_FACTORY_H_