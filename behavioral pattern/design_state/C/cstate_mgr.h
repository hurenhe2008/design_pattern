#ifndef _CSTATE_MGR_H_
#define _CSTATE_MGR_H_

#include "cstate.h"

struct state_mgr_s;
typedef struct state_mgr_s state_mgr_t;

void handle(void *data);

void change_state();

#endif //_CSTATE_MGR_H_