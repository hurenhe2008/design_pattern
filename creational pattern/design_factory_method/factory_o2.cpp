#include "factory_o2.h"
#include "product_o2.h"

#include <new>

factoryO2 *factoryO2::msp_self = nullptr;

factory* factoryO2::instance()
{
    if (!msp_self) {
        /*lock*/

        factoryO2 *tmp = new(std::nothrow) factoryO2();

        msp_self = tmp;

        /*unlock*/
    }

    return msp_self;
}

product* factoryO2::getProduct()
{
    productO2 *tmp = new(std::nothrow) productO2();

    /*init true*/

    return tmp;
}