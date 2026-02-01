#ifndef BASE_HPP
#define BASE_HPP
#include <cstdlib>
typedef enum e_type{
    A,
    B,
    C
}t_type;

class Base {
    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);
};

#endif