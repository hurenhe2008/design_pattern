#include "factory.h"
#include "product_o1.h"
#include "product_o2.h"

#include <new>

#define THREAD_MUTEX_LOCK    //lock
#define THREAD_MUTEX_UNLOCK  //unlock 


factory* factory::msp_self = nullptr;

factory* factory::instance()
{
    if (!msp_self) {
        THREAD_MUTEX_LOCK

        if (!msp_self) {
            factory *tmp = new(std::nothrow) factory();

            msp_self = tmp;
        }
           
        THREAD_MUTEX_UNLOCK
    }

    return msp_self;
}

product* factory::getProduct(EProductType type)
{
    product *tmp = nullptr;

    switch (type)
    {
    case E_Product_O1:
        tmp = new productO1();
        break;

    case E_Product_O2:
        tmp = new productO2();
        break;
    }

    return tmp;
}