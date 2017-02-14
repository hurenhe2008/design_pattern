#ifndef _CSINGLETON_H_
#define _CSINGLETON_H_


typedef struct singleton_s
{
    /*inner member*/
    char ch[1];  /*occupy addr*/
}singleton_s;

typedef singleton_s singleton_t;



singleton_t* get_instance();



#endif //_CSINGLETON_H_