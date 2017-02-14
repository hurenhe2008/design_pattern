#include "factory_o1.h"
#include "product_o1.h"

#include <new>

factoryO1* factoryO1::msp_self = nullptr;

factory* factoryO1::instance()
{
    if (!msp_self) {
        /*lock*/

        factoryO1 *tmp = new(std::nothrow) factoryO1();

        msp_self = tmp;

        /*unlock*/
    }

    return msp_self;
}

product* factoryO1::getProduct()
{
    productO1 *tmp = new(std::nothrow) productO1();

    /*init true*/

    return tmp;
}