#include <stdio.h>
#include "factory.h"
#include "product.h"

int main(void)
{
    product *p = factory::instance()->getProduct(E_Product_O1);
    p->use();
    p->eat();

    product *q = factory::instance()->getProduct(E_Product_O2);
    q->use();
    q->eat();

    delete q;
    delete p;

    return 0;
}