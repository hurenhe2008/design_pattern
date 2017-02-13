#ifndef _STATE_MGR_H_
#define _STATE_MGR_H_

#include "state.h"
#include <map>

class statemgr
{
public:
    static statemgr* instance();
    
    void handle(const void *data);

    void changeState(EStateType curtype);

    void unit();

private:
    bool init();

private:
    static statemgr *msp_self;

    state *mp_cur_state_handle;

    std::map<EStateType, state *> m_state_map;
 
private:
    statemgr();
    virtual ~statemgr();
    statemgr(const statemgr &) = delete;
    statemgr& operator=(const statemgr &) = delete;
};





#endif //_STATE_MGR_H_