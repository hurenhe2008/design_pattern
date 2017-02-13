#include "state_mgr.h"
#include "state_o1.h"
#include "state_o2.h"
#include "state_o3.h"

#include <new>

//accomplish thread mutex for safe
#define THREAD_MUTEX_LOCK      
#define THREAD_MUTEX_UNLOCK    

statemgr *statemgr::msp_self = nullptr;

statemgr* statemgr::instance()
{
    if (!msp_self) {
        THREAD_MUTEX_LOCK
        if (!msp_self) {
            statemgr *tmp = new(std::nothrow) statemgr();

            if (!tmp || !tmp->init()) {
                delete tmp;
                tmp = nullptr;
            }
            
            msp_self = tmp;
        }
        THREAD_MUTEX_UNLOCK
    }

    return msp_self;
}

statemgr::statemgr()
: mp_cur_state_handle(nullptr)
{

}

statemgr::~statemgr()
{
    unit();
}

void statemgr::handle(const void *data)
{
    if (mp_cur_state_handle) {
        mp_cur_state_handle->handle(data, this);
    }
    else {
        //error happen
    }    
}

void statemgr::changeState(EStateType curtype)
{
    EStateType nextstate;

    switch (curtype)
    {
    case E_STATE_O1:
        nextstate = E_STATE_O2;
        break;

    case E_STATE_O2:
        nextstate = E_STATE_O3;
        break;

    case E_STATE_O3:
        nextstate = E_STATE_O1;  //cycle
        break;

    default:
        nextstate = E_STATE_O1;
    }

    if (m_state_map.find(nextstate) == m_state_map.end()) {
        mp_cur_state_handle = nullptr;
    }
    else {
        mp_cur_state_handle = m_state_map[nextstate];
    } 
}

bool statemgr::init()
{
    m_state_map.clear();

    bool binit = true;
    state *tmp = nullptr;

    do {
        tmp = stateO1::create();
        if (!tmp) {
            binit = false;
            break;
        }
        m_state_map[E_STATE_O1] = tmp;

        tmp = stateO2::create();
        if (!tmp) {
            binit = false;
            break;
        }
        m_state_map[E_STATE_O2] = tmp;

        tmp = stateO3::create();
        if (!tmp) {
            binit = false;
            break;
        }
        m_state_map[E_STATE_O3] = tmp;
    } while (0);

    if (!binit) {
        unit();
    }

    mp_cur_state_handle = m_state_map[E_STATE_O1];
    return binit;
}

void statemgr::unit()
{
    state *tmp = nullptr;

    for (auto it: m_state_map) {
        tmp = it.second;
        if (tmp) {
            delete tmp;
            tmp = nullptr;
        }
        it.second = nullptr;
    }

    m_state_map.clear();
}