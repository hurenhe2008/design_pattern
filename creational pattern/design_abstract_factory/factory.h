#ifndef _FACTORY_H_
#define _FACTORY_H_

class productA;
class productB;

class factory
{
public:
    virtual productA* getProductA() = 0;

    virtual productB* getProductB() = 0;
};


#endif //_FACTORY_H_