#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <type_traits>


void print_ip(const std::string& ip_address, std::ostream& out)
{
    out << ip_address << "\n";
}

template<typename T>
typename std::enable_if <std::is_integral_v<T>, void>::type
print_ip(const T& ip_address, std::ostream& out)
{    
    int number_bytes = sizeof(ip_address);

    while (number_bytes > 1)
    {
        out << ((ip_address >> 8 * (number_bytes - 1)) & 0xFF) << ".";
        --number_bytes;
    }
    out << (ip_address & 0xFF) << "\n";
}

template<typename T>
typename std::enable_if <
    std::is_same_v<T, std::vector<typename T::value_type>> ||
    std::is_same_v<T, std::list<typename T::value_type>>,
    void>::type
print_ip(const T& ip_address, std::ostream & out)
{
    for (auto value = ip_address.cbegin(); value != ip_address.cend(); ++value)
    {
        if (value != ip_address.cbegin())
        {
            out << ".";
        }
        out << *value;
    }
    out << "\n";
}


