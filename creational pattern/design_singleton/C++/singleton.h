#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class singleton
{
public:
    static singleton* instance();
    
private:
    bool init();

    void unit();

private:
    singleton();
    virtual ~singleton();
    
    //not allowed
    singleton(const singleton &) = delete;
    singleton& operator =(const singleton &) = delete;

    static singleton *msp_self;
};



#endif //_SINGLETON_H_