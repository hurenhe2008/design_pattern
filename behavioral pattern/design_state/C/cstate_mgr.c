#include "cstate_mgr.h"
#include "cstate_handle.h"
#include <stdio.h>

#ifndef __cplusplus 
    #define NULL (void *)0
    #define nullptr NULL
#endif 


const state_t statelist[] = {
    C_STATE_O1, handle_O1,
    C_STATE_O2, handle_O2,
    C_STATE_O3, handle_O3,
    C_STATE_TOTAL, nullptr,  /*sentinel*/
};

struct state_mgr_s {
    state_type_t   m_cur_state_type;
    state_t       *m_cur_state_handle;
}statemgr = {C_STATE_O1, handle_O1};



static void error_handle()
{
    /*error happen and handle*/
}

static state_t* look_up(state_type_t type)
{
    unsigned i = 0;

    for (i = 0; i < C_STATE_TOTAL; ++i) {
        if (type == statelist[i].type) {
            return &statelist[i];
        }
    }

    error_handle();

    return nullptr;  
}


void handle(const void *data)
{
    state_t *p = statemgr.m_cur_state_handle;

    if (p) {
        p->handle(&statemgr, data);
    }
}

void change_state()
{
    state_type_t next_type = C_STATE_O1;

    switch (statemgr.m_cur_state_type)
    {
    case C_STATE_O1:
        next_type = C_STATE_O2;
        break;

    case C_STATE_O2:
        next_type = C_STATE_O3;
        break;

    case C_STATE_O3:
        next_type = C_STATE_O1;
        break;

    default:
        next_type = C_STATE_TOTAL; /*error*/
    }

    state_t *p = look_up(next_type);
    if (p) {
        statemgr.m_cur_state_type = next_type;
        statemgr.m_cur_state_handle = p;
    }
    else {
        error_handle();
    } 
}