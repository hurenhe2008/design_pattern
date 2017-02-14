#include "factoryo1.h"
#include "productA1.h"
#include "productB1.h"

#include <new>


factoryO1* factoryO1::msp_self = nullptr;

factory* factoryO1::instance()
{
    if (!msp_self) {
        /*lock operation*/
        if (!msp_self) {
            factoryO1 *tmp = new(std::nothrow) factoryO1();

            /*init*/

            msp_self = tmp;
        }
        /*unlock operation*/
    }

    return msp_self;
}

productA* factoryO1::getProductA()
{
    productA1 *tmp = new(std::nothrow) productA1();

    /*init true*/
    return tmp;
}

productB* factoryO1::getProductB()
{
    productB1 *tmp = new(std::nothrow) productB1();

    /*init true*/
    return tmp;
}