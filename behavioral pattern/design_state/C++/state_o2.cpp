#include "state_o2.h"
#include "state_mgr.h"
#include <new>

stateO2* stateO2::create()
{
    stateO2 *tmp = new(std::nothrow) stateO2();

    if (tmp && tmp->init()) {
        return tmp;
    }

    delete tmp;
    tmp = nullptr;

    return nullptr;
}

stateO2::stateO2()
{

}

stateO2::~stateO2()
{
    unit();
}

bool stateO2::init()
{
    //initialize

    return true;
}

void stateO2::handle(const void *data, statemgr *mgr)
{
    bool bret = handle(data);

    if (bret) {
        mgr->changeState(stateType());
    }
}

void stateO2::unit()
{

}

inline EStateType stateO2::stateType()
{
    return E_STATE_O2;
}

bool stateO2::handle(const void *data)
{
    //handle data

    return true;
}