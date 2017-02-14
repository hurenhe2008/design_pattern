#ifndef _CSTATE_H_
#define _CSTATE_H_

#ifdef __cplusplus
extern "C"
{
#endif 

enum state_type_e {
    C_STATE_O1 = 0,
    C_STATE_O2,
    C_STATE_O3,
    C_STATE_TOTAL,
};
typedef enum state_type_e  state_type_t;


struct state_mgr_t;
typedef void (__cdecl *fHandle)(state_mgr_t *mgr, const void *data);

struct state_s {
    state_type_t  type;
    fHandle       handle;
};
typedef struct state_s state_t;


#ifdef __cplusplus
}
#endif


#endif //_CSTATE_H_