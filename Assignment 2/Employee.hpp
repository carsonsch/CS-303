#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee
{
    public:
        virtual float calc_weekly_pay() const = 0;
        virtual float calc_weekly_healthcare_contributions() const = 0;
        virtual float calc_weekly_vacation_hours_earned() const = 0;
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_address() const;

    protected:
        std::string first_name;
        std::string last_name;
        std::string address;
};

#endif