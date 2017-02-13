#include "state_o3.h"

#include "state_mgr.h"
#include <new>

stateO3* stateO3::create()
{
    stateO3 *tmp = new(std::nothrow) stateO3();

    if (tmp && tmp->init()) {
        return tmp;
    }

    delete tmp;
    tmp = nullptr;

    return nullptr;
}

stateO3::stateO3()
{

}

stateO3::~stateO3()
{
    unit();
}

bool stateO3::init()
{
    //initialize

    return true;
}

void stateO3::handle(const void *data, statemgr *mgr)
{
    bool bret = handle(data);

    if (bret) {
        mgr->changeState(stateType());
    }
}

void stateO3::unit()
{

}

inline EStateType stateO3::stateType()
{
    return E_STATE_O3;
}

bool stateO3::handle(const void *data)
{
    //handle data

    return true;
}