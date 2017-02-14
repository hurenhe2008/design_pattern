#ifndef _SINGLETON_TMP_H_
#define _SINGLETON_TMP_H_

#include <mutex>
#include <new>

template<typename T>
class singleton
{
public:
    static T* instance();

private:
    singleton();
    virtual ~singleton();

    singleton(const singleton &) = delete;
    singleton& operator =(const singleton &) = delete;

    static T* msp_self;
    static std::mutex  ms_mutex;
};


template<typename T>
T* singleton<T>::msp_self = nullptr;


template<typename T>
T* singleton<T>::instance()
{
    if (!msp_self) {
        ms_mutex.lock();

        if (!msp_self) {
            T *tmp = new(std::nothrow) T;

            if (tmp && !tmp->init()) {  //if T has init()
                delete tmp;
                tmp = nullptr;
            }

            msp_self = tmp;
        } 

        ms_mutex.unlock();
    }

    return msp_self;
}


template<typename T>
singleton()
{

}

template<typename T>
~singleton()
{

}


#endif //_SINGLETON_TMP_H_