#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
typedef unsigned long uintptr_t;

typedef struct Data
{
    int id;
    const char  *name;   
}Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
};

#endif