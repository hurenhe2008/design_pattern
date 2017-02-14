#include <stdio.h>

#include "product.h"
#include "factory_o1.h"
#include "factory_o2.h"

int main(void)
{
    product *p = factoryO1::instance()->getProduct();
    p->use();
    p->eat();

    product *q = factoryO2::instance()->getProduct();
    q->use();
    q->eat();

    return 0;
}