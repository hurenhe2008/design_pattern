#include "factoryo2.h"
#include "productA2.h"
#include "productB2.h"

#include <new>

factoryO2* factoryO2::msp_self = nullptr;

factory* factoryO2::instance()
{
    if (!msp_self) {
        /*lock operation*/
        if (!msp_self) {
            factoryO2 *tmp = new(std::nothrow) factoryO2();

            /*init*/

            msp_self = tmp;
        }
        /*unlock operation*/
    }

    return msp_self;
}

productA* factoryO2::getProductA()
{
    productA2 *tmp = new(std::nothrow) productA2();

    /*init true*/
    return tmp;
}

productB* factoryO2::getProductB()
{
    productB2 *tmp = new(std::nothrow) productB2();

    /*init true*/
    return tmp;
}