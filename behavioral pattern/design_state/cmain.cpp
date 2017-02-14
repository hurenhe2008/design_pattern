#include <stdio.h>
#include "cstate_mgr.h"

int main(void)
{
    const char *test = "hello, world!";

    handle((const void *)test);

    return 0;
}