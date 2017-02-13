#ifndef _STATE_O3_H_
#define _STATE_O3_H_

#include "state.h"

class stateO3 : public state
{
public:
    static stateO3* create();

    virtual void handle(const void *data, statemgr *mgr);

    virtual void unit();

    inline virtual EStateType stateType();

private:
    virtual bool init();

    bool handle(const void *data);


public:
    virtual ~stateO3();

private:
    stateO3();
    stateO3(const stateO3 &) = delete;
    stateO3& operator=(const stateO3 &) = delete;
};


#endif //_STATE_O3_H_