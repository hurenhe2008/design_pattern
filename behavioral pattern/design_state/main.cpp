#include <iostream>

#include "state_mgr.h"

int main(int argc, char *argv[])
{
    const char *test = "hello, world!";

    statemgr::instance()->handle((const void *)test);

    return 0;
}