#include "singleton.h"
#include <new>

#define THREAD_MUTEX_LOCK         //accomplish mutex
#define THREAD_MUTEX_UNLOCK       


singleton *singleton::msp_self = nullptr;

singleton* singleton::instance()
{
    if (!msp_self) {
        THREAD_MUTEX_LOCK
        if (!msp_self) {   //double check
            singleton *tmp = new(std::nothrow) singleton();

            if (tmp && !tmp->init()) {
                delete tmp;
                tmp = nullptr;
            }

            msp_self = tmp;
        }
        THREAD_MUTEX_UNLOCK
    }

    return msp_self;
}

singleton::singleton()
{

}

singleton::~singleton()
{

}


bool singleton::init()
{
    //initialize

    return true;
}

void singleton::unit()
{
    //re-initialize
}


    