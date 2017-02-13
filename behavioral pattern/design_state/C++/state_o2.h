#ifndef _STATE_O2_H_
#define _STATE_O2_H_

#include "state.h"

class stateO2 : public state
{
public:
    static stateO2* create();

    virtual void handle(const void *data, statemgr *mgr);

    virtual void unit();

    inline virtual EStateType stateType();

private:
    virtual bool init();

    bool handle(const void *data);


public:
    virtual ~stateO2();

private:
    stateO2();
    stateO2(const stateO2 &) = delete;
    stateO2& operator=(const stateO2 &) = delete;
};


#endif //_STATE_O2_H_