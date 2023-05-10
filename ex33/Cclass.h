#ifndef _CCLASS_H
#define _CCLASS_H

#include <iostream>
#include "Aclass.h"

class C : public A {
    private:
        int e;

    public:
        // constructors
        C(int val = 0) : A(), e(val) {}

        void sete(int val) { e = val; }
        virtual std::string toString() const override;
        virtual int fun() const override { return e * geta() * d; }
};

std::string C::toString() const {
    std::stringstream ss;
    ss << "[Cclass: a = " << geta() << ", d = " << d << ", e = " << e << ", size = " << sizeof(*this) << "]" << std::endl;
    return ss.str();
}

#endif