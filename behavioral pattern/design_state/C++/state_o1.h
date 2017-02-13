#ifndef _STATE_O1_H_
#define _STATE_O1_H_

#include "state.h"

class stateO1 : public state
{
public:
    static stateO1* create();

    virtual void handle(const void *data, statemgr *mgr);

    virtual void unit();

    inline virtual EStateType stateType();

private:
    virtual bool init();

    bool handle(const void *data);


public:
    virtual ~stateO1();

private:
    stateO1();
    stateO1(const stateO1 &) = delete;
    stateO1& operator=(const stateO1 &) = delete;
};


#endif //_STATE_O1_H_