#include "state_o1.h"
#include "state_mgr.h"
#include <new>

stateO1* stateO1::create()
{
    stateO1 *tmp = new(std::nothrow) stateO1();

    if (tmp && tmp->init()) {
        return tmp;
    }

    delete tmp;
    tmp = nullptr;

    return nullptr;
}

stateO1::stateO1()
{
   
}

stateO1::~stateO1()
{
    unit();
}

bool stateO1::init()
{
    //initialize

    return true;
}

void stateO1::handle(const void *data, statemgr *mgr)
{
    bool bret = handle(data);

    if (bret) {
        mgr->changeState(stateType());
    }
}

void stateO1::unit()
{

}

inline EStateType stateO1::stateType()
{
    return E_STATE_O1;
}

bool stateO1::handle(const void *data)
{
    //handle data

    return true;
}