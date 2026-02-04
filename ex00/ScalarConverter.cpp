#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void detect_type(t_type &type,const std::string conv)
{
    if (conv.length() == 1 && !isdigit(conv[0]))
        type = t_char;
    else if (conv[conv.length() -1] == 'f')
        type = t_float;
    else if (conv.find('.') != std::string::npos)
    {
        type = t_double;
    }
    else
        type = t_int;
}

bool input_handling(t_type &type, const std::string conv)
{
    switch(type)
    {
        case t_char:
            break;
        case t_double:
            if (!isdigit(conv[conv.length() - 1]))
                return (1);
        case t_float:
            for (unsigned long i=0; i < (conv.length() - 1);i++)
            {
                
                int dot_count = 0;
                if (conv[i] =='-')
                    i++;
                if ((!isdigit(conv[i]) && conv[i] != '.') || dot_count > 1)
                    return (1);
                if (conv[i] == '.')
                    dot_count++;
            }
            break;
        case t_int:
            for (unsigned long i=0;i < conv.length(); i++)
            {
                if (conv[i] =='-')
                    i++;
                if (!isdigit(conv[i]))
                    return (1);
            }
    }
    return (0);
}


void int_cast(std::string conv)
{
    long num;

    num = atol(conv.c_str());
    if (std::numeric_limits<int>::max() < num  || num < std::numeric_limits<int>::min())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        return ;
    }
    if (num < 31 || num > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "\'" << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " <<   std::fixed << std::setprecision(1)
          << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void char_cast(std::string conv)
{
    if (conv[0] < 31 || conv[0] > 127)
    {
        std::cout << "char: Non displayable" << std::endl;
        conv[0] = 0;
    }
    else
        std::cout << "char: '" << static_cast<char>(conv[0]) << "\'" << std::endl;
    std::cout << "int: " << static_cast<int>(conv[0]) << std::endl;
    std::cout << "float: " <<   std::fixed  << std::setprecision(1)
                << static_cast<float>(conv[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(conv[0]) << std::endl;
}
void float_cast(std::string conv)
{
    double num = strtod(conv.c_str(), NULL);
    if (num != 0 && (std::numeric_limits<float>::min() > num  || std::numeric_limits<float>::max() < num))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        return ;
    }
    if (num < 31 || num > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "\'" << std::endl;
    if (std::numeric_limits<int>::min() > num  || std::numeric_limits<int>::max() < num)
        std::cout << "int: " << "impossible" << std::endl; 
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
     std::cout << "float: " <<   std::fixed << std::setprecision(1)
                << num << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void double_cast(std::string conv)
{
    double value = strtod(conv.c_str(), NULL);
    if (value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 31 )
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "\'" << std::endl;
    if (std::numeric_limits<int>::min() > value  || std::numeric_limits<int>::max() < value)
        std::cout << "int: " << "impossible" << std::endl; 
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (value != 0 && (std::numeric_limits<float>::min() > value  || std::numeric_limits<float>::max() < value))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " <<   std::fixed
                << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

int special_value(const std::string conv)
{
    double value = std::strtod(conv.c_str(), NULL);

    if (std::isinf(value))
    {  
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " <<   std::fixed << std::setprecision(1)
                    << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " <<  value << std::endl;
        return 1;
    }
    else if (std::isnan(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " <<   std::fixed << std::setprecision(1)
                    << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " <<  value << std::endl;
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(const std::string conv)
{
    t_type type;

    if (special_value(conv))
        return ;
    detect_type(type, conv);
    if(input_handling(type, conv))
    {
        std::cout << "invalid input !!" << std::endl;
        return;
    }
    switch (type)
    {
        case t_int:
            int_cast(conv);
            break;
        case t_char:
            char_cast(conv);
            break;
        case t_float:
            float_cast(conv);
            break;
        case t_double:
            double_cast(conv);
            break;
    }
}