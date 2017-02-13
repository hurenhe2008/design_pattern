#ifndef _STATE_H_
#define _STATE_H_


enum EStateType {
    E_STATE_O1,
    E_STATE_O2,
    E_STATE_O3,
};

class statemgr;
class state 
{
public:
    virtual bool init() = 0;

    virtual void handle(const void *data, statemgr *mgr) = 0;

    virtual void unit() = 0;

    inline virtual EStateType stateType() = 0;
};


#endif //_STATE_H_