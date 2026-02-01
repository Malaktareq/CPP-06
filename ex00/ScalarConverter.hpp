#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
class ScalarConverter
{
    public:
        void static convert(std::string conv);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};

typedef enum e_type{
    t_char,
    t_int,
    t_float,
    t_double,
}t_type;
#endif