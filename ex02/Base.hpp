#ifndef BASE_HPP
#define BASE_HPP
#include <cstdlib>
#include <iostream>
#include <cstring>
class Base {
    public:
        static Base* generate(void);
        static void identify(Base* p);
        static void identify(Base& p);
        virtual ~Base();
};

#endif