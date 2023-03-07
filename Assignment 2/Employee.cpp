#include <string>

#include "Employee.hpp"

std::string Employee::get_first_name() const
{
    return first_name;
};
std::string Employee::get_last_name() const
{
    return last_name;
};
std::string Employee::get_address() const
{
    return address;
};