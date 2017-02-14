#include "csingleton.h"

#ifndef __cplusplus
#define NULL (void *)0
#define nullptr NULL
#endif

#if defined(_WIN32) || defined(_WIN64) 
#include <windows.h>
CRITICAL_SECTION s_mutex;
#define THREAD_MUTEX_INIT(x)    InitializeCriticalSection(&x)
#define THREAD_MUTEX_LOCK(x)    EnterCriticalSection(&x)
#define THREAD_MUTEX_TRYLOCK(x) TryEnterCriticalSection(&x)
#define THREAD_MUTEX_UNLOCK(x)  LeaveCriticalSection(&x)
#define THREAD_MUTEX_UNIT(x)    DeleteCriticalSection(&x)
#else
#include <pthread.h>
pthread_mutex_t s_mutex;// = PTHREAD_MUTEX_INITIALIZER;
#define THREAD_MUTEX_INIT(x)    pthread_mutex_init(&x)
#define THREAD_MUTEX_LOCK(x)    pthread_mutex_lock(&x)
#define THREAD_MUTEX_TRYLOCK(x) pthread_mutex_trylock(&x)
#define THREAD_MUTEX_UNLOCK(x)  pthread_mutex_unlock(&x)
#define THREAD_MUTEX_UNIT(x)    pthread_mutex_destroy(&x)
#endif

static singleton_t *sp_singleton = nullptr;
static int sb_mutex_init = 0;
static void init_mutex();

singleton_t* get_instance()
{
    if (!sp_singleton) {

        init_mutex();

        THREAD_MUTEX_LOCK(s_mutex);

        if (!sp_singleton) {
            singleton_t *tmp = (singleton_t *)malloc(sizeof(singleton_t));
            
            /*init singleton_t*/

            sp_singleton = tmp;
        }

        THREAD_MUTEX_UNLOCK(s_mutex);
    }

    return sp_singleton; 
}


void init_mutex()
{
    if (!sb_mutex_init) {
        THREAD_MUTEX_INIT(s_mutex);
        sb_mutex_init = !sb_mutex_init;
    }
}