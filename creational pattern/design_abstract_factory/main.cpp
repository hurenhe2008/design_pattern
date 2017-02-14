#include <iostream>

#include "factoryO1.h"
#include "factoryO2.h"
#include "productA.h"
#include "productB.h"

int main(int argc, char *argv[])
{
    productA *p = factoryO1::instance()->getProductA();
    p->use();
    productB *q = factoryO1::instance()->getProductB();
    q->eat();

    productA *m = factoryO2::instance()->getProductA();
    m->use();
    productB *n = factoryO2::instance()->getProductB();
    n->eat();

    return 0;
}