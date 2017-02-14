#ifndef _FACTORY_H_
#define _FACTORY_H_

class product;

enum EProductType{
    E_Product_O1 = 0,
    E_Product_O2,
};

class factory 
{
public:
    static factory* instance();

    product* getProduct(EProductType type);

private:
    static factory* msp_self;

private:
    factory() {}
    virtual ~factory() {}

    factory(const factory &) = delete;
    factory& operator =(const factory &) = delete;
};


#endif //_FACTORY_H_